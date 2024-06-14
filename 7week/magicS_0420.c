#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

// 함수 선언
void make_msquare(int table[][MAX_SIZE], int n);
void display(int table[][MAX_SIZE], int n);

int main(void) {
    int n;
    int table[MAX_SIZE][MAX_SIZE];

    // 마방진의 크기 입력
    printf("Enter a number : ");
    scanf("%d", &n);

    // 입력된 크기가 유효한지 확인
    if (n < 1 || n > MAX_SIZE || n % 2 == 0) {
        printf("Error! Invalid size.\n");
        exit(0);
    }
    /* 다른 방법 */
    // if((n < 1) || n > MAX_SIZE){
    //     printf("Error! size is out of range. \n");
    //     exit(0);
    // }
    // if(!(n%2)){
    //     printf("Error! size is even.\n");
    //     exit(0);
    // }

    // 마방진 생성 및 출력
    make_msquare(table, n);
    display(table, n);
}

// 마방진 생성 함수
void make_msquare(int table[][MAX_SIZE], int n) {
    int i, j, digit, row, col;

    // 테이블 초기화
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            table[i][j] = 0;
    }

    // 중앙에 1 놓기
    i = 0;
    j = (n - 1)/2;
    table[i][j] = 1;

    // 마방진 채우기
    for (digit = 2; digit <= n * n; digit++) {
        row = i - 1;
        col = j - 1;
        if (row < 0) row = n - 1; // up
        if (col < 0) col = n - 1; // left
        if (table[row][col] != 0) i++;
        else {
            i = row;
            j = col;
        }
        table[i][j] = digit;
    }
}

// 마방진 출력 및 첫 번째 행의 합 계산 함수
void display(int table[][MAX_SIZE], int n) {
    int i, j, sum = 0;

    // 첫 번째 행의 합 계산
    for (j = 0; j < n; j++) {
        sum += table[0][j];
    }
    
    // 마방진 출력
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%5d", table[i][j]);
        printf("\n");
    }

    // 결과 출력
    printf("Row / Column / Diagonal Sum = %d\n", sum);
}
