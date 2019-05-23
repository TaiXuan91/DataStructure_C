#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "TX_Sort.h"

void TX_SelectionSort(int *l, size_t length){
    for (size_t i=0;i<length;i++){
        size_t min_index = i;
        for (size_t j=i;j<length;j++){
            min_index = l[min_index]>l[j]?j:min_index;
        }
        int temp = 0;
        temp = l[i];
        l[i] = l[min_index];
        l[min_index] = temp;
    }
}

// be used to move last element in an list.
// in TX_InsertionSort， will use it.
// return true if succeed
// return false if failed
bool movelast(int *l, size_t p1, size_t p2){
    for(size_t i=p2; i>p1;i--){
        l[i]=l[i-1];
    }
    return true;
}

void TX_InsertionSort(int *l, size_t length){
    for(size_t i=1; i<length; i++){
        for(size_t j=0; j<i; j++){
            if(l[j]>l[i]){
                int temp = l[i];
                movelast(l, j, i);
                l[j] = temp;
            }
        }
    }
}

void TX_BubbleSort(int *l, size_t length){
    for(size_t i=length-1; i>0; i--){
        for(size_t j=0; j<i; j++){
            if(l[j]>l[j+1]){
                int temp = l[j+1];
                l[j+1] = l[j];
                l[j] = temp;
            }
        }
    }
}

// used in shell sort
void shell_sort_oneturn(int *l, size_t length,size_t shift,size_t step){
    for(size_t i=shift; i<length; i+=step){
        for(int j=i-step; j>=0; j-=step){
            if(l[j]>l[j+step]){
                int temp = l[j];
                l[j] = l[j+step];
                l[j+step] = temp;
            }
        }
    }
}

// Shell Sort
void TX_ShellSort(int *l, size_t length){
    size_t step = 1;
    while(step<length/3){
        step = step*3+1;
    }
    while(step>=1){
        for(size_t i = 0; i<step; i++){
            shell_sort_oneturn(l, length, i, step);
        }
        step = step/3;
    }
}


void TX_QuickSort(int *l, size_t length){
    if (length<=0){
        return;
    }
    int mvalue = l[0];
    size_t low = 0;
    size_t high = length-1;
    while(low<high){
        // This is not valid when there are two identical values in l.
        int temp;
        while(low<high && l[high]>mvalue)high--;
        temp = l[low];
        l[low] = l[high];
        l[high] = temp;
        while(low<high && l[low]<mvalue)low++;
        temp = l[low];
        l[low] = l[high];
        l[high] = temp;
    }
    TX_QuickSort(l, low);
    TX_QuickSort(l+low+1, length-low-1);
    return;
}

// This function is used in merge sort
// l+mid is the first element of the second part of l.
void merge_two_list(int *l, size_t length, size_t mid, int *aux){
    if(length<=1)return;
    for(size_t i=0; i<length; i++){
        aux[i] = l[i];
    }
    size_t i = 0;
    size_t j = mid;
    for(size_t shift=0; shift<length; shift++){
        if(i>=mid){
            l[shift]=aux[j];
            j++;
            continue;
        }
        if(j>=length){
            l[shift] = aux[i];
            i++;
            continue;
        }
        if(aux[i]<=aux[j]){
            l[shift]=aux[i];
            i++;
            continue;
        }
        else{
            l[shift]=aux[j];
            j++;
            continue;
        }
    }
}

// Merge Sort
void TX_MergeSort(int *l, size_t length, int* aux){
    if(length<=1)return;
    size_t mid = length/2;
    TX_MergeSort(l,mid, aux);
    TX_MergeSort(l+mid,length-mid, aux+mid);
    merge_two_list(l, length, mid, aux);
}

// used in heap sort
// small on the top
// length in not max array length.
// Here, the length is the number of element.
// number start from 1.
// void TX_Swim(int *l, size_t length, size_t k){
//     if(k>length){
//         return;
//     }
//     while(k>1 && l[k]>l[k/2]){
//         int temp;
//         temp = l[k/2];
//         l[k/2] = l[k];
//         l[k] = temp;
//         k = k/2;
//     }
// }

// used in heap sort
void TX_Sink(int *l, size_t length, size_t k){
    while(2*k+1<length){
        int j = 2*k+1;
        // big head.
        // the bigger will up.
        if (j+1<(int)length && l[j]<l[j+1]){
            j = j+1;
        }
        if(l[k]<l[j]){
            int temp;
            temp = l[j];
            l[j] = l[k];
            l[k] = temp;
            k = j;
            continue;
        }
        break;
    }
}

// reverse array
// void TX_Reverse(int *l, size_t length,size_t last){
//     int *aux = (int *)malloc(sizeof(int)*length);
//     for(size_t i=0; i<=last; i++){
//         aux[i] = l[last-i];
//     }
//     for(size_t i=0; i<=last; i++){
//         l[i] = aux[i];
//     }
//     free(aux);
// }

// Heap Sort
void TX_HeapSort(int *l, size_t length){
    for(int k=(int)(length-1)/2;k>=0;k--){
        TX_Sink(l,length,k);
    }
    int n = (int)(length-1);
    while(n>0){
        int temp = l[0];
        l[0] = l[n];
        l[n] = temp;
        TX_Sink(l,n, 0);
        n--;
    }
}