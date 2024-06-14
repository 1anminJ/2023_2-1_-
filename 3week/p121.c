#include <stdio.h>

float trunc_sum(float *data);

void main(){
    float xarray[10], fsum = 0.0;
    int i; 
    printf("Enter 10 reals : ");
    for(i = 0; i < 10; i++){
        scanf("%f", xarray + i);
        fsum = fsum + *(xarray + i);
    }
    printf("Sum = %.2f\n", fsum);
    printf("Truncation Value = %.2f\n", trunc_sum(xarray));
}

float trunc_sum(float *data){
    float sum = 0.0;
    int i, ivalue;
    for(i = 0; i < 10; i++){
        ivalue = data[i];
        sum += (data[i]-ivalue);
    }
    return sum;
}