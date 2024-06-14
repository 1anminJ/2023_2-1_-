#include <stdio.h>

int my_pow(int x, int y);

int main(void){
	int k;
	for(k = 2; k < 6; k++)
		printf("%d ** %d = %d\n", k, k+1, my_pow(k, k+1));
}
	int my_pow(int x, int y){
		int i, ans = 1;
		for(i = 0; i < y; i++)
				ans *= x;
		return ans;
	}