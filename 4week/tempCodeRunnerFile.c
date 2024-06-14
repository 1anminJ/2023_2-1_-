#define _CRT_SECUER_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y);

int main(void){
    int result;
    int a, b, cond = 1;

    while(cond){
        printf("최대공약수를 할 두 수를 입력하시오 : ");
        scanf("%d %d", &a, &b);
        result = gcd(a, b);
        printf("gcd(%d, %d) = %d\n\n", a, b, result);
        printf("계속하실래요? (1/0) : ");
        scanf("%d", &cond);
    }
}

/*
START_GCD(x, y)
while(y != 0) do
	tmp = y
	y = x % y
	x = tmp
endwhile
return x
END_GCD
*/
int gcd(int x, int y){
    int tmp;
    while (y != 0)
    {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}