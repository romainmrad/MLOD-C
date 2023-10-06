// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e)
{
	printf("%s", (char *)e);
}

void detruireElement(Element e)
{
}

bool equalsElement(Element e1, Element e2)
{
	return (e1 == e2);
}

int main(void)
{
	Liste l;

	l = NULL;
	printf("estVide(l) = %s\n", estVide(l) ? "TRUE" : "FALSE");

	l = ajoutTete("d", l);
	l = ajoutTete("l", l);
	l = ajoutTete("r", l);
	l = ajoutTete("o", l);
	l = ajoutTete("W", l);
	l = ajoutTete(" ", l);
	l = ajoutTete("o", l);
	l = ajoutTete("l", l);
	l = ajoutTete("l", l);
	l = ajoutTete("e", l);
	l = ajoutTete("H", l);

	afficheListe_i(l);

	detruire_i(l);

	return EXIT_SUCCESS;
}