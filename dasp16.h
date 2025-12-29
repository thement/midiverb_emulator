enum {
    DramLength = 16*1024,
    ProgramLength = 256,
};

typedef struct {
    int address;
    uint8_t program[ProgramLength];
    int16_t dram[DramLength];
    int16_t acc;
    int memory_shift;
} Machine;

typedef struct {
    int16_t s[2];
} Sample;

void run_machine_tick(Machine *machine, int16_t input, Sample *output) {
    int acc = machine->acc;
    int address = machine->address;
    for (int pc = 0; pc < 128; pc++) {
        unsigned operation = machine->program[(2 * pc - machine->memory_shift - 1) & 0xff] >> 6;
        uint16_t offset_lo = machine->program[(2 * pc - machine->memory_shift + 0) & 0xff];
        uint16_t offset_hi = machine->program[(2 * pc - machine->memory_shift + 1) & 0xff] & 0x3f;
        uint16_t offset = (offset_hi << 8) | offset_lo;

        int16_t new_acc = acc;
        int16_t data, sgn;
        switch (operation) {
            case 0: // sumhlf
                data = machine->dram[address];
                sgn = data < 0 ? 1 : 0;
                new_acc = new_acc + (data >> 1) + sgn;
                break;
            case 1: // ldhlf
                data = machine->dram[address];
                sgn = data < 0 ? 1 : 0;
                new_acc = (data >> 1) + sgn;
                break;
            case 2: // strpos
                data = new_acc;
                sgn = data < 0 ? 1 : 0;
                machine->dram[address] = data;
                new_acc = new_acc + (data >> 1) + sgn;
                break;
            case 3: // strneg
                data = ~new_acc;
                sgn = data < 0 ? 1 : 0;
                machine->dram[address] = data;
                new_acc = (data >> 1) + sgn;
                break;
        }
        //printf("op=%d pc=%d addr=%08x data=%d acc=%d\n", operation, pc, machine->address, data, new_acc);

        // Handle special pc values for storing output.
        // Do not update accumulator at those places.
        if (pc == 0x60) {
            output->s[0] = data;
        } else if (pc == 0x70) {
            output->s[1] = data;
        } else if (pc == 0) {
            machine->dram[address] = input;
        } else {
            acc = new_acc;
        }

        address = (address + offset) % DramLength;
    }
    machine->acc = acc;
    machine->address = address;
    //printf("end addr=%d\n", address);
}

void reset_machine(Machine *machine) {
    memset(machine->dram, 0, sizeof(machine->dram));
    machine->acc = 0;
    machine->address = 0;
}
