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
        self.tmp = set()

    def add(self, line):
        i = len(self.lines)
        line.id = i
        self.lines.append(line)
        for addr in line.tap_addrs:
            self.read_addrs[addr] = i
        self.write_addrs[line.addr] = i

    def add_tmp(self, addr):
        self.tmp.add(addr)

    @staticmethod
    def get_tmp_name(addr):
        return f"tmp{addr}"

    def format_address(self, addr):
        if addr in self.tmp:
            return self.get_tmp_name(addr)
        id = self.read_addrs.get(addr)
        if id is not None:
            line = self.lines[id]
            offset = (line.addr - addr) & 0x3fff
            return f"LINE({line.id}, {line.addr}, {offset})"
        id = self.write_addrs[addr]
        line = self.lines[id]
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
        return " + ".join(terms)

    def __neg__(self):
        return Accumulator({ k: -v for k, v in self.terms.items() })

    def __mul__(self, other):
        return Accumulator({ k: v * other for k, v in self.terms.items() })

    def __truediv__(self, other):
        return Accumulator({ k: v / other for k, v in self.terms.items() })

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


def analyze(address, encoded_instructions, output_filename, unoptimized=False, integer_arithmetic=False):
    assert address == 1, "address counter doesn't end up offseted by 1 - analysis expects that"

    if unoptimized:
        print(f'-- Saving (unoptimized) code into {output_filename}')
        with open(output_filename, 'w') as f:
            f.write('#define MEM(a) (DRAM[(ptr + a) & 0x3fff])\n')
            f.write('#define Sgn(a) ((a) < 0 ? 1 : 0)\n')
            f.write('void effect(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr) {\n')
            f.write(f'\tint16_t Acc, Data;\n')

            for instr in encoded_instructions:
                s = instr.c_string()
                f.write(f'\t{s};\n')
            f.write('}\n')
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
    memory_locations = [{'addr': num, 'write': False} for num in used_address] + \
                       [{'addr': num, 'write': True} for num in defined_address]
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
                if memory_locations[j]['write']:
                    break
                taps.append(memory_locations[j]['addr'])
                j = (j - 1) % n
            if len(taps) == 0:
                not_read.add(location['addr'])
                delay_line_storage.add_tmp(location['addr'])
            else:
                used_writes.add(location['addr'])
                delay_line = DelayLine(addr=location['addr'], tap_addrs=taps)
                delay_line_storage.add(delay_line)

    print('Writes not read:', not_read)
    print('Writes read:', used_writes)

    print('-- Pass 3: Eliminate dead instructions')
    will_be_needed = used_writes | set(['Left', 'Right'])
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
            print(instr.pretty_string())
            pass3_instructions.append(instr)
    pass3_instructions = reversed(pass3_instructions)

    print(f'-- Pass 4: Output C program to {output_filename}')
    with open(output_filename, 'w') as f:
        for line in delay_line_storage.lines:
            f.write(f"// Delay line {line.id}: length={line.length}, taps={line.taps}\n")
        f.write('#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])\n')
        f.write('#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])\n')
        f.write('void effect(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {\n')
        local_vars = ['Acc'] + [delay_line_storage.get_tmp_name(addr) for addr in delay_line_storage.tmp]
        local_vars_str = ', '.join(local_vars)
        f.write(f'\tint16_t {local_vars_str};\n')

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

        for instr in pass3_instructions:
            s = None
            if instr.addr is not None:
                addr_str = delay_line_storage.format_address(instr.addr)
            else:
                addr_str = None
            #f.write(f'// {instr}, addr_str = {addr_str}, opcode = {instr.opcode}\n');

            #flush_acc()
            if instr.opcode == DSPInstruction.SUMHLF:
                #s = f"Acc = Acc + {addr_str}/2"
                default_acc()
                acc += Accumulator.term(addr_str, 1, 2)
            elif instr.opcode == DSPInstruction.LDHLF:
                #s = f"Acc = {addr_str}/2"
                acc = Accumulator.term(addr_str, 1, 2)
            elif instr.opcode == DSPInstruction.INPUT:
                flush_acc()
                s = f"{addr_str} = input"
            elif instr.opcode == DSPInstruction.OUTPUT_LEFT:
                s = f"*out_left = {addr_str}"
            elif instr.opcode == DSPInstruction.OUTPUT_RIGHT:
                s = f"*out_right = {addr_str}"
            elif instr.opcode == DSPInstruction.STORE:
                flush_acc()
                s = f"{addr_str} = Acc"
            elif instr.opcode == DSPInstruction.STOREN:
                flush_acc()
                s = f"{addr_str} = -Acc"
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
        flush_acc()
        f.write('}\n')


def disassemble_dsp(program):
    def decode_instruction(pc, address, prev, this):
        op = prev >> 14
        offset = this & 0x3fff
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

        return f"{pc:02x} {op} {this:04x}   {name}    {comment}", (address + offset) & 0x3fff, instr

    disassembled_instructions = []
    encoded_instructions = []
    address = 0
    for pc in range(0, 128):
        prev = program[(pc + 126) % 128]
        this = program[(pc + 127) % 128]
        text, address, instructions = decode_instruction(pc, address, prev, this)
        disassembled_instructions.append(text)
        encoded_instructions += instructions

    return disassembled_instructions, address, encoded_instructions

def read_256_bytes_at_offset(file_path, n):
    offset = n * 256
    with open(file_path, 'rb') as file:
        file.seek(offset)  # Move the file pointer to the offset
        byte_data = file.read(256)  # Read the 256 bytes at the specified offset

    # Convert the byte data to a list of integers
    integer_list = list(byte_data)
    return integer_list

def validate_program_number(value):
    ivalue = int(value)
    if 1 <= ivalue <= 64:
        return ivalue
    raise argparse.ArgumentTypeError(f"Program number must be an integer between 1 and 64, got {value}")

def main():
    parser = argparse.ArgumentParser(description="Disassemble MidiVerb program and optionally decompile it to C.")
    parser.add_argument("filename", help="Input ROM filename")
    parser.add_argument("program_number", type=validate_program_number, help="Program number (1-64)")
    parser.add_argument("-d", "--decompile", metavar="output_c_file", help="Decompile effect program to C and save to the specified filename")
    parser.add_argument("-U", "--unoptimized", action='store_true', help="Do not optimize the resulting C function with dead-code elimination and constant-folding")
    parser.add_argument("-i", "--integer-arithmetic", action='store_true', help="Use integer arithmetic instead of float-point arithmetic")

    args = parser.parse_args()

    byte_list = read_256_bytes_at_offset(args.filename, args.program_number - 1)
    word_list = [int.from_bytes(byte_list[i:i+2], 'little') for i in range(0, len(byte_list), 2)]

    print(f"-- Disassembling program #{args.program_number}")
    disassembled_instructions, address, encoded_instructions = disassemble_dsp(word_list)
    for instr in disassembled_instructions:
        print(instr)
    print(f'-- End address 0x{address:x}')

    if args.decompile:
        analyze(address, encoded_instructions, args.decompile, args.unoptimized, args.integer_arithmetic)

if __name__ == "__main__":
    main()
