# examples
#
# 1 rom = 64 programs, each 128 instr * 2 bytes
#
# - instruction address is for the *following* operation
# - it seems that the data are stored in the eeprom as little endian, ie. `3f8b` is stored as `8b 3f`
# - input is 13 bits, but arithmetic is done in 16 bits
# - output is 13 bits with saturation
# 
# how the emulator should work:
# while True:
#   offset = instr[pc].offset
#   op = instr[pc].off
#   perform(op)
#   addr += offset
# 
#
# PC   : OP OFFSET MEMN    DD SRC -> DST ; ACC Ops
# 0x23 : 0  0x0075 SUMHALF RD 0x3A2A -> ACC ; Acc = Acc + src/2 + sgn
# 0x24 : 3  0x3F8B STRNEG  WR ~ACC -> 0x3A9F ; dst = ~Acc, Acc = ~Acc/2 + sgn
# 0x25 : 0  0x0000 SUMHALF RD 0x3A2A -> ACC ; Acc = Acc + src/2 + sgn
# 0x26 : 0  0x3FB2 SUMHALF RD 0x3A2A -> ACC ; Acc = Acc + src/2 + sgn
#
# PC : OP OFFSET MEMN DD SRC -> DST ; ACC Ops
# 
# 0x42 : 2 0x216F STRPOS WR ACC -> 0x0001 ; dst = Acc, Acc = Acc + Acc/2 + sgn
# 0x43 : 1 0x1E91 LDHALF RD 0x2170 -> ACC ; Acc = src/2 + sgn
# 0x44 : 0 0x2170 SUMHALF RD 0x0001 -> ACC ; Acc = Acc + src/2 + sgn
# 0x45 : 2 0x0000 STRPOS WR ACC -> 0x2171 ; dst = Acc, Acc = Acc + Acc/2 + sgn
#
# PC : OP OFFSET MEMN DD SRC -> DST

# 0x0E : 1 0x1E8F LDHALF RD 0x2173 -> ACC ; Acc = src/2 + sgn in [* 0.5], the 0x2173 was where the buffer was in this code snippet]
# 0x0F : 2 0x0000 STRPOS WR ACC -> 0x0002 ; dst = Acc, Acc = Acc + Acc/2 + sgn [* 0.75]
# 0x10 : 2 0x0000 STRPOS WR ACC -> 0x0002 ; dst = Acc, Acc = Acc + Acc/2 + sgn [* 1.125]
# 0x11 : 2 0x0000 STRPOS WR ACC -> 0x0002 ; dst = Acc, Acc = Acc + Acc/2 + sgn [* 1.6875]
# 0x12 : 2 0x3F5B STRPOS WR ACC -> 0x0002 ; dst = Acc, Acc = Acc + Acc/2 + sgn [* 2.53125], the next offset 0x3F5B is pipelined 1-instruction
# 
# PC : OP OFFSET MEMN DD SRC -> DST ; ACC Ops
# 
# 0x2C : 1 0x08EF LDHALF RD 0x3712 -> ACC ; Acc = src/2 + sgn in * 0.5
# 0x2D : 3 0x0000 STRNEG WR ~ACC -> 0x0001 ; dst = ~Acc, Acc = ~Acc/2 + sgn * -0.25
# 0x2E : 3 0x3711 STRNEG WR ~ACC -> 0x0001 ; dst = ~Acc, Acc = ~Acc/2 + sgn * 0.125
# 0x2F : 0 0x3C1B SUMHALF RD 0x3712 -> ACC ; Acc = Acc + src/2 + sgn * 0.625
# 
#
# DSP Operations
# 
# OP /Clr /Rd_RO /Rd_R1 /DRAM_W Function
# 
# 00 1 1 1 1 Acc = Acc + DRAM[addr]/2 + sgn
# 01 0 1 1 1 Acc = DRAM[addr]/2 + sgn
# 10 1 0 1 0 DRAM[addr] = Acc, Acc = Acc + Acc/2 + sgn
# 11 0 1 0 0 DRAM[addr] = ~Acc, Acc = ~Acc/2 + sgn
# 
# - Four total instructions:
#   - 00 - Sumhif
#   - 01 - Ldhif
#   - 10 - Strpos
#   - 11 - Strneg
# 
# - Accumulator is either summed with or loaded with (Data/2 + sgn)
# - Writes to DRAM are either Accumulator or binary inverse of Accumulator
# 

import sys
import argparse
import struct
from enum import Enum
from dataclasses import dataclass
from typing import Optional
from fractions import Fraction

class DSPInstruction(Enum):
    OUTPUT_LEFT = "output_left"
    OUTPUT_RIGHT = "output_right"
    INPUT = "input"
    SUMHLF = "sumhlf"
    LDHLF = "ldhlf"
    STRPOS = "strpos"
    STRNEG = "strneg"
    STORE = "store"
    STOREN = "storen"
    ADDHLF = "addhlf"
    NEGHLF = "neghlf"

@dataclass(frozen=True)
class Instruction:
    opcode: DSPInstruction
    pc: int
    addr: Optional[int] = None
    # If present, it means that at this instruction there's a patch table that changes the
    # instruction address depending on the LFO value fractional bits.
    #
    # Fractional bits are the 4 bits after fractional point: `(lfo_value >> 4) & 15`.
    #
    # The structure is (lfo_number, (addr_for_0, addr_for_1, ...))
    patched: Optional[tuple[int, tuple[int, ...]]] = None
    # If this value is non-None, then the address on this instruction is shifted by the
    # integer part of the value of the given LFO.
    lfo_num: Optional[int] = None

    def uses_defines(self):
        uses = set()
        defines = set()

        if self.opcode == DSPInstruction.SUMHLF:
            uses.add(self.addr)
            uses.add("Acc")
            defines.add("Acc")
        elif self.opcode == DSPInstruction.LDHLF:
            uses.add(self.addr)
            defines.add("Acc")
        elif self.opcode in {DSPInstruction.STRPOS, DSPInstruction.STRNEG}:
            uses.add("Acc")
            defines.add(self.addr)
            defines.add("Acc")
        elif self.opcode in {DSPInstruction.STORE, DSPInstruction.STOREN}:
            uses.add("Acc")
            defines.add(self.addr)
        elif self.opcode in {DSPInstruction.ADDHLF, DSPInstruction.NEGHLF}:
            uses.add("Acc")
            defines.add("Acc")
        elif self.opcode == DSPInstruction.INPUT:
            uses.add("Input")
            defines.add(self.addr)
        elif self.opcode == DSPInstruction.OUTPUT_LEFT:
            uses.add(self.addr)
            defines.add("Left")
        elif self.opcode == DSPInstruction.OUTPUT_RIGHT:
            uses.add(self.addr)
            defines.add("Right")
        else:
            raise Exception('unhandled case variant')

        # If the instruction is "patched", then it's sort-of a phi node. It depends
        # on all addresses/variables that it could possibly read.
        if self.patched is not None:
            uses |= set(self.patched[1])

        return uses, defines

    def pretty_string(self):
        addr_str = f"0x{self.addr:04x}" if self.addr is not None else "None"

        if self.opcode == DSPInstruction.SUMHLF:
            return f"Acc = Acc + DRAM[{addr_str}]/2 + sgn"
        elif self.opcode == DSPInstruction.LDHLF:
            return f"Acc = DRAM[{addr_str}]/2 + sgn"
        elif self.opcode == DSPInstruction.STRPOS:
            return f"DRAM[{addr_str}] = Acc, Acc = Acc + Acc/2 + sgn"
        elif self.opcode == DSPInstruction.STRNEG:
            return f"DRAM[{addr_str}] = ~Acc, Acc = ~Acc/2 + sgn"
        elif self.opcode == DSPInstruction.INPUT:
            return f"DRAM[{addr_str}] = Input"
        elif self.opcode == DSPInstruction.OUTPUT_LEFT:
            return f"Left = DRAM[{addr_str}]"
        elif self.opcode == DSPInstruction.OUTPUT_RIGHT:
            return f"Right = DRAM[{addr_str}]"
        elif self.opcode == DSPInstruction.STORE:
            return f"DRAM[{addr_str}] = Acc"
        elif self.opcode == DSPInstruction.STOREN:
            return f"DRAM[{addr_str}] = ~Acc"
        elif self.opcode == DSPInstruction.ADDHLF:
            return f"Acc = Acc + Acc/2 + sgn"
        elif self.opcode == DSPInstruction.NEGHLF:
            return f"Acc = ~Acc/2 + sgn"
        else:
            return "Unknown instruction"

    def c_string(self):
        addr_str = f"0x{self.addr:04x}" if self.addr is not None else "None"

        if self.opcode == DSPInstruction.SUMHLF:
            return f"Data = MEM({addr_str}); Acc = Acc + (Data >> 1) + Sgn(Data)"
        elif self.opcode == DSPInstruction.LDHLF:
            return f"Data = MEM({addr_str}); Acc = (Data >> 1) + Sgn(Data)"
        elif self.opcode == DSPInstruction.STRPOS:
            return f"MEM({addr_str}) = Acc; Acc = Acc + (Acc >> 1) + Sgn(Acc)"
        elif self.opcode == DSPInstruction.STRNEG:
            return f"MEM({addr_str}) = ~Acc; Acc = ~(Acc >> 1) + Sgn(~Acc)"
        elif self.opcode == DSPInstruction.INPUT:
            return f"MEM({addr_str}) = input"
        elif self.opcode == DSPInstruction.OUTPUT_LEFT:
            return f"*out_left = MEM({addr_str})"
        elif self.opcode == DSPInstruction.OUTPUT_RIGHT:
            return f"*out_right = MEM({addr_str})"
        elif self.opcode == DSPInstruction.STORE:
            return f"MEM({addr_str}) = Acc"
        elif self.opcode == DSPInstruction.STOREN:
            return f"MEM({addr_str}) = ~Acc"
        elif self.opcode == DSPInstruction.ADDHLF:
            return f"Acc = Acc + (Acc >> 1) + Sgn(Acc)"
        elif self.opcode == DSPInstruction.NEGHLF:
            return f"Acc = ~(Acc >> 1) + Sgn(~Acc)"

        else:
            return "Unknown instruction"


class DelayLine:
    def __init__(self, addr, tap_addrs):
        self.taps = [(addr - tap_addr) & 0x3fff for tap_addr in tap_addrs]
        self.length = max(self.taps)
        self.tap_addrs = tap_addrs
        self.addr = addr
        self.id = None

    def __str__(self):
        return (f"DelayLine(id={self.id},addr={self.addr}, tap_addrs={self.tap_addrs}, "
                f"taps={self.taps}, length={self.length})")


# =============================================================================
# Backend Interface for Decompiler Output
# =============================================================================
#
# Term types for expressions:
#   - (line_id, write_addr, offset) : memory read from delay line
#   - (line_id, write_addr, offset, lfo_num) : memory read with LFO modulation
#   - 'temp_name' : temp variable
#   - 'Acc' : accumulator
#
# Expression = list of (term, numerator, denominator)
# Example: LINE(0,100,50)/2 + temp_x*3/4 - Acc/8
#   = [((0, 100, 50), 1, 2), ('temp_x', 3, 4), ('Acc', -1, 8)]

class Backend:
    """Base class for decompiler output backends."""

    def __init__(self, output_file):
        self.f = output_file
        self._indent_level = 1  # Base indentation level (inside function)

    def begin(self, name: str, temps: list, effect_num: int = None, effect_name: str = None, unit_name: str = None):
        """Emit function header and declare locals (Acc, temps, out_left, out_right)."""
        raise NotImplementedError

    def end(self):
        """Emit function footer (return statement for JS, closing brace)."""
        raise NotImplementedError

    def input(self, line_id: int, addr: int, lfo_num: int = None):
        """Emit: DRAM[addr] = input."""
        raise NotImplementedError

    def output(self, which: str, expr: list):
        """Emit: out_{which} = formatted(expr). which is 'left' or 'right'."""
        raise NotImplementedError

    def acc(self, expr: list):
        """Emit: Acc = formatted(expr)."""
        raise NotImplementedError

    def store(self, line_id: int, addr: int, expr: list, lfo_num: int = None):
        """Emit: DRAM[addr] = formatted(expr)."""
        raise NotImplementedError

    def temp(self, name: str, expr: list, lfo_num: int = None):
        """Emit: temp_name = formatted(expr)."""
        raise NotImplementedError

    def switch_begin(self, lfo_num: int):
        """Emit: switch ((lfoN_value >> 4) & 15) {"""
        raise NotImplementedError

    def switch_case(self, value: int):
        """Emit: case N:"""
        raise NotImplementedError

    def switch_break(self):
        """Emit: break;"""
        raise NotImplementedError

    def switch_end(self):
        """Emit: }"""
        raise NotImplementedError

    def function_table(self, prefix: str, programs: list):
        """Emit function pointer array (C) or object (JS)."""
        raise NotImplementedError

    def format_expr(self, expr: list) -> str:
        """Format an expression as a string. To be implemented by subclasses."""
        raise NotImplementedError

    def format_term(self, term, num: int, denom: int) -> str:
        """Format a single term with coefficient. To be implemented by subclasses."""
        raise NotImplementedError

    def format_mem_read(self, line_id: int, addr: int, offset: int, lfo_num: int = None) -> str:
        """Format a memory read expression."""
        raise NotImplementedError


class CBackend(Backend):
    """C code output backend."""

    def _indent(self) -> str:
        """Return the current indentation string."""
        return '\t' * self._indent_level

    def begin(self, name: str, temps: list, effect_num: int = None, effect_name: str = None, unit_name: str = None):
        self._indent_level = 1
        if effect_name is not None:
            unit_prefix = f'{unit_name} ' if unit_name else ''
            self.f.write(f'/* {unit_prefix}effect {effect_num}: {effect_name} */\n')
        self.f.write('#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])\n')
        self.f.write('#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])\n')
        self.f.write(f'void {name}(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {{\n')
        local_vars = ['Acc'] + temps
        local_vars_str = ', '.join(local_vars)
        self.f.write(f'{self._indent()}int16_t {local_vars_str};\n')

    def end(self):
        self.f.write('}\n')
        self.f.write('#undef LINE\n')
        self.f.write('#undef WRITE_LINE\n')

    def input(self, line_id: int, addr: int, lfo_num: int = None):
        write_str = self._format_write_addr(line_id, addr, lfo_num)
        self.f.write(f'{self._indent()}{write_str} = input;\n')

    def output(self, which: str, expr: list):
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}*out_{which} = {expr_str};\n')

    def acc(self, expr: list):
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}Acc = {expr_str};\n')

    def store(self, line_id: int, addr: int, expr: list, lfo_num: int = None):
        write_str = self._format_write_addr(line_id, addr, lfo_num)
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}{write_str} = {expr_str};\n')

    def temp(self, name: str, expr: list, lfo_num: int = None):
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}{name} = {expr_str};\n')

    def switch_begin(self, lfo_num: int):
        self.f.write(f"{self._indent()}switch ((lfo{lfo_num}_value >> 4) & 15) {{\n")
        self._indent_level += 1

    def switch_case(self, value: int):
        # Case labels are at switch level (one less indent)
        self.f.write(f"{'\t' * (self._indent_level - 1)}case {value}:\n")

    def switch_break(self):
        self.f.write(f"{self._indent()}break;\n")

    def switch_end(self):
        self._indent_level -= 1
        self.f.write(f"{self._indent()}}}\n")

    def function_table(self, prefix: str, programs: list):
        self.f.write(f'void (*{prefix}effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr, uint32_t lfo1_value, uint32_t lfo2_value) = {{\n')
        for program_number in programs:
            self.f.write(f'\t{prefix}effect_{program_number},\n')
        self.f.write('};\n')

    def _format_write_addr(self, line_id: int, addr: int, lfo_num: int = None) -> str:
        if lfo_num is not None:
            return f"WRITE_LINE({line_id}, ({addr} - (lfo{lfo_num}_value >> 8)))"
        else:
            return f"WRITE_LINE({line_id}, {addr})"

    def format_mem_read(self, line_id: int, addr: int, offset: int, lfo_num: int = None) -> str:
        if lfo_num is not None:
            return f"LINE({line_id}, ({addr} - (lfo{lfo_num}_value >> 8)), {offset})"
        else:
            return f"LINE({line_id}, {addr}, {offset})"

    def format_term(self, term_str: str, num: int, denom: int) -> str:
        """Format a single term with coefficient for C."""
        frac = Fraction(num, denom)
        if frac == Fraction(1, 1):
            return term_str
        elif frac == Fraction(-1, 1):
            return f"-{term_str}"
        elif frac.numerator == 1:
            return f"{term_str} / {frac.denominator}"
        elif frac.numerator == -1:
            return f"-{term_str} / {frac.denominator}"
        else:
            return f"{term_str} * {frac.numerator} / {frac.denominator}"

    def format_expr(self, expr: list) -> str:
        """Format an expression as C code."""
        if len(expr) == 0:
            return "0"
        terms = []
        for term, num, denom in expr:
            if isinstance(term, tuple):
                if len(term) == 4:
                    # Memory read with LFO: (line_id, addr, offset, lfo_num)
                    term_str = self.format_mem_read(term[0], term[1], term[2], term[3])
                else:
                    # Memory read: (line_id, addr, offset)
                    term_str = self.format_mem_read(term[0], term[1], term[2])
            else:
                # String term: 'Acc', 'tmp_x', etc.
                term_str = term
            terms.append(self.format_term(term_str, num, denom))
        return " + ".join(terms)


class JSBackend(Backend):
    """JavaScript code output backend."""

    def _indent(self) -> str:
        """Return the current indentation string (2 spaces per level)."""
        return '  ' * self._indent_level

    def begin(self, name: str, temps: list, effect_num: int = None, effect_name: str = None, unit_name: str = None):
        self._indent_level = 1
        if effect_name is not None:
            unit_prefix = f'{unit_name} ' if unit_name else ''
            self.f.write(f'/* {unit_prefix}effect {effect_num}: {effect_name} */\n')
        self.f.write(f'function {name}(input, DRAM, ptr, lfo1_value, lfo2_value) {{\n')
        self.f.write(f'{self._indent()}const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];\n')
        self.f.write(f'{self._indent()}const WRITE_LINE = (id, w_addr, val) => {{ DRAM[(ptr + w_addr) & 0x3fff] = val; }};\n')
        local_vars = ['Acc'] + temps + ['out_left', 'out_right']
        local_vars_str = ', '.join(local_vars)
        self.f.write(f'{self._indent()}let {local_vars_str};\n')

    def end(self):
        self.f.write(f'{self._indent()}return [out_left, out_right];\n')
        self.f.write('}\n')

    def input(self, line_id: int, addr: int, lfo_num: int = None):
        if lfo_num is not None:
            self.f.write(f"{self._indent()}WRITE_LINE(0, ({addr} - (lfo{lfo_num}_value >> 8)), input);\n")
        else:
            self.f.write(f"{self._indent()}WRITE_LINE(0, {addr}, input);\n")

    def output(self, which: str, expr: list):
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}out_{which} = {expr_str};\n')

    def acc(self, expr: list):
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}Acc = {expr_str};\n')

    def store(self, line_id: int, addr: int, expr: list, lfo_num: int = None):
        expr_str = self.format_expr(expr)
        if lfo_num is not None:
            self.f.write(f"{self._indent()}WRITE_LINE(0, ({addr} - (lfo{lfo_num}_value >> 8)), {expr_str});\n")
        else:
            self.f.write(f"{self._indent()}WRITE_LINE(0, {addr}, {expr_str});\n")

    def temp(self, name: str, expr: list, lfo_num: int = None):
        expr_str = self.format_expr(expr)
        self.f.write(f'{self._indent()}{name} = {expr_str};\n')

    def switch_begin(self, lfo_num: int):
        self.f.write(f"{self._indent()}switch ((lfo{lfo_num}_value >> 4) & 15) {{\n")
        self._indent_level += 1

    def switch_case(self, value: int):
        # Case labels are at switch level (one less indent)
        self.f.write(f"{'  ' * (self._indent_level - 1)}case {value}:\n")

    def switch_break(self):
        self.f.write(f"{self._indent()}break;\n")

    def switch_end(self):
        self._indent_level -= 1
        self.f.write(f"{self._indent()}}}\n")

    def function_table(self, prefix: str, programs: list):
        self.f.write(f'\nconst {prefix}effects = {{\n')
        for program_number in programs:
            self.f.write(f'  {program_number}: {prefix}effect_{program_number},\n')
        self.f.write('};\n')

    def format_mem_read(self, line_id: int, addr: int, offset: int, lfo_num: int = None) -> str:
        if lfo_num is not None:
            return f"LINE({line_id}, ({addr} - (lfo{lfo_num}_value >> 8)), {offset})"
        else:
            return f"LINE({line_id}, {addr}, {offset})"

    def format_term(self, term_str: str, num: int, denom: int) -> str:
        """Format a single term with coefficient for JavaScript.

        Only adds |0 truncation for division operations (where precision loss occurs).
        Simple negation (-Acc) doesn't need truncation since it's integer arithmetic.
        """
        frac = Fraction(num, denom)
        if frac == Fraction(1, 1):
            return term_str
        elif frac == Fraction(-1, 1):
            # Simple negation - no truncation needed
            return f"-{term_str}"
        elif frac.numerator == 1:
            return f"(({term_str} / {frac.denominator}) | 0)"
        elif frac.numerator == -1:
            return f"((-{term_str} / {frac.denominator}) | 0)"
        else:
            return f"(({term_str} * {frac.numerator} / {frac.denominator}) | 0)"

    def format_expr(self, expr: list) -> str:
        """Format an expression as JavaScript code."""
        if len(expr) == 0:
            return "0"
        terms = []
        for term, num, denom in expr:
            if isinstance(term, tuple):
                if len(term) == 4:
                    # Memory read with LFO: (line_id, addr, offset, lfo_num)
                    term_str = self.format_mem_read(term[0], term[1], term[2], term[3])
                else:
                    # Memory read: (line_id, addr, offset)
                    term_str = self.format_mem_read(term[0], term[1], term[2])
            else:
                # String term: 'Acc', 'tmp_x', etc.
                term_str = term
            terms.append(self.format_term(term_str, num, denom))
        return " + ".join(terms)


class DelayLineStorage:
    def __init__(self):
        self.lines = []
        self.read_addrs = {}
        self.write_addrs = {}
        self.tmp_addrs = set()
        self.tmp_addrs_that_read_real_memory = set()

    def add(self, line):
        i = len(self.lines)
        line.id = i
        self.lines.append(line)
        for addr in line.tap_addrs:
            self.read_addrs[addr] = i
        self.write_addrs[line.addr] = i

    def add_tmp(self, addr, is_read_first):
        self.tmp_addrs.add(addr)
        if is_read_first:
            self.tmp_addrs_that_read_real_memory.add(addr)

    @staticmethod
    def get_tmp_name(addr):
        return f"tmp_{addr:x}"

    def format_read_address(self, addr, was_this_addr_written, indexed_by_lfo=None):
        if addr in self.tmp_addrs:
            if not addr in self.tmp_addrs_that_read_real_memory or was_this_addr_written:
                return self.get_tmp_name(addr)
        id = self.read_addrs.get(addr)
        if id is None:
            id = self.write_addrs.get(addr)
        if id is None:
            return None
        line = self.lines[id]
        offset = (line.addr - addr) & 0x3fff
        if indexed_by_lfo is not None:
            return f"LINE({line.id}, ({line.addr} - (lfo{indexed_by_lfo}_value >> 8)), {offset})"
        else:
            return f"LINE({line.id}, {line.addr}, {offset})"

    def format_write_address(self, addr, indexed_by_lfo=None):
        if addr in self.tmp_addrs:
            return self.get_tmp_name(addr)
        id = self.write_addrs.get(addr)
        if id is None:
            return None

        line = self.lines[id]
        if indexed_by_lfo is not None:
            return f"WRITE_LINE({line.id}, ({line.addr} - (lfo{indexed_by_lfo}_value >> 8)))"
        else:
            return f"WRITE_LINE({line.id}, {line.addr})"

class Accumulator:
    """Represents an accumulator expression as a sum of terms with fractional coefficients."""

    def __init__(self, terms):
        self.terms = terms

    @staticmethod
    def empty():
        return Accumulator(terms=dict())

    @staticmethod
    def term(name, a, b):
        terms={name: Fraction(a, b)}
        return Accumulator(terms)

    def to_expr_list(self) -> list:
        """Convert the accumulator to an expression list for the backend."""
        result = []
        for k, v in self.terms.items():
            result.append((k, v.numerator, v.denominator))
        return result

    def __neg__(self):
        return Accumulator({ k: -v for k, v in self.terms.items() })

    def __mul__(self, other):
        return Accumulator({ k: v * other for k, v in self.terms.items() if abs(v) > 0.00001 })

    def __truediv__(self, other):
        return Accumulator({ k: v / other for k, v in self.terms.items() if abs(v) > 0.00001 })

    def __add__(self, other):
        new = Accumulator(self.terms.copy())
        new += other
        return new

    def __iadd__(self, other):
        for (k, v) in other.terms.items():
            if self.terms.get(k) is None:
                self.terms[k] = v
            else:
                self.terms[k] += v
        return self


def decompile_with_backend(end_address, encoded_instructions, function_name, backend: Backend, effect_number=None, effect_name=None, unit_name=None):
    """
    Decompile DSP instructions using the provided backend.

    This unified function handles the optimization passes and emits code
    through the backend interface, which formats output for C or JavaScript.
    """
    assert end_address == 1, "address counter doesn't end up offseted by 1 - decompiler expects that"

    print('-- Pass 1: Find uses/defines of the whole program')
    prev_used = set()
    prev_defined = set()
    for instr in encoded_instructions:
        uses, defines = instr.uses_defines()
        prev_used |= uses - prev_defined
        prev_defined |= defines

    print('Program used:', prev_used)
    print('Program defined:', prev_defined)

    print('-- Pass 2: Calculate which addresses start a delay line and get used on following samples')
    used_address = {x for x in prev_used if isinstance(x, int)}
    defined_address = {x for x in prev_defined if isinstance(x, int)}
    memory_locations = []
    for addr in used_address.union(defined_address):
        memory_locations.append({
            'addr': addr,
            'write': addr in defined_address,
            'read': addr in used_address,
        })
    memory_locations.sort(key=lambda x: x['addr'])
    print('Read/write locations:', memory_locations)

    # Calculate all delay lines
    n = len(memory_locations)
    delay_line_storage = DelayLineStorage()
    not_read = set()
    used_writes = set()
    for i, location in enumerate(memory_locations):
        if location['write']:
            taps = []
            j = (i - 1) % n
            while j != i:
                if memory_locations[j]['read']:
                    taps.append(memory_locations[j]['addr'])
                if memory_locations[j]['write']:
                    break
                j = (j - 1) % n
            if len(taps) == 0:
                not_read.add(location['addr'])
                delay_line_storage.add_tmp(location['addr'], location['read'])
            else:
                used_writes.add(location['addr'])
                delay_line = DelayLine(addr=location['addr'], tap_addrs=taps)
                delay_line_storage.add(delay_line)

    print('Writes not read:', not_read)
    print('Writes read:', used_writes)

    print('-- Pass 3: Eliminate dead instructions')
    will_be_needed = used_writes | set(['Left', 'Right'])
    used_locations = set()
    pass3_instructions = []

    for instr in reversed(encoded_instructions):
        uses, defines = instr.uses_defines()
        if defines.isdisjoint(will_be_needed):
            print('// eliminated:', instr.pretty_string())
            pass
        else:
            will_be_needed = (will_be_needed - defines) | uses
            used_locations |= uses
            print(instr.pretty_string())
            pass3_instructions.append(instr)
    pass3_instructions = list(reversed(pass3_instructions))

    print(f'-- Pass 4: Output program via backend')
    for line in delay_line_storage.lines:
        print(f"Delay line {line.id}: length={line.length}, taps={line.taps}")

    # Collect temp variable names
    temps = [delay_line_storage.get_tmp_name(addr) for addr in delay_line_storage.tmp_addrs if addr in used_locations]

    backend.begin(function_name, temps, effect_number, effect_name, unit_name)

    # Helper to create a memory read term for the expression list
    def make_read_term(addr, was_written, lfo_num=None):
        """Create a term representing a memory read."""
        if addr in delay_line_storage.tmp_addrs:
            if not addr in delay_line_storage.tmp_addrs_that_read_real_memory or was_written:
                return delay_line_storage.get_tmp_name(addr)
        line_id = delay_line_storage.read_addrs.get(addr)
        if line_id is None:
            line_id = delay_line_storage.write_addrs.get(addr)
        if line_id is None:
            return None
        line = delay_line_storage.lines[line_id]
        offset = (line.addr - addr) & 0x3fff
        if lfo_num is not None:
            return (line_id, line.addr, offset, lfo_num)
        else:
            return (line_id, line.addr, offset)

    def get_write_info(addr, lfo_num=None):
        """Get write information: (line_id, addr, lfo_num) or None if it's a temp."""
        if addr in delay_line_storage.tmp_addrs:
            return None  # It's a temp variable
        line_id = delay_line_storage.write_addrs.get(addr)
        if line_id is None:
            return None
        return (line_id, addr, lfo_num)

    addrs_written = dict()
    acc = None

    def flush_acc():
        nonlocal acc
        if acc is not None:
            backend.acc(acc.to_expr_list())
            acc = None

    def default_acc():
        nonlocal acc
        if acc is None:
            acc = Accumulator.term('Acc', 1, 1)

    i = 0
    while i < len(pass3_instructions):
        instr = pass3_instructions[i]

        # If instruction is patched:
        # - find sequence of patched instructions in a row
        # - create a switch statement on fract value of selected LFO
        # - decompile each patched block
        # - skip those instruction in the regular pass
        if instr.patched is not None:
            lfo_num = instr.patched[0]
            num_patched = 0
            while pass3_instructions[i + num_patched].patched is not None and pass3_instructions[i + num_patched].patched[0] == lfo_num:
                num_patched += 1

            flush_acc()
            backend.switch_begin(lfo_num)
            for k in range(16):
                backend.switch_case(k)
                for j in range(num_patched):
                    instr = pass3_instructions[i + j]
                    addr = instr.patched[1][k]
                    read_term = make_read_term(addr, addr in addrs_written, instr.lfo_num)
                    if instr.opcode == DSPInstruction.SUMHLF:
                        default_acc()
                        acc += Accumulator.term(read_term, 1, 2)
                    elif instr.opcode == DSPInstruction.LDHLF:
                        acc = Accumulator.term(read_term, 1, 2)
                    else:
                        raise Exception("unsupported instr")
                flush_acc()
                backend.switch_break()

            backend.switch_end()

            i += num_patched
            continue

        if instr.opcode == DSPInstruction.SUMHLF:
            read_term = make_read_term(instr.addr, instr.addr in addrs_written, instr.lfo_num)
            default_acc()
            acc += Accumulator.term(read_term, 1, 2)
        elif instr.opcode == DSPInstruction.LDHLF:
            read_term = make_read_term(instr.addr, instr.addr in addrs_written, instr.lfo_num)
            acc = Accumulator.term(read_term, 1, 2)
        elif instr.opcode == DSPInstruction.INPUT:
            flush_acc()
            write_info = get_write_info(instr.addr, instr.lfo_num)
            if write_info:
                backend.input(write_info[0], write_info[1], write_info[2])
            else:
                # Input to a temp (shouldn't happen normally)
                backend.temp(delay_line_storage.get_tmp_name(instr.addr), [('input', 1, 1)], instr.lfo_num)
            addrs_written[instr.addr] = True
        elif instr.opcode == DSPInstruction.OUTPUT_LEFT:
            read_term = make_read_term(instr.addr, instr.addr in addrs_written, instr.lfo_num)
            backend.output('left', [(read_term, 1, 1)])
        elif instr.opcode == DSPInstruction.OUTPUT_RIGHT:
            read_term = make_read_term(instr.addr, instr.addr in addrs_written, instr.lfo_num)
            backend.output('right', [(read_term, 1, 1)])
        elif instr.opcode == DSPInstruction.STORE:
            flush_acc()
            write_info = get_write_info(instr.addr, instr.lfo_num)
            if write_info:
                backend.store(write_info[0], write_info[1], [('Acc', 1, 1)], write_info[2])
            else:
                backend.temp(delay_line_storage.get_tmp_name(instr.addr), [('Acc', 1, 1)], instr.lfo_num)
            addrs_written[instr.addr] = True
        elif instr.opcode == DSPInstruction.STOREN:
            flush_acc()
            write_info = get_write_info(instr.addr, instr.lfo_num)
            if write_info:
                backend.store(write_info[0], write_info[1], [('Acc', -1, 1)], write_info[2])
            else:
                backend.temp(delay_line_storage.get_tmp_name(instr.addr), [('Acc', -1, 1)], instr.lfo_num)
            addrs_written[instr.addr] = True
        elif instr.opcode == DSPInstruction.ADDHLF:
            default_acc()
            acc += acc / 2
        elif instr.opcode == DSPInstruction.NEGHLF:
            default_acc()
            acc = (-acc) / 2
        else:
            raise Exception('unhandled instruction')
        i += 1

    flush_acc()
    backend.end()


# This is a really hacky solution to decompiling effects where the 8031 is live-patching
# effect programs with LFO coefficients, but YOLO, this whole decompiler needs
# to be decompiled as SSA anyway.
#
# How does it work?
#
#   * All choruses/flangers on Midiverb 2 are patched with the same coefficients
#     * There's a place in program where address is decremented by lfo offset (the integer
#       part), and another where it's incremented by the same offset.
#     * We annotate all instruction in-between to add this offset
#   * There are around two instructions in the program that are patched to select the
#     right interpolated value (there is 8 values and either one of them is selected,
#     or value exactly in between is selected). The fractional offset selects this value.
#   * We generate patched program for every of these 16 possible fractional points.
#   * We compare the program and find all instructions that changed.
#   * We assume the instruction type didn't change, only the offset.
#   * For each instruction we generate a patch table with possible addresses.
#   * This table is later decompiled as a `switch(fract)` statement
#
def patch_instructions_for_lfo(program, memory_shift, lfo_num, next_instr_opcode, pc1, pc2, original_program=None, interpolation_patch_table=None):
    prog = []
    difference_at = {}
    patch_table = {}
    ptlen = 16
    for k in range(ptlen):
        if lfo_num == 1:
            apply_modulation(program, k * 0x10, 0x00, next_instr_opcode, interpolation_patch_table)
        elif lfo_num == 2:
            apply_modulation(program, 0x00, k * 0x10, next_instr_opcode, interpolation_patch_table)
        else:
            assert "oops"
        _, ea, enc = disassemble_dsp(program, memory_shift)
        prog.append(enc)
        assert(ea == 1)
        assert(len(prog[0]) == len(prog[k]))
        for i in range(len(prog[0])):
            a = prog[0][i]
            b = prog[k][i]
            assert a.opcode == b.opcode, 'different opcode?'
            assert a.pc == b.pc, 'different pc?'

            if a.addr != b.addr:
                difference_at[i] = True

    for i in difference_at.keys():
        addrs = []
        for k in range(ptlen):
            a = prog[k][i].addr
            addrs.append(a)

        patch_table[i] = addrs

    # construct new program that has patches
    progx = original_program or prog[0].copy()
    for i in patch_table.keys():
        instr = progx[i]
        progx[i] = Instruction(instr.opcode, addr=instr.addr, pc=instr.pc, lfo_num=instr.lfo_num, patched=(lfo_num, tuple(patch_table[i])))
    for i in range(len(progx)):
        instr = progx[i]
        if instr.pc > pc1 and instr.pc <= pc2:
            progx[i] = Instruction(instr.opcode, addr=instr.addr, pc=instr.pc, patched=instr.patched, lfo_num=lfo_num)

    return progx

def disassemble_dsp(program, memory_shift):
    def decode_instruction(pc, address, op, offset):
        if op == 0b00:
            name = f"sumhlf 0x{address:04x}"
            comment = f"Acc = Acc + DRAM[0x{address:04x}]/2 + sgn"
            instr = [Instruction(DSPInstruction.SUMHLF, addr=address, pc=pc)]
        elif op == 0b01:
            name = f"ldhlf  0x{address:04x}"
            comment = f"Acc = DRAM[0x{address:04x}]/2 + sgn"
            instr = [Instruction(DSPInstruction.LDHLF, addr=address, pc=pc)]
        elif op == 0b10:
            name = f"strpos 0x{address:04x}"
            comment = f"DRAM[0x{address:04x}] = Acc, Acc = Acc + Acc/2 + sgn"
            # Break the instruction into two virtual instructions for simpler analysis later
            #instr = Instruction(DSPInstruction.STRPOS, addr=address, pc=pc)
            instr = [
                Instruction(DSPInstruction.STORE, addr=address, pc=pc),
                Instruction(DSPInstruction.ADDHLF, pc=pc),
            ]
        elif op == 0b11:
            name = f"strneg 0x{address:04x}"
            comment = f"DRAM[0x{address:04x}] = ~Acc, Acc = ~Acc/2 + sgn"
            # Break the instruction into two virtual instructions for simpler analysis later
            #instr = Instruction(DSPInstruction.STRNEG, addr=address, pc=pc)
            instr = [
                Instruction(DSPInstruction.STOREN, addr=address, pc=pc),
                Instruction(DSPInstruction.NEGHLF, pc=pc),
            ]
        else:
            name = "unknown"
            comment = ""

        if pc == 0x00:
            assert op == 0
            comment = f"DRAM[0x{address:04x}] = Input"
            instr = [Instruction(DSPInstruction.INPUT, addr=address, pc=pc)]
        elif pc == 0x60:
            assert op == 0
            comment = f'Left = DRAM[0x{address:04x}]'
            instr = [Instruction(DSPInstruction.OUTPUT_LEFT, addr=address, pc=pc)]
        elif pc == 0x70:
            assert op == 0
            comment = f'Right = DRAM[0x{address:04x}]'
            instr = [Instruction(DSPInstruction.OUTPUT_RIGHT, addr=address, pc=pc)]

        return f"{pc:02x} {op} {offset:04x}   {name}    {comment}", (address + offset) & 0x3fff, instr

    disassembled_instructions = []
    encoded_instructions = []
    address = 0
    for pc in range(0, 128):
        op = program[(2 * pc - memory_shift - 1) % 256] >> 6
        offset = ((program[(2 * pc - memory_shift + 1) % 256] & 0x3f) << 8) | program[(2 * pc - memory_shift) % 256]
        text, address, instructions = decode_instruction(pc, address, op, offset)
        disassembled_instructions.append(text)
        encoded_instructions += instructions

    return disassembled_instructions, address, encoded_instructions


class Programs:
    PROGRAM_LEN = 256

    def __init__(self, path, first_program_number, start_offset):
        self.programs = {}
        self.program_numbers = []

        i = first_program_number
        with open(path, 'rb') as file:
            if start_offset > 0:
                file.read(start_offset)
            while True:
                b = file.read(Programs.PROGRAM_LEN)
                if len(b) < Programs.PROGRAM_LEN:
                    break
                self.programs[i] = b
                self.program_numbers.append(i)
                i += 1

    def get(self, n):
        return self.programs.get(n)

    def all_programs(self):
        return self.program_numbers

def int_or_hex(value):
    """Parse a string as int, supporting hex (0x) or decimal."""
    try:
        return int(value, 0)  # base=0 auto-detects 0x, 0o, etc.
    except ValueError:
        raise argparse.ArgumentTypeError(f"{value!r} is not a valid int or hex value")

def parse_names_file(path, first_program_number):
    """Parse a names file containing one quoted string per line.
    Returns a dict mapping program number to name."""
    names = {}
    with open(path, 'r') as f:
        for i, line in enumerate(f):
            line = line.strip()
            if line.startswith('"') and line.rstrip(',').endswith('"'):
                # Remove quotes and trailing comma
                name = line.rstrip(',')[1:-1]
                names[first_program_number + i] = name
    return names

def add16(ahi, alo, bhi, blo):
    return (ahi + bhi + ((alo + blo) >> 8), (alo + blo) & 0xff)

def sub16(ahi, alo, bhi, blo):
    return (ahi + bhi + ((alo + blo) >> 8), (alo + blo) & 0xff)

def apply_modulation(program, lfo1_value, lfo2_value, lfo_op, patch_table):

    # LFO 1
    patch = patch_table[(lfo1_value & 0xf0):]
    sub = ((patch[1] << 8) | patch[0]) - (lfo1_value >> 8)
    add = ((patch[7] << 8) | patch[6]) + (lfo1_value >> 8)
    program[0x05] = sub & 0xff
    program[0x06] = ((sub >> 8) & 0x3f) | 0x40
    program[0x59] = patch[2]
    program[0x5a] = patch[3]
    program[0x5b] = patch[4]
    program[0x5c] = patch[5]
    program[0x5d] = add & 0xff
    program[0x5e] = ((add >> 8) & 0x3f) | lfo_op

    # LFO 2
    patch = patch_table[8 + (lfo2_value & 0xf0):]
    sub = ((patch[1] << 8) | patch[0]) - (lfo2_value >> 8)
    add = ((patch[7] << 8) | patch[6]) + (lfo2_value >> 8)
    program[0x5f] = sub & 0xff
    program[0x60] = ((sub >> 8) & 0x3f) | 0x40
    program[0xb3] = patch[2]
    program[0xb4] = patch[3]
    program[0xb5] = patch[4]
    program[0xb6] = patch[5]
    program[0xb7] = add & 0xff
    program[0xb8] = ((add >> 8) & 0x3f) | lfo_op



def main():
    parser = argparse.ArgumentParser(description="Disassemble MidiVerb program and optionally decompile it to C.")
    parser.add_argument("-d", "--decompile", metavar="output.c", help="Decompile effect program to C and save to the specified filename")
    parser.add_argument("-j", "--javascript", metavar="output.js", help="Decompile effect program to JavaScript and save to the specified filename")
    parser.add_argument("-U", "--unoptimized", action='store_true', help="Do not optimize the resulting C function with dead-code elimination and constant-folding")
    parser.add_argument("-i", "--integer-arithmetic", action='store_true', help="Use integer arithmetic instead of float-point arithmetic")
    parser.add_argument("-2", "--midiverb2", action='store_true', help="Assume the byte order is same as Midiverb 2, and start at 0x1c00 from program 0")
    parser.add_argument("-p", "--prefix", default="", help="Add custom prefix to decompiled functions")
    parser.add_argument("-n", "--names", metavar="FILE", help="File with effect names (one per line, quoted strings)")
    parser.add_argument("-u", "--unit-name", metavar="NAME", help="Unit name for comments (e.g., 'Midiverb 2')")
    parser.add_argument("--lfo1", type=int_or_hex, help="Apply LFO1 modulation (from modulation table)")
    parser.add_argument("--lfo2", type=int_or_hex, help="Apply LFO2 modulation (from modulation table)")
    parser.add_argument("--lfo-op", type=int_or_hex, help="LFO operator")
    parser.add_argument("rompath", help="Input ROM file")
    parser.add_argument("program_number", nargs='?', type=int, default=None, help="Program number (1-64 for Midiverb I, 0-99 for Midiverb II)")

    args = parser.parse_args()
    if args.midiverb2:
        first_program_number = 0
        start_offset = 0x1c00
        memory_shift = 1
        # Load interpolation patch table for LFO effects (offset 0x1b00, 256 bytes)
        with open(args.rompath, 'rb') as f:
            f.seek(0x1b00)
            interpolation_patch_table = bytearray(f.read(256))
    else:
        first_program_number = 1
        start_offset = 0
        memory_shift = 2
        interpolation_patch_table = None

    programs = Programs(args.rompath, first_program_number, start_offset)
    if args.program_number is not None:
        decode = [args.program_number]
    else:
        decode = programs.all_programs()

    # Parse effect names if provided
    effect_names = {}
    if args.names is not None:
        effect_names = parse_names_file(args.names, first_program_number)

    # Create backends based on command-line arguments
    c_backend = None
    js_backend = None

    if args.decompile is not None:
        decompiler_output = open(args.decompile, 'w')
        c_backend = CBackend(decompiler_output)
    else:
        decompiler_output = None

    if args.javascript is not None:
        javascript_output = open(args.javascript, 'w')
        javascript_output.write('// Auto-generated JavaScript DSP code from disasm.py\n')
        javascript_output.write('// These functions share the same DRAM array with the emulator\n\n')
        js_backend = JSBackend(javascript_output)
    else:
        javascript_output = None

    for program_number in decode:
        program = programs.get(program_number)
        if program is None:
            raise Exception(f"Program #{program_number} not found")

        print(f"-- Disassembling program #{program_number}")
        program = list(program)
        if args.lfo1 is not None or args.lfo2 is not None:
            lfo1 = args.lfo1 if args.lfo1 is not None else 0
            lfo2 = args.lfo2 if args.lfo2 is not None else 0
            apply_modulation(program, lfo1, lfo2, args.lfo_op, interpolation_patch_table)
        disassembled_instructions, end_address, encoded_instructions = disassemble_dsp(program, memory_shift)
        for instr in disassembled_instructions:
            print(instr)
        print(f'-- End address 0x{end_address:x}')
        # Only patch LFO for midiverb and only the selected programs.
        if args.midiverb2 and (program_number >= 50 and program_number <= 69):
            # These values should be read from a table but ...
            if program_number < 60 and program_number % 2 == 0:
                next_instr_opcode = 0xc0
            else:
                next_instr_opcode = 0x80
            # Patch the program
            encoded_instructions = patch_instructions_for_lfo(program, memory_shift, 1, next_instr_opcode, 0x03, 0x2f, interpolation_patch_table=interpolation_patch_table)
            encoded_instructions = patch_instructions_for_lfo(program, memory_shift, 2, next_instr_opcode, 0x30, 0x5c, encoded_instructions, interpolation_patch_table=interpolation_patch_table)

        # Determine function name
        if len(decode) > 1:
            function_name = f'{args.prefix}effect_{program_number}'
        else:
            function_name = f'{args.prefix}effect'
        effect_name = effect_names.get(program_number)

        # Decompile using backends
        if c_backend is not None:
            decompile_with_backend(end_address, encoded_instructions, function_name, c_backend, program_number, effect_name, args.unit_name)

        if js_backend is not None:
            decompile_with_backend(end_address, encoded_instructions, function_name, js_backend, program_number, effect_name, args.unit_name)

    # Output function tables
    if c_backend is not None and len(decode) > 1:
        c_backend.function_table(args.prefix, decode)

    if js_backend is not None and len(decode) > 1:
        js_backend.function_table(args.prefix, decode)

    # Close output files
    if decompiler_output is not None:
        decompiler_output.close()
    if javascript_output is not None:
        javascript_output.close()

if __name__ == "__main__":
    main()
