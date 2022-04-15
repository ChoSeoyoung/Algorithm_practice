#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void radix_sort(int* list, int n) {
	int result[MAX], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (list[i] > maxValue) maxValue = list[i];
	}
	while (maxValue / exp > 0) { // 1의 자릿수 계산
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) bucket[list[i] / exp % 10]++; // 자릿수 배열 처리
		for (int i = 1; i < 10; i++)bucket[i] += bucket[i - 1]; // 누적 계산 : 결과 배열을 만들기 위해서!	
		for (int i = n - 1; i >= 0; i--) { //같은 자릿수 끼리는 순서를 유지
			result[--bucket[list[i] / exp % 10]] = list[i];
		}
		for (int i = 0; i < n; i++) list[i] = result[i]; // 기본 배열 갱신
		exp *= 10;
	}
}

int main(void) {
	int list[MAX];
	clock_t before;
	double result;

	srand(time(NULL));
	for (int i = 0; i < MAX; i++) {
		list[i] = rand() % MAX;
	}


	before = clock();
	radix_sort(list, MAX);
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	printf("걸린시간은 %5.5f 입니다.", result);
	return 0;
}