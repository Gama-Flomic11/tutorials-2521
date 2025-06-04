#include <stdio.h>

int main(void) {
	int a = 5; 
 	int b = 123;

	int *pa = &a;
	int *pb = &b;

	*pa = 6;
	*pb = 234;

	int c = *pa;
	*pa = *pb;
	*pb = c;

	pa = pb;
	*pa = 345;

    printf("%d %d %d\n", a, b, c);
}