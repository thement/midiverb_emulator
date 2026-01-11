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
    def __init__(self, terms):
        self.terms = terms

    @staticmethod
    def empty():
        return Accumulator(terms=dict())

    @staticmethod
    def term(name, a, b):
        terms={name: Fraction(a, b)}
        return Accumulator(terms)

    def to_string(self, integer_arithmetic=False):
        def multiplicand(k, v):
            if v == Fraction(1, 1):
                return k
            elif v == Fraction(-1, 1):
                return f"-{k}"
            elif v.numerator == 1:
                return f"{k} / {v.denominator}"
            elif v.numerator == -1:
                return f"-{k} / {v.denominator}"
            else:
                if integer_arithmetic:
                    return f"{k} * {v.numerator} / {v.denominator}"
                else:
                    return f"{k} * {float(v)}"
        terms = [multiplicand(k, v) for k, v in self.terms.items()]
        if len(terms) == 0:
            return "0"
        return " + ".join(terms)

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


def decompile(end_address, encoded_instructions, function_name, f, unoptimized=False, integer_arithmetic=False):
    assert end_address == 1, "address counter doesn't end up offseted by 1 - decompiler expects that"

    if unoptimized:
        print(f'-- Saving (unoptimized) code into a file')
        f.write('#define MEM(a) (DRAM[(ptr + a) & 0x3fff])\n')
        f.write('#define Sgn(a) ((a) < 0 ? 1 : 0)\n')
        f.write(f'void {function_name}(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr) {{\n')
        f.write(f'\tint16_t Acc, Data;\n')

        for instr in encoded_instructions:
            s = instr.c_string()
            f.write(f'\t{s};\n')
        f.write('}\n')
        f.write('#undef MEM\n')
        f.write('#undef Sgn\n')
        return

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
    # Accumulator is probably not used in between iterations, but just in case...
    #if 'Acc' in prev_used:
    #    will_be_needed.add('Acc')

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

    print(f'-- Pass 4: Output C program into a file')
    for line in delay_line_storage.lines:
        print(f"Delay line {line.id}: length={line.length}, taps={line.taps}")
    f.write('#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])\n')
    f.write('#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])\n')
    f.write(f'void {function_name}(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {{\n')
    local_vars = ['Acc'] + [delay_line_storage.get_tmp_name(addr) for addr in delay_line_storage.tmp_addrs if addr in used_locations]
    local_vars_str = ', '.join(local_vars)
    f.write(f'\tint16_t {local_vars_str};\n')

    addrs_written = dict()
    acc = None
    def flush_acc():
        nonlocal acc
        if acc is not None:
            acc_str = acc.to_string(integer_arithmetic)
            f.write(f'\tAcc = {acc_str};\n')
            acc = None
    def default_acc():
        nonlocal acc
        if acc is None:
            acc = Accumulator.term('Acc', 1, 1)

    i = 0
    while i < len(pass3_instructions):
        instr = pass3_instructions[i]
        s = None
        if instr.addr is not None:
            read_addr_str = delay_line_storage.format_read_address(instr.addr, instr.addr in addrs_written, instr.lfo_num)
            write_addr_str = delay_line_storage.format_write_address(instr.addr, instr.lfo_num)
        else:
            read_addr_str = None
            write_addr_str = None

        # If instruction is patched:
        #
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
            f.write(f"\tswitch ((lfo{lfo_num}_value >> 4) & 15) {{\n")
            for k in range(16):
                f.write(f"\tcase {k}:\n")
                for j in range(num_patched):
                    instr = pass3_instructions[i + j]
                    addr = instr.patched[1][k]
                    read_addr_str = delay_line_storage.format_read_address(addr, addr in addrs_written, instr.lfo_num)
                    if instr.opcode == DSPInstruction.SUMHLF:
                        default_acc()
                        acc += Accumulator.term(read_addr_str, 1, 2)
                    elif instr.opcode == DSPInstruction.LDHLF:
                        acc = Accumulator.term(read_addr_str, 1, 2)
                    else:
                        raise Exception("unsupported instr")
                f.write(f"\t")
                flush_acc()
                f.write(f"\t\tbreak;\n")

            f.write(f"\t}}\n")

            i += num_patched
            continue

        if instr.opcode == DSPInstruction.SUMHLF:
            default_acc( )
            acc += Accumulator.term(read_addr_str, 1, 2)
        elif instr.opcode == DSPInstruction.LDHLF:
            acc = Accumulator.term(read_addr_str, 1, 2)
        elif instr.opcode == DSPInstruction.INPUT:
            flush_acc()
            s = f"{write_addr_str} = input"
            addrs_written[instr.addr] = True
        elif instr.opcode == DSPInstruction.OUTPUT_LEFT:
            s = f"*out_left = {read_addr_str}"
        elif instr.opcode == DSPInstruction.OUTPUT_RIGHT:
            s = f"*out_right = {read_addr_str}"
        elif instr.opcode == DSPInstruction.STORE:
            flush_acc()
            s = f"{write_addr_str} = Acc"
            addrs_written[instr.addr] = True
        elif instr.opcode == DSPInstruction.STOREN:
            flush_acc()
            s = f"{write_addr_str} = -Acc"
            addrs_written[instr.addr] = True
        elif instr.opcode == DSPInstruction.ADDHLF:
            #s = f"Acc = Acc + Acc/2"
            default_acc()
            acc += acc / 2
        elif instr.opcode == DSPInstruction.NEGHLF:
            #s = f"Acc = -Acc/2"
            default_acc()
            acc = (-acc) / 2
        else:
            raise Exception('unhandled instruction')
            pass
        if s is not None:
            f.write(f"\t{s};\n")
        i += 1

    flush_acc()
    f.write('}\n')
    f.write('#undef LINE\n')
    f.write('#undef WRITE_LINE\n')


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
def patch_instructions_for_lfo(program, memory_shift, lfo_num, next_instr_opcode, pc1, pc2, original_program=None):
    prog = []
    difference_at = {}
    patch_table = {}
    ptlen = 16
    for k in range(ptlen):
        if lfo_num == 1:
            apply_modulation(program, k * 0x10, 0x00, next_instr_opcode)
        elif lfo_num == 2:
            apply_modulation(program, 0x00, k * 0x10, next_instr_opcode)
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

def add16(ahi, alo, bhi, blo):
    return (ahi + bhi + ((alo + blo) >> 8), (alo + blo) & 0xff)

def sub16(ahi, alo, bhi, blo):
    return (ahi + bhi + ((alo + blo) >> 8), (alo + blo) & 0xff)

def apply_modulation(program, lfo1_value, lfo2_value, lfo_op):
    with open('midiverb2_patches.rom', 'rb') as f:
        patch_table = bytearray(f.read())

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
    parser.add_argument("-U", "--unoptimized", action='store_true', help="Do not optimize the resulting C function with dead-code elimination and constant-folding")
    parser.add_argument("-i", "--integer-arithmetic", action='store_true', help="Use integer arithmetic instead of float-point arithmetic")
    parser.add_argument("-2", "--midiverb2", action='store_true', help="Assume the byte order is same as Midiverb 2, and start at 0x1c00 from program 0")
    parser.add_argument("-p", "--prefix", default="", help="Add custom prefix to decompiled functions")
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
    else:
        first_program_number = 1
        start_offset = 0
        memory_shift = 2

    programs = Programs(args.rompath, first_program_number, start_offset)
    if args.program_number is not None:
        decode = [args.program_number]
    else:
        decode = programs.all_programs()

    if args.decompile is not None:
        decompiler_output = open(args.decompile, 'w')
    else:
        decompiler_output = None

    for program_number in decode:
        program = programs.get(program_number)
        if program is None:
            raise Exception(f"Program #{program_number} not found")

        print(f"-- Disassembling program #{program_number}")
        program = list(program)
        if args.lfo1 is not None or args.lfo2 is not None:
            lfo1 = args.lfo1 if args.lfo1 is not None else 0
            lfo2 = args.lfo2 if args.lfo2 is not None else 0
            apply_modulation(program, lfo1, lfo2, args.lfo_op)
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
            encoded_instructions = patch_instructions_for_lfo(program, memory_shift, 1, next_instr_opcode, 0x03, 0x2f)
            encoded_instructions = patch_instructions_for_lfo(program, memory_shift, 2, next_instr_opcode, 0x30, 0x5c, encoded_instructions)

        if decompiler_output is not None:
            if len(decode) > 1:
                function_name = f'{args.prefix}effect_{program_number}'
            else:
                function_name = f'{args.prefix}effect'
            decompile(end_address, encoded_instructions, function_name, decompiler_output, args.unoptimized, args.integer_arithmetic)

    if decompiler_output is not None and len(decode) > 1:
        f = decompiler_output
        f.write(f'void (*{args.prefix}effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr, uint32_t lfo1_value, uint32_t lfo2_value) = {{\n')
        for program_number in decode:
            f.write(f'\t{args.prefix}effect_{program_number},\n')
        f.write('};\n')

if __name__ == "__main__":
    main()
