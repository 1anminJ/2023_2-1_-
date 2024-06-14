#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>

typedef struct member{
    int id;
    char name[20];
    float score;
} example;

void over40(example *a, int n);
example find_max(example *a, int n);

void main(){
    example onep, exmember[20];
    int i, n;
    printf("Input the number of data : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("데이터 입력 : ");
        scanf("%d %s %f", &exmember[i].id, &exmember[i].name, &exmember[i].score);
    }

    over40(exmember, n);
    onep = find_max(exmember, n);
    printf("Infomaion of the higest score student = %d : %s : %.2f\n", onep.id, onep.name, onep.score);
}

void over40(example *a, int n){
    int k;

    printf("List of high score students(over 4.0)\n");
    for(k = 0; k < n; k++){
        if(a[k].score >= 4.0)
            printf("%d -- %s\n", a[k].id, a[k].name);
    }
}

example find_max(example *a, int n){
    int x, maxindex;

    maxindex = 0;

    for(x = 0; x < n; x++){
        if(a[x].score > a[maxindex].score)
            maxindex = x;
    }
    return a[maxindex];
}
