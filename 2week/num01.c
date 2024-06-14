/*
두 수와 수행할 연산자를 읽어 그 연산 결과 출력
입력 : a, b, op(+, =, *, /)
출력 : c

START
read(a, b)
read(op)
if(op=='+') then c = a + b
if(op=='-') then c = a - b
if(op=='*') then c = a * b
if(op=='/') then c = a / b
print(c)
END
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int a, b, c = 0;
    char op;
    printf("두 개의 정수 입력 >> ");
    scanf("%d %d", &a, &b);
    printf("연산자 입력 >> ");
    scanf(" %c", &op);

    if(op == '+')
        c = a + b;
    if(op == '-')
        c = a - b;
    if(op == '*')
        c = a * b;
    if(op == '/')
        c = a / b;

    printf("%d %c %d = %d \n", a, op, b, c);
}