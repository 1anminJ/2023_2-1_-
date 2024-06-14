#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *px, int *py);

main(){
    int x, y, z;
    printf("세 수를 입력하시오. ");
    scanf("%d %d %d", &x, &y, &z);
    if(x > y) swap(&x, &y);
    if(y > z) swap(&y, &z);
    if(x > y) swap(&x, &y);
    printf("%d **** %d **** %d\n", x, y, z);
}

void swap(int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}