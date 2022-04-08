#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void quick_sort(int list[], int low, int high) {
    //배열의 원소가 2개 이상일 경우
    if (low < high) {

        int j = low;
        int tmp;
        int pivotItem = list[low];
        for (int i = low + 1; i <= high; i++) {
            if (list[i] < pivotItem) {
                j += 1;
                int tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
        int pivotpoint = j;
        tmp = list[low];
        list[low] = list[pivotpoint];
        list[pivotpoint] = tmp;

        quick_sort(list, low, pivotpoint - 1);
        quick_sort(list, pivotpoint + 1, high);
    }
}

int main() {
    int list[MAX];
    clock_t before;
    double result;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        list[i] = rand() % MAX;
    }


    before = clock();
    quick_sort(list, 0, MAX - 1);
    result = (double)(clock() - before) / CLOCKS_PER_SEC;
    printf("걸린시간은 %5.5f 입니다.", result);
    return 0;
}