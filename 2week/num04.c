#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
 START
 read(num)
 while(num > 0) do
    r = num % 10
    num = num / 10
    print(r)
 endwhile
 END
 */

int main(void){
    int num, r;
    
    printf("두 자리 이상 양의 정수 입력 >> ");
    scanf("%d", &num);
    while(num > 0){
        r = num % 10;
        num = num / 10;
        printf("%d", r);
    }
    printf("\n");
}