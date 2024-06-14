#include <stdio.h>

int add_product(int *a, int b);

void main(){
    int x = 10, y = 20, z;
    z = add_product(&x, y);
    printf("x = %d :: y = %d :: z = %d\n", x, y, z);
}

int add_product(int *a, int b){
    int temp = b;
    b = *a + b;
    *a = *a * temp;
    return b;
}