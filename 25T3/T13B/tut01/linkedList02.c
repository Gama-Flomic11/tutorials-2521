// To run copy and use
// clang linkedList02.c -o linkedList02 
// ./linkedList02

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
	// Case 1: List is empty
	if (list == NULL) {
		return NULL;
		
	// Case 2: First element
	} else if (list->value == value) {
		struct node *newHead = list->next;
		free(list);
		return newHead;
		
	// Case 3: Middle Value
	} else {
		struct node *curr = list;
		while (curr->next != NULL) {
			if (curr->next->value == value) {
					struct node *toDelete = curr->next;
		      curr->next = toDelete->next;
	        free(toDelete);
	        break;
	    }
	    curr = curr->next;
	  }
    return list;
  }
}
	