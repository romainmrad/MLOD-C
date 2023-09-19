#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef u_int64_t TypeEntier;

TypeEntier factorial(TypeEntier n)
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
	u_int16_t n;
	printf("Input number : ");
	scanf("%hd", &n);
	printf("Factorielle de %i: %llu", n, factorial(n));
	return EXIT_SUCCESS;
}