#pragma once
#include <stdbool.h>

typedef enum
{
    JANVIER = 1,
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
} Mois;

typedef struct
{
    unsigned int jour;
    Mois mois;
    unsigned int annee;
} Date;

void initialiseDate(Date *d);

Date creerDateParCopie(void);

Date *newDate();

void afficheDate(Date *d);

unsigned int nbreJours(Mois mois, unsigned int annee);

bool dateValide(Date uneDate);

unsigned int jourDansAnnee(Date uneDate);