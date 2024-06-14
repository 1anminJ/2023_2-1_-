// 프로그램 명령 인수 출력
// main()의 명령인수 받아들이기 = 컴파일러마다 다르다 = 프로젝트명에서 오른쪽 버튼.. 속성.. 디버깅.. 명령인수로 준다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y);

int main(int argc, char* argv[]) {
    int i;
    printf("프로그램 명령 인수의 갯수는 %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("%d : %s\n", i, argv[i]);

    int a, b, result, answer;
    int correct = 0, i = 0;
    FILE* infile;
    if (argc != 2) {
        printf("실행인수를 잘못주었습니다.");
        exit(1);
    }
    if ((infile = fopen(argv[1], "r")) == NULL) {
        printf("입력파일을 열 수 없습니다.");
        exit(1);
    }
    while (fscanf(infile, "%d %d", &a, &b) != EOF) {
        printf("%d : gcd(%d %d) = ", i + 1, a, b);
        scanf("%d", &answer);
        result = gcd(a, b);
        if (answer != result)
            printf("Answer : gcd(%d %d) = %d\n", a, b, result);
        else {
            printf("Correct...\n");
            correct++;
        }
        i++;
    }
    printf("%d문제 중에 %d문제를 통과하셨습니다. \n", i, correct);
}

int gcd(int x, int y) {
    int tmp;
    while (y != 0)
    {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}