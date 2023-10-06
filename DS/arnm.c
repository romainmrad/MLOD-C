// =========
// Romain MRAD
// gcc -W -Wall -std=c99 arnm.c -o arnm
// =========

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct
{
	uint32_t index;
	uint32_t distance;
} Difference;

// =============
// = Fonctions =
// =============

bool isNucleotide(char c)
{
	return (c == NUCLEOTIDES[0] || c == NUCLEOTIDES[1] || c == NUCLEOTIDES[2] || c == NUCLEOTIDES[3]);
}

int indexOf(char nucleotide)
{
	switch (nucleotide)
	{
	case 'A':
		return 0;
	case 'T':
		return 1;
	case 'C':
		return 2;
	case 'G':
		return 3;
	default:
		return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2)
{
	return indexOf(n1) - indexOf(n2);
}

float *statistics(char *sequence)
{
	float *res = malloc(sizeof(float));
	for (int k = 0; k < 4; k++)
	{
		res[k] = 0;
	}
	int i = 0;
	while (sequence[i] != '\0')
	{
		if (isNucleotide(sequence[i]))
		{
			res[indexOf(sequence[i])]++;
			i++;
		}
	}
	for (int k = 0; k < 4; k++)
	{
		res[k] = res[k] / (i)*100;
	}
	return res;
}

Difference **computeDifferenceBetween(char *seqA, char *seqB)
{
	if (strlen(seqA) != strlen(seqB))
		return NULL;

	Difference **differences = NULL;
	int i = 0;
	int nDiff = 0;

	while (seqA[i] != '\0')
	{
		if (seqA[i] != seqB[i])
		{
			Difference *ptr = malloc(sizeof(Difference));
			ptr->index = i;
			ptr->distance = distanceBetweenNucleotides(seqA[i], seqB[i]);
			nDiff++;
			differences = realloc(differences, sizeof(Difference *) * nDiff);
			differences[nDiff - 1] = ptr;
		}
		i++;
	}
	return differences;
}

void printDifferences(Difference **differences)
{
	if (differences == NULL)
		printf("No differences found");
	else
	{
		printf("Differences: ");
		int i = 0;
		while (differences[i] != NULL)
		{
			printf("<%i,%i> ", differences[i]->index, differences[i]->distance);
			i++;
		}
	}
}

// ========
// = Main =
// ========

int main(void)
{

	printf("Test de statistics avec sequenceDeNulceotides\n");
	char sequenceDeNucleotides[] = "ATGCATCCATCATGCATGTA";
	float *stats = statistics(sequenceDeNucleotides);
	for (int i = 0; i < 4; i++)
	{
		printf("%c : %f \n", NUCLEOTIDES[i], stats[i]);
	}

	printf("\n\nTest de computeDifferenceBetween et printDifferences\n");
	Difference **differences = computeDifferenceBetween(code_proteine_spike_pfizer, code_proteine_spike_moderna);
	printDifferences(differences);

	return EXIT_SUCCESS;
}

/*
Il manque une fonction qui permet de detruire un element de notre liste de differences
afin de pouvoir liberer tout l'espace mémoire allouer en fin d'execution.
*/