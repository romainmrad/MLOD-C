#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum Mois
{
    JANVIER,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
};

struct Date
{
    int jour;
    enum Mois mois;
    int annee;
};

void initialiseDate(struct Date *d)
{
    printf("Veuillez saisir une date");
}

int main(void)
{
    struct Date d;
    return EXIT_SUCCESS;
}