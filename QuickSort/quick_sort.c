#include <stdio.h>

void quick_sort(int list[],int low, int high) {
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
    int llist[10] = { 1, 2, 7, 8, 12, 23, 3, 93, 49, 19 };
    quick_sort(llist, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", llist[i]);
    }
}