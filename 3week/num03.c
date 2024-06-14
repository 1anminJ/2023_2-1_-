/*
# 음수가 나올 때 까지 양수를 읽어 들여 읽어 들인 데이터 수와 최대 값을 출력하는 c 프로그램을 작성
    (단, 처음부터 음수를 입력하는 경우 "No data!!"라고 출력하고 끝냄)
    input : num
    ouput : size, max
    START
    max = 0, size = 0
    read(num)
    while(num > 0) do
        size += 1
        if(num > max) max = num
        read(num)
    endwhile
    print("데이터 수 : ", size)
    if(size = 0) print("No data!!")
    else print("최대값 : ", max)
    END
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int max = 0, size = 0, num;
    printf("데이터 입력 >> ");
    scanf("%d", &num);
    while (num > 0)
    {
        size += 1;
        if(num > max)
            max = num;
        scanf("%d", &num);
    }
    printf("데이터 수 : %d \n", size);
    if(size == 0)
        printf("No data!! \n");
    else
        printf("최대값 : %d \n", max);
}