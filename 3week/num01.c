/* n명의 학생의 학번과 성적을 이차원 배열에 읽어 들여 학번을 입력하면
   그의 성적과 등수를 출력하는 알고리즘 작성
    START
    read(n)
    print("INput id and score : ")
    for i <- 0 to n-1 do
        read(scores(i,0), scores(i, 1))
    endfor
    print("Input student id to b searched...")
    read(sid)
    for i <- 0 to n-1 do
        if(sid = scores(i, 0))
            jumsu = scores(i, 1)
            break
        endif
    endfor
    rank = 0;
    for i <- 0 to n-1 do
        if(scores(i, 1) > jumsu) rank = rank + 1
    endfor
    print(sid, "의 점수 : ", jumsu)
    print(sid, "의 등수 : ", rank + 1)
    END
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 4

int main(void) {
    int i, scores[NUM][2], sid, jumsu = 0, rank, n;
    printf("입력할 학생의 수 입력 >> ");
    scanf("%d", &n);
    printf("학번과 점수를 입력 >> \n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &scores[i][0], &scores[i][1]);
    printf("원하는 학생의 학번 입력 >> ");
    scanf("%d", &sid);
    for(i = 0; i < n; i++){
        if(sid == scores[i][0]){
            jumsu = scores[i][1];
            break;
        }
    }
    rank = 0;
    for(i = 0; i < n; i++)
        if(scores[i][1] > jumsu) 
            rank++;
    printf("%d번의 점수 : %d \n", sid, jumsu);
    printf("%d번의 등수 : %d \n", sid, rank + 1);
}
