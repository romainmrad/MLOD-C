#include <stdbool.h>
#include "dates.h"
#include <stdlib.h>
#include <stdio.h>

void initialiseDate(Date *d)
{
    printf("\nVeuillez saisir un numero de jour : ");
    scanf("%d", &d->jour);
    printf("Veuillez saisir un mois : ");
    scanf("%d", &d->mois);
    printf("Veuillez saisir une année : ");
    scanf("%d", &d->annee);
}

Date creerDateParCopie(void)
{
    Date d;
    printf("\nVeuillez saisir un numero de jour : ");
    scanf("%d", &d.jour);
    printf("Veuillez saisir un mois : ");
    scanf("%d", &d.mois);
    printf("Veuillez saisir une année : ");
    scanf("%d", &d.annee);
    return d;
}

Date *newDate()
{
    Date *d = NULL;
    d = malloc(sizeof(*d));
    return d;
}

void afficheDate(Date *d)
{
    printf("\nLa Date est : %d/%d/%d\n", d->jour, d->mois, d->annee);
}

unsigned int nbreJours(Mois mois, unsigned int annee)
{
    if (mois >= JANVIER && mois <= DECEMBRE)
    {
        switch (mois)
        {
        case JANVIER:
            return 31;
        case FEVRIER:
            if (annee % 4 == 0)
                return 29;
            return 28;
        case MARS:
            return 31;
        case AVRIL:
            return 30;
        case MAI:
            return 31;
        case JUIN:
            return 30;
        case JUILLET:
            return 31;
        case AOUT:
            return 31;
        case SEPTEMBRE:
            return 30;
        case OCTOBRE:
            return 31;
        case NOVEMBRE:
            return 30;
        case DECEMBRE:
            return 31;
        }
    }
    return 0;
}

bool dateValide(Date uneDate)
{
    return ((uneDate.jour >= 0 && uneDate.jour <= nbreJours(uneDate.mois, uneDate.annee)) &&
            (uneDate.mois >= JANVIER && uneDate.mois <= DECEMBRE));
}

unsigned int jourDansAnnee(Date uneDate)
{
    unsigned int numero = uneDate.jour;
    if (uneDate.mois > JANVIER)
    {
        for (Mois i = JANVIER; i < uneDate.mois; i++)
            numero += nbreJours(i, uneDate.annee);
    }
    return numero;
}
