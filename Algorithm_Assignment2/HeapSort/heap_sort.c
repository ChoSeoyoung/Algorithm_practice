#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

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

void heap_sort(int* list, int size) {
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
    int a[MAX];
    clock_t before;
    double result;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        a[i] = rand() % MAX;
    }


    before = clock();
    heap_sort(a, MAX);
    result = (double)(clock() - before) / CLOCKS_PER_SEC;
    printf("걸린시간은 %5.5f 입니다.", result);
    return 0;
}