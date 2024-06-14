#define _CRT_SECURE_NO_WARNINGS
#define DNUM 100
#include <stdio.h>

int pcount(int a[], int n);
double avg(int a[], int n);
int large(int a[], int n);
int small(int a[], int n);
int main(void)
{
    int data[DNUM], k, n;
    printf("처리할 데이터의 수 : ");
    scanf("%d", &n);
    printf("%d개의 정수를 입력하시오 : ", n);
    for(k = 0; k < n; k++)
        scanf("%d", &data[k]);
    printf("양의 갯수는 %d\n", pcount(data, n));
    printf("데이터 평균 = %.2f\n", avg(data, n));
    printf("최대값 = %d\n", large(data, n));
    printf("최소값 = %d\n", small(data, n));
}

int pcount(int a[], int n){
    int j, result = 0;
    for(j = 0; j < n; j++){
        if(a[j] > 0)
            result++;
    }
    return result;
}

double avg(int a[], int n){
    int j, sum;
    double avg;
    for(j = 0; j < n; j++){
        sum += a[j];
    }
    avg = (double)sum / n;
    return avg;
}

int large(int a[], int n){
    int j, lar = 0;
    for(j = 0; j < n; j++){
        if(a[j] > lar)
            lar = a[j];
    }
    return lar;
}

int small(int a[], int n){
    int j, min = 0;
    for(j = 0; j < n; j++){
        if(a[j] < min)
            min = a[j];
    }
    return min;
}