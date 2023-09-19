#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

bool isPerfect(u_int16_t n)
{
	u_int32_t sumOfDivisors = 0;
	for (u_int16_t i = 1; i < n; i++){
		if (n%i==0) {
			sumOfDivisors += i;
		}
	}
	return (sumOfDivisors == n);
}

void displayPerfectNumbers(u_int16_t n){
	for (u_int16_t i = 0; i < n; i++){
		if (isPerfect(i)){
			printf("%i est parfait\n", i);
		}
	}
}

int main (void)
{
	u_int32_t n;
	printf("Input value : ");
	scanf("%d", &n);
	displayPerfectNumbers(n);
	return EXIT_SUCCESS;
}