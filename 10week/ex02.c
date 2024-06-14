#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(){
    /* 메모리 주소를 값으로 가지는 데이터 형 실습*/
    int *p, q;
    float *fp, x;
    p = &q;
    *p = 199;
    fp = &x;
    scanf("%f", fp);
    printf("%d --- %.2f\n", q, x);
}