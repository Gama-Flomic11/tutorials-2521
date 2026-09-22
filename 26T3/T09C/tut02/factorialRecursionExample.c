#include <stdio.h>
#include <stdlib.h>

long findFactorial(int number);

int main (int argc, char *argv[]) {
    printf("%ld\n", findFactorial(atoi(argv[1])));
}

long findFactorial(int number) {
	// Base case
	if (number == 0) {
		return 1;
	// Recursive case
	} else {
		return findFactorial(number - 1) * number;
	}
}	