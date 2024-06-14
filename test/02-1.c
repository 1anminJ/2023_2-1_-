#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *left;
    char *word;
    struct node *right;
} NODETYPE;

int insert_node(NODETYPE *root, char *str);
NODETYPE *search(NODETYPE *root, char *key);
void inorder(NODETYPE *root);

int main(void) {
    NODETYPE *tree = NULL;
    NODETYPE *ptr;
    char wbuf[30];

    printf("검색 트리에 저장할 단어를 입력하세요\n입력의 끝에는 quit를 입력하세요\n");

    while (strcmp(gets(wbuf), "quit")) {
        if (!tree) {
            tree = (NODETYPE *)malloc(sizeof(NODETYPE));
            tree->word = (char *)malloc(strlen(wbuf) + 1);
            strcpy(tree->word, wbuf);
            tree->left = tree->right = NULL;
        } else {
            insert_node(tree, wbuf);
        }
    }

    printf("\n\n검색할 단어 입력 : ");
    gets(wbuf);
    ptr = search(tree, wbuf);
    if (ptr)
        printf("%s가 트리에 존재함. \n\n", wbuf);
    else
        printf("%s가 트리에 존재하지 않음. \n\n", wbuf);
    

    printf("------트리 안의 단어들 (사전식 순서)------\n");
    inorder(tree);
}

NODETYPE *search(NODETYPE *root, char *key) {
    NODETYPE *tptr = root;
    int cmp;
    while (tptr) {
        cmp = strcmp(key, tptr->word);
        if (cmp < 0)
            tptr = tptr->left;
        else if (cmp > 0)
            tptr = tptr->right;
        else    // found
            return tptr;
    }
    return NULL;    // not found
}

int insert_node(NODETYPE *root, char *word) {
    NODETYPE *tptr = root, *before = NULL;
    int cmp;
    while (tptr) {
        cmp = strcmp(word, tptr->word);
        if (cmp < 0) {
            before = tptr;
            tptr = tptr->left;
        } 
        else if (cmp > 0) {
            before = tptr;
            tptr = tptr->right;
        } 
        else {
            return 0; 
        }
    }

    tptr = (NODETYPE *)malloc(sizeof(NODETYPE));
    tptr->word = (char *)malloc(strlen(word) + 1);
    strcpy(tptr->word, word);
    tptr->left = tptr->right = NULL;

    if (cmp < 0)
        before->left = tptr;
    else
        before->right = tptr;
    return 1;
}

void inorder(NODETYPE *ptr) {
    if (ptr) {
        inorder(ptr->left);
        printf("%s\n", ptr->word);
        inorder(ptr->right);
    }
}

 
