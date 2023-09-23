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
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
	int16_t year;
	char name[100];
	char works[1024];
} turingWinner;

uint16_t numberOfWinners(char filename[])
{
	FILE *file = fopen(filename, "r");
	int n = 0;
	if (file == NULL)
	{
		printf("Code de l'erreur: %d\n", errno);
		if (errno == ENOENT)
		{
			printf("Le fichier n'existe pas");
			return EXIT_FAILURE;
		}
		else
		{
			printf("Code erreur inconnu");
			return EXIT_FAILURE;
		}
	}
	char c;
	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			n++;
	}
	fclose(file);
	return n;
}

turingWinner *readWinners(char filename[], uint16_t nWinners)
{
	turingWinner *winners = (turingWinner *)malloc(nWinners * sizeof(turingWinner));

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

	char c;
	int fieldIndex = 0;
	int winnerIndex = 0;
	int bufferIndex = 0;
	char buffer[1024];

	while (((c = fgetc(file)) != EOF))
	{
		if (c == ';')
		{
			buffer[bufferIndex] = '\0';
			switch (fieldIndex)
			{
			case 0:
				winners[winnerIndex].year = atoi(buffer);
				break;

			case 1:
				strcpy(winners[winnerIndex].name, buffer);
				break;
			}
			bufferIndex = 0;
			memset(buffer, 0, sizeof(buffer));
			fieldIndex++;
		}
		else if (c == '\n')
		{
			strcpy(winners[winnerIndex].works, buffer);
			buffer[bufferIndex] = '\0';
			bufferIndex = 0;
			memset(buffer, 0, sizeof(buffer));
			winnerIndex++;
			fieldIndex = 0;
		}
		else
		{
			buffer[bufferIndex++] = c;
		}
	}

	fclose(file);
	return winners;
}

void printWinners(turingWinner *winners, char outputFilename[], uint16_t nWinners)
{
	FILE *file = fopen(outputFilename, "w");
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
	for (int i = 0; i < nWinners; i++)
	{
		fprintf(file, "%d;%s;%s\n", winners[i].year, winners[i].name, winners[i].works);
	}
	fclose(file);
}

void infoAnnee(turingWinner *winners, uint16_t year)
{
	int i = 0;
	while (winners[i].year != 0)
	{
		if (winners[i].year == year)
		{
			printf("L'annee %d, le(s) gagnant(s) ont ete : %s\n", winners[i].year, winners[i].name);
			printf("Nature des travaux : %s", winners[i].works);
			break;
		}
		i++;
	}
}

void sortTuringWinners(turingWinner *winners, uint16_t nWinners)
{
	bool swapped = false;
	for (int i = 0; i < nWinners - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < nWinners - 1; j++)
		{
			if (winners[j].year > winners[j + 1].year)
			{
				turingWinner temp = winners[j];
				winners[j] = winners[j + 1];
				winners[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

/**
 * Possible command line executions : 
 * 
 * ./prixTuring -o turingWinners.csv out.csv
 * 
 * ./prixTuring --info -o turingWinners.csv 2007
 * 
 * ./prixTuring --sort -o turingWinners.csv sortedWinners.csv
*/


int main(int argc, char *argv[])
{
	bool sort = false;
	bool info = false;
	// Reading input and output files from command line
	char *filename = argv[argc - 2];
	char *outputFilename = argv[argc - 1];
	// If option sort is passed
	if (strcmp(argv[1], "--sort") == 0)
	{
		// Check for number of arguments
		if (argc != 5){
			printf("Usage: %s --sort -o input_file sorted_file\n", argv[0]);
			return EXIT_FAILURE;
		}
		// Turn on sort flag
		sort = true;
	} else if (strcmp(argv[1], "--info") == 0){
		// Check for number of arguments
		if (argc != 5){
			printf("Usage: %s --info -o input_file year_info\n", argv[0]);
			return EXIT_FAILURE;
		}
		// Turn on info flag
		info = true;
	} else {
		// Check for number of arguments
		if (argc != 4){
			printf("Usage: %s -o input_file output_file\n", argv[0]);
			return EXIT_FAILURE;
		}
	}
	// Reading csv file
	uint16_t nWinners = numberOfWinners(filename);
	turingWinner *winners = readWinners(filename, nWinners);
	if (sort){
		// Sorting and printing in new file
		sortTuringWinners(winners, nWinners);
	} else if (info){
		// Getting info about year
		infoAnnee(winners, atoi(argv[argc - 1]));
	}
	// Printing in output file
	printWinners(winners, outputFilename, nWinners);
	return EXIT_SUCCESS;
}
