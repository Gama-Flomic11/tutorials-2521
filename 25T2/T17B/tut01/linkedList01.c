#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *createList(struct node *list, int *array, int index, int size);
int sumList(struct node *list);

int main(void) {
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    struct node *list = createList(NULL, array, 0, 5);
    printf("%d\n", sumList(list));
}

struct node *createList(struct node *list, int *array, int index, int size) {
    if (size == 0) return NULL;
    list = malloc(sizeof(struct node));
    list->value = array[index];
    list->next = createList(list, array, index + 1, size - 1);
    return list;
}

int sumList(struct node *list) {
    // This is the code we added
	int sum = 0;
	while (list != NULL) {
		sum += list->value;
        list = list->next;
	}
}