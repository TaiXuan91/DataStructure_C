#include <stddef.h>
#include <stdbool.h>

#include "TX_Anytype.h"
#include "TX_List.h"

#if !defined(TX_SORT)
#define TX_SORT

// Select different comparison functions by list type.
// if list type is TX_NONE, it can't be sorted.
typedef bool (*TX_Sort_Comparator)(TX_Anytype_AnytypeElement e1, TX_Anytype_AnytypeElement e2);

// Get comparator of type
TX_Sort_Comparator TX_Sort_GetComparator(TX_Anytype_Typenumber t);

// Selection sort
void TX_SelectionSort(int *l, size_t length);

// Insertion sort
void TX_InsertionSort(int *l, size_t length);

// Bubble Sort
void TX_BubbleSort(int *l, size_t length);

// Shell Sort
void TX_ShellSort(int *l, size_t length);

// Quick Sort
void TX_QuickSort(int *l, size_t length);

// Merge Sort
void TX_MergeSort(int *l, size_t length, int* aux);


#endif // TX_SORT
