#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // 3, 15번째 줄을 주석처리하고 살펴보면, 중복값이 나오는 것을 확인할 수 있음

/* C언어에서 난수 발생시키려면 rand() 함수 사용, 0 ~ RAND_MAX - 1 정수값을 난수로 발생시켜 리턴해주는 함수
    문제점 : 같은 난수 발생
    해결책 : 실행 도중 seed값을 달리해주어야 실행 때마다 같은 난수 발생 방지

    seed값을 설정해주는 srand()함수
*/

#define NUM 20

int main(){
    int i, num;

    srand((unsigned int)time(NULL));

    for(i = 0; i < 10; i++){
        num = rand() % 101;
        printf("%d\n", num);
    }

    printf("-------------------------\n");

    int x, xnum;

    for(x = 0; x < 10; x++){
        xnum = rand() % 101 + 100;  // 100~200 사이의 난수 출력
        printf("%d\n", xnum);
    }

    printf("-------------------------\n");

    int j;
    char c;

    for(j = 0; j < 10; j++){
        c = 'a' + rand() % 26; // 'a'부터 'z'까지의 랜덤한 문자 생성
        printf("%c\n", c);
    }

    printf("-------------------------\n");

    
    float rdata[NUM], fsum = 0.0;
    int y, ysum = 0, temp;

    // srand((unsigned int)time(NULL));   // seed값 설정
    for(y = 0; y < NUM; y++){
        rdata[y] = rand() % 100 + rand() % 100 / 100.0;  // 난수를 생성해 rdata[]에 저장  0~(99+0.99)
        printf("%.2f ", rdata[y]);  
        if((y + 1) % 7 == 0)
            printf("\n");
    }

    for(y = 0; y < NUM; y++){
        temp = rdata[y];
        ysum += temp;
        fsum += (rdata[y] - temp);
    }

    printf("\n\n정수 부분의 합 : %d\n", ysum);
    printf("소수 부분의 합 : %.3f\n", fsum);

    system("pause");
}