#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPR_SIZE 50
#define MAX_STACK_SIZE 30

char pexpr[MAX_EXPR_SIZE];
int stack[MAX_STACK_SIZE];
int top;

int delete_stack();
void add_stack(int data);
int is_operator(char c);
int cal(void);

void main(){
    printf("Input the expression as a postfix notation : ");
    gets(pexpr);
    printf("Evaluation Value : %d\n", cal());
}

int cal(void){
    char symbol;
    int op1, op2, n = 0;

    top = -1;
    symbol = pexpr[n++];

    while(symbol != '\0'){
        if(is_operator(symbol)){
            op2 = delete_stack();
            op1 = delete_stack();
            switch (symbol)
            {
            case '+' : add_stack(op1 + op2);
                break;
            case '-' : add_stack(op1 - op2);
                break;
            case '*' : add_stack(op1 * op2);
                break;
            case '/' : add_stack(op1 / op2);
                break;
            }
        }
        else
            add_stack(symbol - '0');    // 스택에 삽입
        symbol = pexpr[n++];
    }
    return delete_stack();  //결과 반환
}

int delete_stack(){
    int data;
    if(top == -1){
        printf("Stack is empty. \n");
        exit(1);
    }
    data = stack[top];
    top--;
    return data;
    // return stack[top--];
}

void add_stack(int data){
    if(top >= MAX_STACK_SIZE - 1){
        printf("Stack is full. \n");
        exit(1);
    }
    ++top; stack[top] = data;
    // stack[++top] = data;
}

int is_operator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}