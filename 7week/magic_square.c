#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

/*
    # rule 1 : 첫 번째 행의 중앙에 1을 놓는다
        i = 0, j(n-1)/2
        table[i][j] = 1
    # rule 2 
        for count = 2 to n * n
            row = i - 1, col = i -1
            if(row < 0) row = n -1
            if(col < 0) col = n - 1
            if(table[row][col] != 0) i++
            else i = row, j = col
            table[i][j] = count
*/

void make_msquare(int table[][MAX_SIZE], int n);
void display(int table[][MAX_SIZE], int n);

void main(){
    int n, i, j, sum = 0, digit, row, col;
    int table[MAX_SIZE][MAX_SIZE];

    printf("Enter a number : ");
    scanf("%d", &n);

    if((n < 1) || n > MAX_SIZE){
        printf("Error! size is out of range. \n");
        exit(0);
    }
    if(!(n%2)){
        printf("Error! size is even.\n");
        exit(0);
    }

    make_msquare(table, n);
    display(table, n);
}

void make_msquare(int table[][MAX_SIZE], int n){
    int i, j, row, col, digit;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            table[i][j] = 0;
    }

    // 중앙에 1 놓기
    i = 0;
    j = (n - 1)/2;
    table[i][j] = 1;

    for(digit = 2; digit <= n * n; digit++){
        row = i - 1;
        col = j - 1;
        if(row < 0) row = n - 1; // up
        if(col < 0) col = n - 1; // left
        if(table[row][col]) i++;
        else{
            i = row;
            j = col;
        }
        table[i][j] = digit;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%5d", table[i][j]);
        printf("\n");
    }
}

void display(int table[][MAX_SIZE], int n){
    int i, j, sum = 0;

    for(j = 0; j < n; j++)
        sum += table[0][j];
    
    printf("Row / Column / Digonal Sum = %d\n", sum);
}
