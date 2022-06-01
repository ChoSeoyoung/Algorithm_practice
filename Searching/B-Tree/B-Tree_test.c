#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

#include "B-Tree.h"

int main(){
    struct timeval before1,before2,before3,before4,before5;
    struct timeval after1,after2,after3,after4,after5;
    double tmp;

    srand(time(NULL));
    gettimeofday(&before1, NULL);
    for(int i=0;i<1000;i++){
        insert(rand()%1000);
    }
    for(int i=0;i<500;i++){
        delete(root, rand()%1000);
    }
    gettimeofday(&after1, NULL);
    tmp = (double)(after1.tv_sec) + (double)(after1.tv_usec) / 1000000.0 - (double)(before1.tv_sec) - (double)(before1.tv_usec) / 1000000.0;
    printf("minimum degree: %d\n",M);
    printf("spend time: %f\n",tmp);   

}