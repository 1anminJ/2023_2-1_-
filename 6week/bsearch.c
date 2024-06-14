#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 30

char compare(int x, int y);
void selection_sort(int list[], int n); // 오름차순 정렬
void selection_down_sort(int list[], int n); // 내림차순 정렬
int bsearch_ascending(int a[], int n, int key);
int bsearch_desending(int a[], int n, int key);
void sort_data(int list[], int n);

int main(void){
    int n; 
    int list[NUM];
    printf("입력 받을 데이터의 수 : ");
    scanf("%d", &n);
    printf("데이터 값 입력 : ");
    for(int x = 0;  x < n; x++){
        scanf("%d", &list[x]);
    }

    char sorted;
    int key1, kind, result1;
    printf("정렬 방법을 선택하세요 1. 오름차순 2. 내림차순 >> ");
    scanf("%d", &kind);
    if(kind == 1)
        selection_sort(list, n);
    else if(kind == 2)
        selection_down_sort(list, n);
    printf("정렬 후 데이터 값\n");
    sort_data(list, n);
    printf("Enter a key : ");
    scanf("%d", &key1);

    if(kind == 1)
        result1 = bsearch_ascending(list, n, key1);
    else
        result1 = bsearch_desending(list, n, key1);
    
    if(result1 == -1)
        printf("%d is not found\n", key1);
    else
        printf("%d is found[%d]\n", key1, result1 + 1);
}

// x와 y의 크기에 따라 '>, <, =' 반환
char compare(int x, int y){
    if(x > y)
        return '>';
    else if(x < y)
        return '<';
    else return '=';
}

// 오름차순 정렬
void selection_sort(int list[], int n){
    int s, m, j, temp;
    for(s = 0; s < n-1; s++){
        m = s;
        for(j = s + 1; j < n; j++){
            if(list[j] < list[m])
            m = j;
        }
        temp = list[s];
        list[s] = list[m];
        list[m] = temp;
    }
}

// 내림차순 정렬
void selection_down_sort(int list[], int n){
    int s, m, j, temp;
    for(s = 0; s < n - 1; s++){
        m = s;
        for(j = s + 1; j < n; j++){
            if(list[j] > list[m])
            m = j;
        }
        temp = list[s];
        list[s] = list[m];
        list[m] = temp;
    }
}

// 이진검색 함수(오름차순 정렬)
int bsearch_ascending(int a[], int n, int key){
    int mid;
    int left = 0, right = n - 1;
    while(left <= right){
        mid = (left + right) / 2;
        switch (compare(key, a[mid])){
        case '>' : left = mid + 1;
            break;
        case '<' : right = mid - 1;
            break;
        case '=' : return mid;
        }
    }
    /* if문*/
    // if(key > a[mid])
    //     left = mid + 1;
    // else if(key < a[mid])
    //     right = mid - 1;
    // else 
    //     return mid;
    return -1;
}

// 이진탐색 함수(내림차순 정렬)
int bsearch_desending(int a[], int n, int key){
    int mid;
    int left = 0, right = n - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(key > a[mid]) 
            right = mid - 1;
        else if(key < a[mid]) 
            left = mid + 1;
        else return mid;

        /* switch문
        while(left <= right){
            mid = (left + right) / 2;
            switch (compare(key, a[mid])){
            // 내림차순의 경우 부등호 방향만 바꿈
            case '<' : left = mid + 1;
                break;
            case '>' : right = mid - 1;
                break;
            case '=' : return mid;
            }
        }
        */
    }
    return -1;
}

// 배열의 현재 상태 출력
void sort_data(int list[], int n){
    for(int x = 0; x < n; x++)
        printf("%d ", list[x]);
    printf("\n");
}