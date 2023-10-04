#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l)
{
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v)
{
	Liste res = malloc(sizeof(Cellule));
	res->val = v;
	res->suiv = NULL;
	return res;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l)
{
	Liste res = creer(v);
	res->suiv = l;
	return res;
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l)
{
	Liste cell = l;
	while (!estVide(cell))
	{
		afficheElement(cell->val);
		cell = cell->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l)
{
	if (!estVide(l))
	{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else
	{
		printf("\n");
	}
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l)
{
	Liste current, next = l;
	while (!estVide(current))
	{
		next = current->suiv;
		detruireElement(current->val);
		free(current);
		current = next;
	}
}

// version récursive
void detruire_r(Liste l)
{
	if (!estVide(l))
	{
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l)
{
	if (estVide(l))
		return creer(v);

	Liste cell = l;
	while (!estVide(cell))
	{
		cell = cell->suiv;
	}
	cell->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l)
{
	if (estVide(l))
	{
		l = creer(v);
		return l;
	}
	l->suiv = ajoutFin_r(v, l->suiv);
	return l;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l)
{
	Liste cell = l;
	while (!estVide(cell) && !equalsElement(cell->val, v))
	{
		cell = cell->suiv;
	}
	return cell;
}

// version récursive
Liste cherche_r(Element v, Liste l)
{
	if (estVide(l) || estVide(l->suiv))
		return NULL;
	if (equalsElement(l->val, v))
		return l;
	return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l)
{
	Liste cell = l;
	Liste target = NULL;
	while (!estVide(cell))
	{
		if (equalsElement(cell->suiv->val, v))
		{
			target = cell;
			break;
		}
		cell = cell->suiv;
	}
	if (estVide(target))
		return l;
	detruireElement(target->suiv);
	target->suiv = target->suiv->suiv;
	return l;
}

// version recursive
Liste retirePremier_r(Element v, Liste l)
{
	if (estVide(l))
		return NULL;

	if(equalsElement(l->val, v)){
		Liste tmp = l->suiv;
		detruireElement(l);
		return tmp;
	}
	l->suiv = retirePremier_r(v, l->suiv);

	return l;
}

void afficheEnvers_r(Liste l)
{
	if (!estVide(l))
	{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}
