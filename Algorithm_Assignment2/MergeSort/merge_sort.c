#include <stdio.h>

#include "merge_sort.h"

#define MAX1 100
#define MAX2 500
#define MAX3 1000
#define MAX4 5000
#define MAX5 10000

int sorted[MAX5];//추가적인 공간 필요

void merge(int list[], int low, int mid, int high) {
    int l = low;
    int h = mid + 1;
    int idx = 0;
    while (l < mid + 1 && h < high + 1) {
        if (list[l] <= list[h]) {
            sorted[idx] = list[l];
            l += 1;
            idx += 1;
        }
        else if (list[l] > list[h]) {
            sorted[idx] = list[h];
            h += 1;
            idx += 1;
        }
    }
    for (int i = l; i < mid + 1; i++) {
        sorted[idx] = list[i];
        idx += 1;
    }
    for (int i = h; i < high + 1; i++) {
        sorted[idx] = list[i];
        idx += 1;
    }

    int start = 0;
    for (int i = low; i < high + 1; i++) {
        list[i] = sorted[start++];
    }
}

void merge_sort(int list[], int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
        merge_sort(list, low, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
        merge_sort(list, mid + 1, high); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        merge(list, low, mid, high); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
    }
}
