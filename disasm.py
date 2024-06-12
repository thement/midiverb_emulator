import sys
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

def disassemble_dsp(byte_list, prog):
    def decode_instruction(pc, op, byte1, byte2, address):
        # Extract address bits
        a7_a0 = byte1
        a13_a8 = byte2 & 0x3F
        offset = (a13_a8 << 8) | a7_a0

        # Determine the instruction
        if op == 0b00:
            instruction = f"sumhlf 0x{address:04x}"
            data = f"DRAM[0x{address:04x}]"
            comment = f"Acc = Acc + {data}/2 + sgn"
        elif op == 0b01:
            instruction = f"ldhlf 0x{address:04x}"
            data = f"DRAM[0x{address:04x}]"
            comment = f"Acc = {data}/2 + sgn"
        elif op == 0b10:
            instruction = f"strpos 0x{address:04x}"
            data = "Acc"
            comment = f"DRAM[0x{address:04x}] = {data}, Acc = Acc + {data}/2 + sgn"
        elif op == 0b11:
            data = "~Acc"
            instruction = f"strneg 0x{address:04x}"
            comment = f"DRAM[0x{address:04x}] = {data}, Acc = {data}/2 + sgn"
        else:
            instruction = "unknown"
            comment = ""

        if pc == 0x00:
            if op == 0b00:
                comment = f"DRAM[0x{address:04x}] = Input, Acc = Acc + Input/2 + sgn"
            else:
                comment = f"DRAM[0x{address:04x}] = Input, Acc = Input/2 + sgn"
        elif pc == 0x60:
            comment = f'Left = {data}'
        elif pc == 0x70:
            comment = f'Right = {data}'

        return f"P{prog}: {pc:02x} {op} {byte2:02x}{byte1:02x}  {instruction}\t\t{comment}", (address + offset) & 0x3fff
        #return f"{pc:02x} {byte2:02x}{byte1:02x}  {instruction}\t\t{comment}", (address + offset) & 0x3fff

    # Ensure the byte list length is even
    if len(byte_list) % 2 != 0:
        raise ValueError("The byte list length must be even.")

    disassembled_instructions = []

    # Iterate over the byte list in pairs
    address = 0
    for pc in range(0, 128):
        # Extract operation bits
        i = (pc + 126) % 128 * 2
        op = (byte_list[i+1] >> 6) & 0x03
        j = (pc + 127) % 128 * 2
        byte1 = byte_list[j]
        byte2 = byte_list[j+1]
        instruction, address = decode_instruction(pc, op, byte1, byte2, address)
        disassembled_instructions.append(instruction)

    print(f'end offset 0x{address:x}')

    return disassembled_instructions

def read_256_bytes_at_offset(file_path, n):
    offset = n * 256
    with open(file_path, 'rb') as file:
        file.seek(offset)  # Move the file pointer to the offset
        byte_data = file.read(256)  # Read the 256 bytes at the specified offset

    # Convert the byte data to a list of integers
    integer_list = list(byte_data)
    return integer_list

def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <filename> <program_number>")
        sys.exit(1)

    try:
        prog = int(sys.argv[2])
    except ValueError:
        print("Program number must be an integer.")
        sys.exit(1)
    if prog < 1 or prog > 64:
        print("Program number must be from range 1-64.")
        sys.exit(1)

    byte_list = read_256_bytes_at_offset(sys.argv[1], prog - 1)

    disassembled_instructions = disassemble_dsp(byte_list, prog)
    for instr in disassembled_instructions:
        print(instr)

if __name__ == "__main__":
    main()
