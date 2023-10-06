#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a)
{
	return (a == NULL);
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire *a)
{
	*a == NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e)
{
	ArbreBinaire res = malloc(sizeof(Noeud));
	res->val = e;
	initialiser(&res->filsDroit);
	initialiser(&res->filsGauche);
	return res;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e)
{
	ArbreBinaire p = a;
	while (!estVide(p))
	{
		if (e > p->val)
			p = p->filsDroit;
		else if (e < p->val)
			p = p->filsGauche;
		else
			return a;
	}
	p->val = creer(e);
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e)
{
	if (estVide(a))
		a->val = creer(e);
	else
	{
		if (e > a->val)
			a->filsDroit = insere_r(a->filsDroit, e);
		else if (e < a->val)
			a->filsGauche = insere_r(a->filsGauche, e);
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
	return !estVide(a) ? 1 + nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche) : 0;
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
	ArbreBinaire p = a;
	int counter = 1;
	while (!estVide(p))
	{
		if (e > p->val)
		{
			counter++;
			p = p->filsDroit;
		}
		else if (e < p->val)
		{
			counter++;
			p = p->filsGauche;
		}
		else
		{
			return counter;
		}
	}
	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	if (estVide(a))
		return 0;
	else
	{
		int gauche = hauteur(a->filsGauche);
		int droite = hauteur(a->filsDroit);
		return 1 + (gauche > droite) ? gauche : droite;
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{
	if (estVide(a))
		return NULL;
	else if (a->filsDroit->val == elem || a->filsGauche->val == elem)
		return a;
	else
	{
		if (elem > a->val)
			return pere(a->filsDroit, elem);
		else if (elem < a->val)
			return pere(a->filsGauche, elem);
	}
}

void afficheRGD_r(ArbreBinaire a)
{
	while(!estVide(a)){
		printf("%i ", a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a)
{
	while(!estVide(a)){
		afficheGRD_r(a->filsGauche);
		printf("%i ", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a)
{
	while(!estVide(a)){
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%i ", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	return NULL;
}

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{

	return NULL;
}

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a)
{
}
