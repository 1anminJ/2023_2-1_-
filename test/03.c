#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct nodt *left;
    long id;
    float grade;
    struct nodt *right;
} SNODETYPE;

int insert_node(SNODETYPE *root, long sid, float grade);
SNODETYPE *search(SNODETYPE *root, long keyid);
void inorder(SNODETYPE *ptr);
void over4(SNODETYPE *ptr);

void main(int argc, char *argv[]){
    SNODETYPE *tree = NULL;
    SNODETYPE *ptr;
    long sid;
    float grade;
    FILE *input;

    if((input=fopen(argv[1], "r")) == NULL){
        printf("Invalid Open input file...\n");
        exit(1);
    }

    while(fscanf(input, "%ld %f", &sid, &grade) != EOF){
        if(!tree){
            tree = (SNODETYPE *)malloc(sizeof(SNODETYPE));
            tree -> id = sid;
            tree -> left = tree -> right = NULL;
            tree -> grade = grade;
        }
        else
            insert_node(tree, sid, grade);
    }
    printf("\n------저장된 트리 순회 리스트------");
    inorder(tree);

    printf("검색할 학생의 학번 입력 : ");
    scanf("%ld", &sid);
    prt = search(tree, sid);
    if(ptr)
        printf("%ld가 트리에 존재함(%.2f).\n", ptr-> id, ptr -> grade);
    else
        printf("%ld가 트리에 존재하지 않음.\n", sid);
    printf("\n4.0이상인 학생 검색 결과 : \n");
    over4(tree);
}

SNODETYPE *search(NODETYPE *root, char *keyid) {
    NODETYPE *tptr = root;
    int cmp;
    while (tptr) {
        if (keyid < tptr -> id)
            tptr = tptr->left;
        else if (keyid > tptr -> id)
            tptr = tptr->right;
        else    // found
            return tptr;
    }
    return NULL;    // not found
}


int insert_node(NODETYPE *root, long sid, float grade) {
    NODETYPE *tptr = root, *before = NULL;
    int left;
    while (tptr) {
        if (sid < tptr -> id) {
            before = tptr;
            tptr = tptr->left;
            left = 1;
        } 
        else if (sid > tptr -> id) {
            before = tptr;
            tptr = tptr->right;
            left = 0;
        } 
        else {
            return 0; 
        }
    }

    tptr = (SNODETYPE *)malloc(sizeof(SNODETYPE));
    tptr -> id = sid;
    tptr -> left = tptr -> right = NULL;
    tptr -> grade = grade;
    if (left)
        before->left = tptr;
    else
        before->right = tptr;
    return 1;
}

void inoder(SNODETYPE *ptr){
    if(ptr){
        inoder(ptr -> left);
        printf("%ld\n", ptr->id);
        inoder(ptr -> right);
    }
}

void over4(SNODETYPE *ptr){
    if(ptr){
        over4(ptr->left);
        if(ptr -> grade >= 4.0)
            printf("%ld\t%.2f\n", ptr->id, ptr->grade);
        over4(ptr->right);
    }
}
