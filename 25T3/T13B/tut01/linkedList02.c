#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *createList(struct node *list, int *array, int index, int size);
void viewList(struct node *list);
struct node *listDelete(struct node *list, int value);

int main(void) {
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    struct node *list = createList(NULL, array, 0, 5);

    // We have a list containing 0, 1, 2, 3, 4
    // List delete goes here
    list = listDelete(list, 1);

    // View List
    viewList(list);

    // We have a list containing 0, 2, 3, 4
    list = listDelete(list, 0);

    viewList(list);

    // We have a list containing 2, 3, 4
    list = listDelete(list, 2);
    list = listDelete(list, 3);
    list = listDelete(list, 4);
    list = listDelete(list, 5);

    viewList(list);
}

struct node *createList(struct node *list, int *array, int index, int size) {
    if (size == 0) return NULL;
    list = malloc(sizeof(struct node));
    list->value = array[index];
    list->next = createList(list, array, index + 1, size - 1);
    return list;
}

void viewList(struct node *list) {
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }
    printf("X\n");
}

struct node *listDelete(struct node *list, int value) {
	// Paste code here
}
	