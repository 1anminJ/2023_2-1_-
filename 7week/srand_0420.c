#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 20

void print_int(int count, int min, int max);
void print_char(int count);
void print_float(int count);

int main(void) {
    // 시드 값을 현재 시간으로 설정하여 난수 발생기를 초기화
    srand((unsigned int)time(NULL));

    print_int(10, 0, 100);
    printf("-------------------------\n");
    print_int(10, 100, 200);
    printf("-------------------------\n");
    print_char(10);
    printf("-------------------------\n");
    print_float(NUM);

    system("pause");  // 프로그램이 바로 종료되지 않도록 대기
}

void print_int(int count, int min, int max) {
    int i, num;
    for (i = 0; i < count; i++) {
        num = rand() % (max - min + 1) + min;  // min부터 max까지의 난수를 생성
        printf("%d\n", num);
    }
}

void print_char(int count) {
    int i;
    char c;
    for (i = 0; i < count; i++) {
        c = 'a' + rand() % 26;  // 'a'부터 'z'까지의 랜덤한 문자를 생성
        printf("%c\n", c);
    }
}

void print_float(int count) {
    float rdata[NUM], fsum = 0.0;
    int i, ysum = 0, temp;

    for (i = 0; i < count; i++) {
        // 소수를 포함하는 실수를 생성
        rdata[i] = rand() % 100 + rand() % 100 / 100.0;
        printf("%.2f ", rdata[i]);
        if ((i + 1) % 7 == 0)  // 매 7개의 숫자마다 줄바꿈
            printf("\n");
        
        temp = rdata[i];
        ysum += temp;  // 각 숫자의 정수 부분을 합산
        fsum += (rdata[i] - temp);  // 각 숫자의 소수 부분을 합산
    }

    printf("\n\n정수 부분의 합 : %d\n", ysum);
    printf("소수 부분의 합 : %.3f\n", fsum);
}
