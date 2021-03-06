#include <stdio.h>

#include "heap_sort.h"

void siftdown(int* list, int size, int mid) {
    int parent = mid;
    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    int largest = parent;
    int tmp;

    if (left<size && list[left] > list[largest]) {
        largest = left;
    }
    if (right<size && list[right] > list[largest]) {
        largest = right;
    }

    if (parent != largest) {
        tmp = list[largest];
        list[largest] = list[parent];
        list[parent] = tmp;
        siftdown(list, size, largest);
    }
}

void makeHeap(int* list, int size) {
    int mid = size / 2 - 1;

    for (mid; mid >= 0; mid--) {
        siftdown(list, size, mid);
    }
}

void removekeys(int* list,int size){
    int tmp;
    while (size > 1) {
        tmp = list[0];
        list[0] = list[size - 1];
        list[size - 1] = tmp;

        size--;
        siftdown(list, size, 0);
    }
}

void heap_sort(int* list, int size) {
    makeHeap(list, size);
    removekeys(list, size);
}