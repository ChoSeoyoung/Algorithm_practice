#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

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
	int a[MAX];
	clock_t before;
	double result;

	srand(time(NULL));
	for (int i = 0; i < MAX; i++) {
		a[i] = rand() % MAX;
	}


	before = clock();
	exchange_sort(a, MAX);
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	printf("걸린시간은 %5.5f 입니다.", result);
	return 0;
}