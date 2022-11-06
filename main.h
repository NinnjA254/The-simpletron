#include <stdio.h>

typedef struct Cpu
{
    int memory[100];
    int accumulator;
    int instruction_counter;
    int instruction_register;
    int op_code;
    int operand;
} Cpu;

void dump(Cpu);
void init(Cpu *);
void welcome();