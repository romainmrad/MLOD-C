#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isPerfect(int n)
{
	int sumOfDivisors = 0;
	for (int i = 1; i < n; i++){
		if (n%i==0) {
			sumOfDivisors += i;
		}
	}
	return (sumOfDivisors == n);
}

void displayPerfectNumbers(int n){
	for (int i = 0; i < n; i++){
		if (isPerfect(i)){
			printf("%i est parfait\n", i);
		}
	}
}

int main (void)
{
	int n;
	printf("Input value : ");
	scanf("%d", &n);
	displayPerfectNumbers(n);
	return EXIT_SUCCESS;
}