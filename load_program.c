#include "main.h"
#define SENTINEL -99999/* When the the program_loader reads this value it will stop reading instructions into memory.*/

void load_program(char *program_file, Cpu *cpu)
{
    int i;
    int read;
	int sentinel_found = 0; /*used as a bool*/
	FILE *fptr;

	fptr = fopen(program_file, "r");

	for (i =0; i < 100; i++)
	{ // load program
        fscanf(fptr, "%d", &read);
        if (read == SENTINEL)
		{
			sentinel_found = 1;
            break;
		}

		if (read < -9999 || read > 9999)
		{
			printf("load ERROR: line %d , Invalid input: input must be between 9999 and  -9999\n", i);
			fclose(fptr);
			exit(-1);
		}
		if (read == EOF)
		{

		}
        cpu->memory[i] = read;
	}
	if (!sentinel_found)
	{
			printf("ERROR: Reached end of file without encountering the sentinel -99999\n", i);
			fclose(fptr);
			exit(-1);
	}
	fclose(fptr);
	
}
