#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROD_SIZE 4
#define SIZE 5

struct node {
	int value;
	struct node *next;
};

void rodAdd(int *rod, int nodeNumber);
void printPegs(int *firstRod, int *secondRod, int *thirdRod);

int main(int argc, char *argv[]) {
    char character;
    while (true) {
        int *firstRod = calloc(sizeof(int), (ROD_SIZE + 1));
        int *secondRod = calloc(sizeof(int), (ROD_SIZE + 1));
        int *thirdRod = calloc(sizeof(int), (ROD_SIZE + 1));

        for (int i = 0; i < ROD_SIZE; i++) {
            char node;
            scanf(" %c", &node);
            if (node == 'f') {
                rodAdd(firstRod, i);
            } else if (node == 's') {
                rodAdd(secondRod, i);
            } else {
                rodAdd(thirdRod, i);
            }
        }
        printPegs(firstRod, secondRod, thirdRod);


        free(firstRod);
        free(secondRod);
        free(thirdRod);
    }
}

void rodAdd(int *rod, int nodeNumber) {
    int i = 0;
    while (rod[i]) {
        i++;
    }
    rod[i] = nodeNumber + 1;
}

void printPegs(int *firstRod, int *secondRod, int *thirdRod) {
    int i = 0;
    int j = 0;
    int k = 0;
    int currentValue = 1;

    while (firstRod[i] || secondRod[j] || thirdRod[k]) {
        if (firstRod[i] == currentValue) {
            int l = 0;
            while (SIZE * 2 + 3 - l > 0) {
                if (SIZE * 2 + 3 - l > SIZE - currentValue && SIZE * 2 + 3 - l < SIZE + 2 + currentValue) {
                    if (SIZE * 2 + 3 - l == SIZE + 1) {
                        printf("|");
                    } else {
                        printf("-");
                    }
                } else {
                    printf(" ");
                }
                l++;
            }

            printf("       |       ");
            printf("      |      \n");
            i++;
        } else if (secondRod[j] == currentValue) {
            int l = 1;

            printf("       |      ");
            while (SIZE * 2 + 3 - l > 0) {
                if (SIZE * 2 + 3 - l > SIZE - currentValue && SIZE * 2 + 3 - l < SIZE + 2 + currentValue) {
                    if (SIZE * 2 + 3 - l == SIZE + 1) {
                        printf("|");
                    } else {
                        printf("-");
                    }
                } else {
                    printf(" ");
                }
                l++;
            }
            printf("        |       \n");
            j++;
        } else {
            int l = 1;
            
            printf("       |      ");
            printf("      |       ");

            
            while (SIZE * 2 + 3 - l > 0) {
                if (SIZE * 2 + 3 - l > SIZE - currentValue && SIZE * 2 + 3 - l < SIZE + 2 + currentValue) {
                    if (SIZE * 2 + 3 - l == SIZE + 1) {
                        printf("|");
                    } else {
                        printf("-");
                    }
                } else {
                    printf(" ");
                }
                l++;
            }
            printf("\n");
            k++;
        }
        currentValue++;
    }
}