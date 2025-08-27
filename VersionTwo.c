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

int main() {
    ListPtr L = initialize();


    return 0;
}

ListPtr initialize() {
    ListPtr retval = (ListPtr)malloc(sizeof(List));
    if (retval != NULL) {
        retval->count = 0;
    }
    return retval;
}