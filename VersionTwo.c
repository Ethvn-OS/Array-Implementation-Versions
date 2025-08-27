/* ******************************************************************************
*                                                                                *
*    This program demonstrates the 2nd version of array implementation of List   *
*    (ListPtr points to a List)                                                  *
*                                                                                *
*    Programmer: Ethan Andre O. Dalocanog                                        *
*    Date Created: August 27, 2025                                               *
*                                                                                *
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
} List, *ListPtr;

ListPtr initialize();
void printList(ListPtr A);
void bubbleSort(ListPtr A);
void selectionSort(ListPtr A);
void insert(ListPtr A, char elem, int pos);
void delete(ListPtr A, char elem);

int main() {
    ListPtr L = initialize();
    L->elem[0] = 'b';
    L->elem[1] = 'd';
    L->elem[2] = 'a';
    L->elem[3] = 'c';
    L->count = 4;

    printf("Elements of the list:\n");
    printList(L);

    selectionSort(L);

    printf("\nSorted List:\n");
    printList(L);

    insert(L,'x',3);

    printf("\nList after insertion:\n");
    printList(L);

    delete(L,'e');

    printf("\nList after deletion:\n");
    printList(L);

    return 0;
}

//initializes the list
ListPtr initialize() {
    ListPtr retval = (ListPtr)malloc(sizeof(List));
    if (retval != NULL) {
        retval->count = 0;
    }
    return retval;
}

//prints the list
void printList(ListPtr A) {
    int ctr;
    for (ctr = 0; ctr < A->count; ctr++) {
        printf("Data %d: %c\n", ctr+1, A->elem[ctr]);
    }
}

//this will sort the list in ascending order using bubble sort
void bubbleSort(ListPtr A) {
    int ctr, ndx;
    int temp = A->count - 1;
    for (ctr = 0; ctr < temp; ctr++) {
        for (ndx = 0; ndx < A->count - ctr - 1; ndx++) {
            if (A->elem[ndx] > A->elem[ndx+1]) {
                int spot = A->elem[ndx];
                A->elem[ndx] = A->elem[ndx+1];
                A->elem[ndx+1] = spot;
            }
        }
    }
}

//this will sort the list in ascending order using selection sort
void selectionSort(ListPtr A) {
    int ctr, ndx;
    int temp = A->count - 1;

    for (ctr = 0; ctr < temp; ctr++) {
        int smallestNdx = ctr;
        for (ndx = ctr+1; ndx < A->count; ndx++) {
            if (A->elem[ndx] < A->elem[smallestNdx]) {
                smallestNdx = ndx;
            }
        }
        if (smallestNdx != ctr) {
            int spot = A->elem[smallestNdx];
            A->elem[smallestNdx] = A->elem[ctr];
            A->elem[ctr] = spot;
        }
    }
}

//this will insert an element at any position of the list, as long as it is valid and there is still space
void insert(ListPtr A, char elem, int pos) {
    if (A->count < MAX) {
        if (pos > 0 && pos <= A->count+1) {
            int spot = pos - 1;
            int ctr;
            for (ctr = A->count++; ctr > spot; ctr--) {
                A->elem[ctr] = A->elem[ctr-1];
            }
            A->elem[ctr] = elem;
        } else {
            printf("\nInvalid position!\n");
        }
    } else {
        printf("\nArray is full!\n");
    }
}

//this function will delete an element in the list
void delete(ListPtr A, char elem) {
    int ctr;
    for (ctr = 0; ctr < A->count && A->elem[ctr] != elem; ctr++) {}
    if (ctr < A->count) {
        A->count--;
        for (; ctr < A->count; ctr++) {
            A->elem[ctr] = A->elem[ctr+1];
        }
    } else {
        printf("\nElement does not exist!\n");
    }
}