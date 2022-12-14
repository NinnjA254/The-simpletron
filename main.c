#include "main.h"

int main(int argc, char **argv)
{
    Cpu cpu;

	if (argc  != 2)
	{
		printf("usage, %s SML program file name\n", argv[0]);
		return (-1);
	}
    init(&cpu);
    load_program(argv[1], &cpu);

    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins ***\n");

    execute(&cpu);
    dump(cpu);

    return (0);
}


void init(Cpu *cpu)
{
    int i = 0;

    while (i < 100)
    {
        cpu->memory[i] = 0;
        i++;
    }
    cpu->accumulator = 0;
    cpu->instruction_counter = 0;
    cpu->instruction_register = 0;
    cpu->op_code = 0;
    cpu->operand = 0;

    printf("*** Welcome to the simpletron! ***\n");
    printf("*** Please enter your program one instruction ***\n");
    printf("*** (or data word) at a time. I will type the ***\n");
    printf("*** location number and question mark (?) ***\n");
    printf("*** You then type the word for that location. ***\n");
    printf("*** Type the sentinel -99999 to stop entering ***\n");
    printf("*** your program ***\n");
}

void dump(Cpu cpu)
{
    int i;
    int j;

    printf("REGISTERS:\n");
    printf("accumulator          %+05d\n", cpu.accumulator);
    printf("instructionCounter      %02d\n", cpu.instruction_counter);
    printf("instructionRegister  %+05d\n", cpu.instruction_register);
    printf("operationCode           %02d\n", cpu.op_code);
    printf("operand                 %02d\n", cpu.operand);

    printf("\nMEMORY:\n");
    printf("   ");
    for (j = 0; j < 10; j++)
        printf("%5d ", j);
    printf("\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j == 0)
                printf("%2d ", i * 10);
            printf("%+05d ", cpu.memory[(i * 10) + j]);
        }
        printf("\n");
    }
}


