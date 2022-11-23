#include "main.h"
void load_program(char *program_file, Cpu *cpu)
{
    int i;
    int read;
    for (i = 0; i < 100; i++)
    { // load program
        printf("%02d ? ", i);
        scanf("%d", &read);
        if (read == -99999)
            break;

		if (read < -9999 || read > 9999)
		{
			printf("Invalid input: input must be between 9999 and  -9999\n", i);
			printf("%02d ? ", i);
			scanf("%d", &read);
		}
        cpu->memory[i] = read;
    }
}
