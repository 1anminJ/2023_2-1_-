#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 500

long lookup(long pdb[][2], int n, long item_code);
void display_code(long pdb[][2], int n);
long total_price(unsigned s[][2], int n);



void main(int argc, char *argv[]){
    FILE *pricedb;

    long pdb[MAX_NUM][2], item_code, item_price;
    int i = 0, j, n, num, item_num;
    long total_price = 0;

    // 데이터 파일 읽어오기
    if((pricedb = fopen(argv[1], "r")) == NULL){
        printf("데이터 파일을 열 수 없습니다. \n");
        exit(1);
    }
    while (fscanf(pricedb, "%ld %ld", &(pdb[i][0]), &(pdb[i][1])) != EOF){
        i++;
    }

    n = i;      // 물품의 총 갯수

    printf("오늘 팔린 물품의 종류는 몇 개인가요? : ");
    scanf("%d", &num);
    display_code(pdb, n);
    for(j = 0; j < num; j++){
        printf("물품코드와 팔린 갯수를 입력하시오. ");
        scanf("%ld %ld", &item_code, &item_num);
        item_price = lookup(pdb, n, item_code);
        if(item_price == 0){
            printf("%ld : 입력한 물품에 대한 가격 정보가 없습니다. ", item_code);
        }
        else
            printf("%ld : %ld\n", item_code, item_price);
        total_price = total_price + (item_num * item_price);    //정산 금액 계산

        printf("오늘의 정산 금액 : %ld\n", total_price);
        system("pause");
    }
}

// 물품코드에 해당하는 가격
long lookup(long pdb[][2], int n, long item_code){
    int i;

    for(i = 0; i < n; i++){
        if(pdb[i][0] == item_code)
            return pdb[i][1];
    }
    return 0;
}


// 물품코드 리스트 출력함수
void display_code(long pdb[][2], int n){
    int i;
    printf("물품코드 리스트 : \n");
    for(i = 0; i < n; i++){
        printf("%ld\n", pdb[i][0]);
    }
}