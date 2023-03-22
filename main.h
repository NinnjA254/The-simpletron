#ifndef __SIMPLETRON__
#define __SIMPLETRON__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void load_program(char *, Cpu *);
void execute(Cpu *);

#endif
