#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod);

int main(int argc, char *argv[]) {
    int numDisks = atoi(argv[1]);
    char *fromRod = argv[2];
    char *toRod = argv[4];
    char *otherRod = argv[3];
    solveHanoi(numDisks, fromRod, toRod, otherRod);
}

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {
    // Add your code here
}
