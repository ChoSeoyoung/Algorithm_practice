#include <stdio.h>

void heapify(int* list, int size, int mid) {
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
        heapify(list, size, largest);
    }
}

void makeHeap(int* list, int size) {
    int mid = size / 2 - 1;

    for (mid; mid >= 0; mid--) {
        heapify(list, size, mid);
    }
}

void heapSort(int* list, int size) {
    makeHeap(list, size);

    int tmp;
    while (size > 1) {
        tmp = list[0];
        list[0] = list[size - 1];
        list[size - 1] = tmp;

        size--;
        heapify(list, size, 0);
    }
}

int main() {
    int list[10] = {5,1,8,26,10,62,98,2,55,8};
    heapSort(list, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", list[i]);
    }
}