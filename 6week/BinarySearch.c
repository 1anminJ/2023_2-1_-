
// 이진검색 함수(오름차순 정렬)
int bsearch_asc(int a[], int n, int key){
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

// 이진검색 함수(내림차순 정렬)
int bsearch_desc(int a[], int n, int key){
    int mid;
    int left = 0, right = n - 1;
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
}