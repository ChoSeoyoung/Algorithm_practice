#ifndef _RADIXSORT_HEADER_H
#define _RADIXSORT_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//참고: https://yjg-lab.tistory.com/118

typedef struct nodetype {
	int key;
	struct nodetype* link;
}NODE;


void distribute(int* masterlist, int size, int exp, NODE* list[]);	
void coalesce(int* masterlist, NODE* list[]);
void radix_sort(int* masterlist, int size, int numdigits);

#endif /* _RADIXSORT_HEADER_H*/