#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

int findMissMin(ElemType A[], int n){
    int *B = (int *)malloc(sizeof(int) * n);
    if (B == NULL) return -1;

    memset(B, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++){
        if (A[i] > 0 && A[i] <= n)
            B[A[i] - 1] = 1;                   //之后用 B[i] 作为布尔标记数组来记录某个数是否出现过
    }

    int i;
    for (i = 0; i < n; i++){
        if (B[i] == 0)
            break;
    }
    free(B);
    return i + 1;
}

int main(){
    ElemType A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(A) / sizeof(ElemType);
    printf("%d\n", findMissMin(A, n));
    return 0;
}