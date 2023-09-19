#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef short TypeEntier;

TypeEntier factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main(void)
{
	int n;
	printf("Input number : ");
	scanf("%d", &n);
	printf("Factorielle de %i: %d", n, factorial(n));
	return EXIT_SUCCESS;
}