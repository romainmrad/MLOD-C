#include "echangeContenu.h"

void echangeContenu(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}