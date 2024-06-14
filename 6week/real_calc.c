#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define STAGE1 0
#define STAGE2 1
#define STAGE3 2

// 실수형
void real_calculator(void);
double real_operation(char op, double operand1, double operand2);
double get_real(double current_operand, char c, int status);
int is_operator(char c);
int is_digit(char c);

int main(void) {
	printf("계산기 프로그램을 시작합니다.\n");
	printf("실수형의 피연산자와 사칙연산자 중 하나를 입력하시오. \n");
    printf("결과를 받은 후 끝내려면 문자 x를 입력하시오.\n");
	real_calculator();
	printf("\n계산기 프로그램을 종료합니다.\n");
}

void real_calculator(void){
    double operand1 = 0, operand2 = 0;
	char op, c;
    double result;
	int current_stage = STAGE1, status = 0;

	while ((c = getchar()) != 'x') {
		if (current_stage == STAGE1) {
			if (is_digit(c)){
				operand1 = get_real(operand1, c, status);
                if(status != 0)
                    status++;
            }
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
                status = 0;
				operand2 = 0;
			}
            else if(c == '.')   
                status = 1;
		} // STAGE1

		else if (current_stage == STAGE2) {
			if (is_digit(c)){
				operand2 = get_real(operand2, c, status);
                if(status != 0) status++;
            }
            else if(c == '.') 
                status = 1;
			else if (c == '\n') {
				result = real_operation(op, operand1, operand2);
				if ((result - (int)result) == 0) // 정수일 때
				    printf("= %.0f", result);
				/*   # 위의 코드 다른 작성 방법
				if(result / 1.000 == (int)result)
				    printf("= %.f", result);
				*/
                else
				    printf("= %.3f", result);
				current_stage = STAGE3;
                status = 0;
			}
		}

		else if (current_stage == STAGE3) {
			if (c == '\n') {
				operand1 = 0;
				current_stage = STAGE1;
			}
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
				operand1 = result;
				operand2 = 0;
			}
		}
	}
}


double real_operation(char op, double operand1, double operand2) {
	double result;
	switch (op) {
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0) {
			printf("\n0으로 나눌 수 없습니다. \n");
			result = operand1;
		}
		else
			result = operand1 / operand2;
		break;
    case '^':
        result = pow(operand1, operand2);
        break;
	}
	return result;
}

int is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	else
		return 0;
}

int is_digit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

double get_real(double current_operand, char c, int status){
    int part1;
    double part2;
    if(status == 0){
        part1 = c - '0';
        current_operand *= 10;
        current_operand += part1;
    }
    else{
        part2 = c - '0';
        part2 = part2 * pow(10, -status);
        current_operand += part2;
    }
    return current_operand;
}
