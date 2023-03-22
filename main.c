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

    printf("*** simpletron v1 ***\n");
}

void dump(Cpu cpu)
{
    int i;
    int j;
    FILE *fptr;

    fptr = fopen("simpletron.dump", "w");

    fprintf(fptr, "REGISTERS:\n");
    fprintf(fptr, "accumulator          %+05d\n", cpu.accumulator);
    fprintf(fptr, "instructionCounter      %02d\n", cpu.instruction_counter);
    fprintf(fptr, "instructionRegister  %+05d\n", cpu.instruction_register);
    fprintf(fptr, "operationCode           %02d\n", cpu.op_code);
    fprintf(fptr, "operand                 %02d\n", cpu.operand);

    fprintf(fptr, "\nMEMORY:\n");
    fprintf(fptr, "   ");
    for (j = 0; j < 10; j++)
        fprintf(fptr, "%5d ", j);
    fprintf(fptr, "\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j == 0)
                fprintf(fptr, "%2d ", i * 10);
            fprintf(fptr, "%+05d ", cpu.memory[(i * 10) + j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}
