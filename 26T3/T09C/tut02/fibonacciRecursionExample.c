#include <stdio.h>
#include <stdlib.h>

long findFibonacci(int number);

int main (int argc, char *argv[]) {
    printf("%ld\n", findFibonacci(atoi(argv[1])));
}

long findFibonacci(int number) {
	// Base case
	if (number == 1) {
		return 0;
	// Recursive case
	} else if (number == 2) {
		return 1;
	// Recursive case
	} else {
		return findFibonacci(number - 1) + findFibonacci(number - 2);
	}
}	