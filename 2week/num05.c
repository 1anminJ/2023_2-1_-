#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
 n개의 자료의 값을 읽어 가장 큰 값 출력
 
 입력 : n, data
 출력 : large
 
 n : 7
 data : 29   55   17   78   99   35   80
 
 large의 초기화
 read(data)
 if(data > large) large = data
 
 START
 read(n)
 read(data)
 count = 1
 large = data
 while(count < n) do
    read(data)
    if(data > large) large = data
    count = count + 1
 endwhile
 print(large)
 
 END
 
 */

int main(void) {
    int n, data;
    int count = 0;
    int large = data;
    printf("자료의 개수 입력 >> ");
    scanf("%d", &n);
    while(count < n){
        scanf("%d", &data);
        if(data > large)
            large = data;
        count += 1;
    }
    printf("가장 큰 값 >> %d \n", large);
}
