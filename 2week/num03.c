/*
 40명의 학생의 성적의 평균을 구하는 알고리즘 작성
 
 입력 : data(40)
 출력 : avg
 기타 : lcv(count=0), sum = 0
 
START
 sum = 0
 count = 0
 
 #while문
 while(count < 40) do
    read(data)
    sum = sum + data
 endwhile
 avg = sum / 40
 pring(avg)
 
 #for문
 for count = 1 to 40 do
    read(data)
 sum = sum + data
 endfor
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int data, sum = 0, count = 0;
    float avg;
    // while문
    while(count < 40){
        printf("성적을 입력 >> ");
        scanf("%d", &data);
        sum += data;
        count += 1;
    }
    // for문
    for(int count = 1; count < 40; count++){
        int data = 0;
        printf("성적을 입력 >> ");
        scanf("%d", &data);
        sum += data;
    }
    
    avg = sum / 40;
    printf("성적의 평균 : %.2f\n", avg);
}
