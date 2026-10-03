#include <stdio.h>
typedef int ElemType;
ElemType MAX(ElemType a, ElemType b) {
    return a > b ? a : b;
}
void sameKey( ElemType A[], ElemType B[], ElemType C[],int n) {
    int i = 0, j = 0, k = 0;
    while(i < n && j < n && k < n) {
        if(A[i]==B[j]&&B[j]==C[k])
           { printf("%d\n",A[i]);
            i++;j++;k++;}    
        else{
            ElemType maxnum = MAX(A[i],MAX(B[j],C[k]));
            if(A[i] < maxnum) i++;
            if(B[j] < maxnum) j++;
            if(C[k] < maxnum) k++;
        }
}
}                   
int main(void) {
    ElemType A[] = {1, 2, 3, 4, 5, 7};
    ElemType B[] = {2, 4, 5, 6, 8};
    ElemType C[] = {2, 3, 4, 5, 9};
    int n = 5;

    sameKey(A, B, C, n);
    return 0;
}