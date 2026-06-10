#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool hasTwoSum(int a[], int n, int v);

int main(int argc, char *argv[]) {
	int *a = malloc(sizeof(int) * atoi(argv[1]));
	for (int i = 0; i < atoi(argv[1]); i++) {
		scanf("%d", &a[i]);
	}

	if (hasTwoSum(a, atoi(argv[1]), atoi(argv[2]))) {
		printf("True\n");
	} else {
		printf("False\n");
	}
}

static bool hasTwoSum(int a[], int n, int v) {
	// Code here;
	return false;
}