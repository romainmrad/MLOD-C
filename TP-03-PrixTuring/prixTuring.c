/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct
{
	int16_t year;
	char name[100];
	char works[255];
} turingWinner;

int main(void)
{
	char filename[] = "turingWinners.csv";
	// char outputFilename[] = "out.csv";

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Code de l'erreur: %d\n", errno);
		if (errno == ENOENT)
		{
			printf("Le fichier n'existe pas");
		}
		else
		{
			printf("Code erreur inconnu");
		}
	}

	int i = 0;
	int fieldIndex = 0;
	int winnerIndex = 0;
	char buffer[1024];

	turingWinner winners[60];

	while (1)
	{
		int c = fgetc(file);

		if (c == EOF || c == '\n')
		{
			if (fieldIndex == 0)
			{
				break;
			}

			buffer[i] = '\n';

			switch (fieldIndex)
			{
			case 1:
				sscanf(buffer, "%hd", &winners[winnerIndex].year);
				break;
			case 2:
				strcpy(winners[winnerIndex].name, buffer);
				break;
			case 3:
				strcpy(winners[winnerIndex].works, buffer);
				break;
			}

			fieldIndex = 0;
			i = 0;
			winnerIndex++;

			if (c == EOF)
			{
				break;
			}
		}
		else if (c == ';')
		{
			buffer[i] = '\0';
			i = 0;
			fieldIndex++;
		}
		else
		{
			buffer[i++] = (char)c;
		}
	}

	fclose(file);

	for (int i = 0; i < winnerIndex; i++){
		printf("Year: %d\n", winners[i].year);
		printf("Name: %s\n", winners[i].name);
		printf("Works: %s\n", winners[i].works);
	}

	return EXIT_SUCCESS;
}
