// 선택정렬 실습
#include <stdio.h>

void selection_sort(int list[], int n);
void selection_under_sort(int list[], int n);
void print_data(int list[], int n);

void main(){
    // int aList[] = {65, 77, 30, 90, 15, 85, 37, 55};
    // int n = 8;
    // selection_sort(aList, n);
    // print_data(aList, n);
    int n, num = 0;
    int list[7];

    printf("개수 입력 : ");
    scanf("%d", &n);

    printf("넣을 값 입력 : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        list[i] = num;
    }
    print_data(list, n);
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
void selection_under_sort(int list[], int n){
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


void print_data(int list[], int n){
    int i; 
    printf("\n입력한 값 : ");
    for(i = 0; i < n; i++){
        printf("%d\t", list[i]);
    }

    printf("\n\n오름차순 정렬 \n");
    selection_sort(list, n);
    for(i = 0; i < n; i++)
        printf("%d\t", list[i]);
    
    printf("\n\n내림차순 정렬 \n");
    selection_under_sort(list, n);
    for(i = 0; i < n; i++)
        printf("%d\t", list[i]);
}