#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *createList(struct node *list, int *array, int index, int size);
int sumListWhile(struct node *list);
int sumListFor(struct node *list);


int main(void) {
    // Creates a list with numbers 0, 1, 2, 3, 4.
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    struct node *list = createList(NULL, array, 0, 5);

    // Prints the while loop and for loop output
    printf("While Loop %d\n", sumListWhile(list));
    printf("For Loop %d\n", sumListFor(list));
    return 0;
}

struct node *createList(struct node *list, int *array, int index, int size) {
    if (size == 0) return NULL;
    list = malloc(sizeof(struct node));
    list->value = array[index];
    list->next = createList(list, array, index + 1, size - 1);
    return list;
}

int sumListWhile(struct node *list) {
    // While goes here
    return 0;
}

int sumListFor(struct node *list) {
    // For goes here
    return 0;
}