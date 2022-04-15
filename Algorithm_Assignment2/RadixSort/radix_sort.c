#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodetype {
	int key;
	struct nodetype* link;
}NODE;

void distribute(int* masterlist, int size, int exp, NODE* list[]) {
	for (int i = 0; i < 10; i++) { //더미를 비운다
		list[i] = NULL;
	}

	for (int i = 0; i < size; i++) {
		int idx = (masterlist[i] / exp)%10;
		NODE* tmp = (NODE*)malloc(sizeof(NODE*));
		tmp->key = masterlist[i];
		tmp->link = list[idx];
		list[idx] = tmp;
	}
}

void coalesce(int* masterlist, NODE* list[]) {
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		for (NODE* tmp = list[i]; tmp != NULL; tmp = tmp->link) {
			masterlist[idx++] = tmp->key;
		}
	}
}

void radix_sort(int* masterlist, int size, int numdigits) {
	NODE* list[10];
	for (int i = 0; i < 10; i++) {
		list[i] = (NODE*)malloc(sizeof(NODE*));
		list[i]->key = NULL;
		list[i]->link = NULL;
	}

	int exp = 1;
	for (int i = 0; i < numdigits; i++) {
		exp *= 10;
	}
	for (int i = 0; i < numdigits; i++) {
		distribute(masterlist, size, exp, list);
		coalesce(masterlist, list);
		exp /=10;
	}
}
