#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

struct node *createList(struct node *list, int *array, int index, int size);
void viewList(struct node *list, int listIndex);
int listLength(struct node *l);
int listCountOdds(struct node *l);
bool listIsSorted(struct node *l);
bool listIsSortedImplemented();
struct node *listDelete(struct node *l, int value);

int main(void) {

    // Change the linked list elements
    int size = 6;
    int *array1 = malloc(size * sizeof(int));
    for (int i = 0; i < 6; i += 3) {
        array1[i] = i * 2;
        array1[i+1] = i * i + 1;
        array1[i+2] = i+2;
    }
    
    // Additional arrays
    int *array2 = malloc(size * sizeof(int));
    for (int i = 0; i < 6; i += 1) {
        array2[i] = i * 2;
    }

    int *array3 = malloc(size * sizeof(int));
    for (int i = 0; i < 6; i += 1) {
        array3[i] = 3;
    }
    //

    struct node *list1 = createList(NULL, array1, 0, size);
    struct node *list2 = createList(NULL, array2, 0, size);
    struct node *list3 = createList(NULL, array3, 0, size);


    // We have a list containing 0 -> 1 -> 2 -> 6 -> 10 -> 5 -> X
    // View List
    viewList(list1, 1);

    printf("List 1 Data\n");
    if (listLength(list1) != -1) {
        printf("Length: %d\n", listLength(list1));
    } else {
        printf("Length: not calculated\n");
    }

    if (listCountOdds(list1) != -1) {
        printf("Odd Count: %d\n", listCountOdds(list1));
    } else {
        printf("Odd Count: not calculated\n");
    }

    if (listIsSortedImplemented() == true) {
        if (listIsSorted(list1) == true) {
            printf("Odd Count: True\n");
        } else {
            printf("Odd Count: False\n");
        }
        printf("\n");

        viewList(list2, 2);
        if (listIsSorted(list3) == true) {
            printf("Odd Count: True\n");
        } else {
            printf("Odd Count: False\n");
        }

        printf("\n");
        viewList(list3, 3);
        if (listIsSorted(list3) == true) {
            printf("Odd Count: True\n");
        } else {
            printf("Odd Count: False\n");
        }
    } else {
        printf("List is sorted not implemented.\n\n");
    }

    printf("Deleting the element 0 from the list\n");
    list1 = listDelete(list1, 0);
    if (list1 == NULL) {
        printf("List value could not be deleted, no function\n");
    } else {
        viewList(list1, 1);
        printf("Deleting the element 2 from the list\n");
        list1 = listDelete(list1, 2);
        viewList(list1, 1);
        printf("Deleting the element 5 from the list\n");
        list1 = listDelete(list1, 5);
        viewList(list1, 1);
    }
}

struct node *createList(struct node *list, int *array, int index, int size) {
    if (size == 0) return NULL;
    list = malloc(sizeof(struct node));
    list->value = array[index];
    list->next = createList(list, array, index + 1, size - 1);
    return list;
}

void viewList(struct node *list, int listIndex) {
    printf("List %d: ", listIndex);
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }
    printf("X\n");
}

int listLength(struct node *l) {
	// Paste code in here.
    return -1;
}

int listCountOdds(struct node *l) {
	// Paste code in here.
    return -1;
}

bool listIsSortedImplemented() {
    // Change to true when implemented
    return false;
}

bool listIsSorted(struct node *l) {
    // Paste the code here
    return false;
}

struct node *listDelete(struct node *l, int value) { 
    // Paste the code here
    return NULL;
}

