/*
START
read(n)
print("Input id and score : ")
for i <- 0 to n-1 do
    read(scores(i, 0), scores(i, 1))
endfor
print("평균 : ", find_avg(scores, n))
print("최대값 : ", find_max(scores, n))
print("Input student id to be searched....")
read(sid)
print(sid, "의 등수 : ", find_rank(scores, n, sid))
END
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 100

double find_avg(int sdata[][2], int n);
int find_max(int sdata[][2], int n);
int find_rank(int sdata[][2], int n, int sid);

int main(void){
    int scores[NUM][2], sid, n;
    printf("학생의 수 입력 : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("학번과 성적 입력 : ");
        scanf("%d %d", &scores[i][0], &scores[i][1]);
    }
    printf("평균 : %.2f\n", find_avg(scores, n));
    printf("최대값 : %d\n", find_max(scores, n));
    printf("찾고 싶은 학생의 학번 입력 : ");
    scanf("%d", &sid);
    printf("등수 : %d\n", find_rank(scores, n, sid));
}

/*
START
 sum = 0
 for i <- 0 to n-1 do
    sum += sdata(i, 1)
 return sum / n
END
*/
double find_avg(int sdata[][2], int n){
    int i, sum;
    for(i = 0; i < n; i++)
        sum += sdata[i][1];
    return (double)sum / n;
}

/*
START
 max = sdata(0, 1)
 for i <- 1 to n-1 do
    if(sdata(i, 1) > max) max = sdata(i, 1)
 return max
END
*/
int find_max(int sdata[][2], int n){
    int i, max;
    for(i = 0; i < n; i++){
        if(sdata[i][1] > max)
            max = sdata[i][1];
    }
    return max;
}

/*
START
 for i <- 0 to n-1 do
    if(sid = sdata(i, 0))
     jumsu = sdata(i, 1)
     break
    endif
 endfor
 rank = 0;
 for i <- 0 to n-1 do
    if(sdata(i, 1) > jumsu) rank += 1
 endfor
 return rank + 1
END
*/
int find_rank(int sdata[][2], int n, int sid){
    int i, jumsu, rank;
    for(i = 0; i < n; i++){
        if(sid == sdata[i][0])
            jumsu = sdata[i][1];
            break;
    }
    rank = 0;
    for(i = 0; i < n; i++){
        if(sdata[i][1] > jumsu)
        rank++;
    }
    return rank + 1;
}


