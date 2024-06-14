#include <stdio.h>

int pcount(int a[]);

int main(void){
    int data[10], k;

    printf("Enter 10 data : ");
    for(k = 0; k < 10; k++)
        scanf("%d", &data[k]);
    printf("양의 갯수는 %d\n", pcount(data));
}

int pcount(int a[]){
    int j, result = 0;
    for(j = 0; j < 10; j++){
        if(a[j] > 0)
            result++;
    }
    return result;
}