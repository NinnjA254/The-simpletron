#include "main.h"
/**
 * i/o operations
 */
#define READ 10
#define WRITE 11

/**
 * load/store operations
 */
#define LOAD 20
#define STORE 21

/**
 * arithmetic operations
 */
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

/**
 * transfer of control operations
 */
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42

#define HALT 43

void execute(Cpu *cpu)
{
	int done = 0; 

	printf("*** Program execution begins ***\n");
	while (done == 0)
	{
		cpu->instruction_register = cpu->memory[cpu->instruction_counter];
		cpu->op_code = cpu->instruction_register / 100;
		cpu->operand = cpu->instruction_register % 100;
		cpu->instruction_counter++;

		switch (cpu->op_code)
		{
		case READ:
			printf("? ");
			scanf("%d", &(cpu->memory[cpu->operand]));
			break;
		case WRITE:
			printf("%d\n", cpu->memory[cpu->operand]);
			break;
		case LOAD:
			cpu->accumulator = cpu->memory[cpu->operand];
			break;
		case STORE:
			cpu->memory[cpu->operand] = cpu->accumulator;
			break;
		case ADD:
			cpu->accumulator += cpu->memory[cpu->operand];
			break;
		case SUBTRACT:
			cpu->accumulator -= cpu->memory[cpu->operand];
			break;
		case DIVIDE:
			if (cpu->memory[cpu->operand] == 0)
			{
				printf("*** Attempt to divide by zero ***\n");
				done = -1;
				break;
			}
			cpu->accumulator /= cpu->memory[cpu->operand];
			break;
		case MULTIPLY:
			cpu->accumulator *= cpu->memory[cpu->operand];
			break;
		case BRANCH:
			cpu->instruction_counter = cpu->operand;
			break;
		case BRANCHNEG:
			if (cpu->accumulator < 0)
				cpu->instruction_counter = cpu->operand;
			break;
		case BRANCHZERO:
			if (cpu->accumulator == 0)
				cpu->instruction_counter = cpu->operand;
			break;
		case HALT:
			done = 1;
			break;
		default:
			printf("*** Unrecognised operation code at: memory[%d] ***\n", cpu->instruction_counter - 1); 
			done = -1;
			break;
		}
	}
	if (done == 1)
		printf("*** Simpletron execution terminated ***\n");
	else if (done == -1)
		printf("*** Simpletron execution abnormally terminated ***\n");
}
