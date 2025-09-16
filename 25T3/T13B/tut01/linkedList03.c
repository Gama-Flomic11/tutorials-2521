// To run copy and use
// clang linkedList03.c -o linkedList03 
// ./linkedList03

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

struct node *createList(struct node *list, int *array, int index, int size);
void viewList(struct node *list);
void listDelete(struct list *list, int value);

int main(void) {
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    struct node *head = createList(NULL, array, 0, 5);

    // Notice now needs to set the head
    struct list *list = malloc(sizeof(struct list));
    list->head = head;

    viewList(list->head);


    // We have a list containing 0, 1, 2, 3, 4
    // List delete goes here
    listDelete(list, 1);

    // View List
    viewList(list->head);

    // We have a list containing 0, 2, 3, 4
    listDelete(list, 0);

    viewList(list->head);

    // We have a list containing 2, 3, 4
    listDelete(list, 2);
    listDelete(list, 3);
    listDelete(list, 4);
    listDelete(list, 5);

    viewList(list->head);
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

void listDelete(struct list *list, int value) {
	// Case 1: List is empty
	if (list == NULL || list->head == NULL) {
        return;
    }
    // Case 2: First Value
	if (list->head->value == value) {
        struct node *tmp = list->head;
		list->head = list->head->next;
		free(tmp);
        return;		
	// Case 3: Middle Value
	} else {
		struct node *curr = list->head;
		while (curr->next != NULL) {
			if (curr->next->value == value) {
					struct node *toDelete = curr->next;
		      curr->next = toDelete->next;
	        free(toDelete);
	        break;
	    }
	    curr = curr->next;
	  }
  }
}
	