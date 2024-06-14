/*
# part 1
START
sum = 0
read(n)
for i = 0 to n-1 do
    read(scores(i))
    sum = sum + scores(i)
endfor
avg = sum / n
print(avg)
END
#part2
START
over_count = 0
for i = 0 to n-1 do
    if(scores(i) > avg) then over_count++
endfor
print(over_count) 
END
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define DMAX 100

int main(void){
    int n, scores[DMAX], over_count = 0, sum = 0, i = 0;
    double avg;
    printf("데이터 갯수 입력 >> ");
    scanf("%d", &n);
    printf("점수 입력 >> ");
    for(i = 0; i < n; i++){
        scanf("%d", &scores[i]);
        sum += scores[i];
    }
    avg = (double)sum / n;
    printf("성적 평균 : %.2f\n", avg);
    for(i = 0; i < n; i++){
        if(avg < scores[i]){
            over_count++;
        }
    }
    printf("평균 이상의 과목 갯수 : %d\n", over_count);
}