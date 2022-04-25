#include <stdio.h>

void exchange_sort(int list[], int size) {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

int main() {
    int list[10] = { 5,1,8,26,10,62,98,2,55,8 };
    exchange_sort(list, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", list[i]);
    }
}