#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
 n개의 자료의 값을 읽어 가장 큰 값 출력
 
 입력 : n, data
 출력 : mult
 
 n : 7
 data : 3   4   0   1   10   0   5
 
 large의 초기화
 read(data)
 if(data > large) large = data
 
 START
 read(n)
 mult = 1
 allzero = 1
 count = 0
 while(count < n) do
    read(data)
    if(data != 0) then
        mult = mult * data
        allzero = 0
    endif
    count = count + 1
 endwhile
 if(allzero == 1) mult = 0
 print(mult)
 END
 
 */

int main(void) {
    int n, data;
    int mult = 1, allzero = 1, count = 0;
    
    printf("자료의 개수 입력 >> ");
    scanf("%d", &n);
    while(count < n){
        scanf("%d", &data);
        if(data != 0)
            mult = mult * data;
            allzero = 0;
        count += 1;
    }
    if(allzero == 1)
        mult = 0;
    printf("값 >> %d \n", mult);
}