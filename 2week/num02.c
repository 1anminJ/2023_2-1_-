/*
 세 수를 읽어 그중 가장 큰 값을 찾아 출력하는 알고리즘을 작성하시오
 (입력 세 수가 다르게 입력된다는 가정하에 작성)
 입력 : n1, n2, n3
 출력 : large
 
 START
 read(n1, n2, n3)
 
 if(n1 > n2) then large = n1
 else large = n2
 
 if(n3 > large) then large = n3
 print(large)
 END
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int n1, n2, n3;
    int large;
    
    printf("서로 다른 정수 세 개 입력 >> ");
    scanf("%d %d %d", &n1, &n2, &n3);
    if(n1 > n2)
        large = n1;
    else
        large = n2;
    if(n3 > large)
        large = n3;
    
    printf("가장 큰 수 >> %d \n", large);
}