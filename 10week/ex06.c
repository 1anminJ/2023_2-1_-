#include <stdio.h>
#include <stdlib.h>

void main(){
    int *ip;
    float *fp;
    // 동적 메모리 할당
    ip = (int *)malloc(sizeof(int));
    fp = (float *)malloc(sizeof(float));
    // 동적 메모리 사용
    *ip = 2020;
    *fp = 7.123;
    printf("year = %d : point = %.3f\n", *ip, *fp);
    // 동적 메모리 반납
    free(ip);
    free(fp);
}