#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "TX_Anytype.h"
#include "TX_List.h"
#include "TX_Sort.h"

void showList(int *l, size_t length){
    for(size_t i=0;i<length;i++){
        printf("%u:%u\n",(unsigned int)i,(unsigned int)l[i]);
    }
}

bool Test_TX_Sort(){
    int myLinearList[] = {6, 11, 7, 12, 18, 17, 15, 13, 8, 0, 14, 1, 19, 16, 9, 5, 4, 2, 3, 10};
    printf("TX_SORT_COMPARATOR\n");
    printf("Selection sort\n");
    printf("before--------\n");
    showList(myLinearList, 20);
    printf("after---------\n");
    TX_SelectionSort(myLinearList, 20);
    showList(myLinearList, 20);
    int myLinearList2[] = {19, 17, 5, 12, 15, 3, 4, 11, 10, 2, 8, 13, 1, 16, 14, 9, 7, 6, 0, 18};
    printf("Insertion sort\n");
    printf("before--------\n");
    showList(myLinearList2, 20);
    printf("after---------\n");
    TX_InsertionSort(myLinearList2, 20);
    showList(myLinearList2, 20);
    int myLinearList3[] = {15, 9, 18, 5, 1, 13, 10, 11, 4, 3, 2, 17, 8, 19, 16, 12, 6, 7, 0, 14};
    printf("Bubble sort\n");
    printf("before--------\n");
    showList(myLinearList3, 20);
    printf("after---------\n");
    TX_BubbleSort(myLinearList3, 20);
    showList(myLinearList3, 20);
    int myLinearList4[] = {7, 13, 0, 2, 5, 17, 10, 8, 9, 11, 14, 15, 3, 19, 4, 16, 1, 18, 6, 12};
    printf("Shell sort\n");
    printf("before--------\n");
    showList(myLinearList4, 20);
    printf("after---------\n");
    TX_ShellSort(myLinearList4, 20);
    showList(myLinearList4, 20);
    int myLinearList5[] = {16, 3, 5, 18, 11, 17, 2, 14, 13, 4, 0, 10, 6, 12, 7, 8, 1, 15, 9, 19};
    printf("Quick sort\n");
    printf("before--------\n");
    showList(myLinearList5, 20);
    printf("after---------\n");
    TX_QuickSort(myLinearList5, 20);
    showList(myLinearList5, 20);
    int myLinearList6[] = {13, 11, 7, 9, 14, 18, 6, 0, 10, 8, 15, 19, 3, 16, 17, 4, 1, 12, 5, 2};
    printf("Merge sort\n");
    printf("before--------\n");
    showList(myLinearList6, 20);
    printf("after---------\n");
    int *aux = (int*)malloc(sizeof(int)*20);
    TX_MergeSort(myLinearList6, 20, aux);
    free(aux);
    showList(myLinearList6, 20);
    return true;
}