#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX1 100
#define MAX2 500
#define MAX3 1000
#define MAX4 5000
#define MAX5 10000

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
	int a1[MAX1];
    int a2[MAX2];
    int a3[MAX3];
    int a4[MAX4];
    int a5[MAX5];
    srand(time(NULL));
    struct timeval before1,before2,before3,before4,before5;
    struct timeval after1,after2,after3,after4,after5;
    double result1,result2,result3,result4,result5;
    double tmp[5];
    for (int i = 0; i < MAX1; i++) {a1[i] = rand() % MAX1;}
    for (int i = 0; i < MAX2; i++) {a2[i] = rand() % MAX2;}
    for (int i = 0; i < MAX3; i++) {a3[i] = rand() % MAX3;}
    for (int i = 0; i < MAX4; i++) {a4[i] = rand() % MAX4;}
    for (int i = 0; i < MAX5; i++) {a5[i] = rand() % MAX5;}
    
    for(int i=0;i<5;i++){
        gettimeofday(&before1, NULL);
        exchange_sort(a1, MAX1);
        gettimeofday(&after1, NULL);
        tmp[i] = (double)(after1.tv_sec) + (double)(after1.tv_usec) / 1000000.0 - (double)(before1.tv_sec) - (double)(before1.tv_usec) / 1000000.0;
    }
    result1=(tmp[0]+tmp[1]+tmp[2]+tmp[3]+tmp[4])/5;
    printf("Data Size: 100 and Spended Time: %5.5f\n", result1);
    
    for(int i=0;i<5;i++){
        gettimeofday(&before2, NULL);
        exchange_sort(a2, MAX2);
        gettimeofday(&after2, NULL);
        tmp[i] = (double)(after2.tv_sec) + (double)(after2.tv_usec) / 1000000.0 - (double)(before2.tv_sec) - (double)(before2.tv_usec) / 1000000.0;
    }
    result2=(tmp[0]+tmp[1]+tmp[2]+tmp[3]+tmp[4])/5;
    printf("Data Size: 500 and Spended Time: %5.5f\n", result2);
    
    for(int i=0;i<5;i++){
        gettimeofday(&before3, NULL);
        exchange_sort(a3, MAX3);
        gettimeofday(&after3, NULL);
        tmp[i] = (double)(after3.tv_sec) + (double)(after3.tv_usec) / 1000000.0 - (double)(before3.tv_sec) - (double)(before3.tv_usec) / 1000000.0;
    }
    result3=(tmp[0]+tmp[1]+tmp[2]+tmp[3]+tmp[4])/5;
    printf("Data Size: 1000 and Spended Time: %5.5f\n", result3);
 
    for(int i=0;i<5;i++){
        gettimeofday(&before4, NULL);
        exchange_sort(a4, MAX4);
        gettimeofday(&after4, NULL);
        tmp[i] = (double)(after4.tv_sec) + (double)(after4.tv_usec) / 1000000.0 - (double)(before4.tv_sec) - (double)(before4.tv_usec) / 1000000.0;
    }
    result4=(tmp[0]+tmp[1]+tmp[2]+tmp[3]+tmp[4])/5;
    printf("Data Size: 5000 and Spended Time: %5.5f\n", result4);
    
    for(int i=0;i<5;i++){
        gettimeofday(&before5, NULL);
        exchange_sort(a5, MAX5);
        gettimeofday(&after5, NULL);
        tmp[i] = (double)(after5.tv_sec) + (double)(after5.tv_usec) / 1000000.0 - (double)(before5.tv_sec) - (double)(before5.tv_usec) / 1000000.0;
    }
    result5=(tmp[0]+tmp[1]+tmp[2]+tmp[3]+tmp[4])/5;
    printf("Data Size: 10000 and Spended Time: %5.5f\n", result5);

    printf("Total Average time: %5.5f\n",(result1+result2+result3+result4+result5)/5);
    return 0;
}