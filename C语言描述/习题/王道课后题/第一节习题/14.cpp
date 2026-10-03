#include <stdio.h>
typedef int ElemType;
#define INT_MAX 0x7fffffff
int first_is_min(ElemType a, ElemType b, ElemType c){
       if (a < b && a < c)
         return a;
    return -1;}
int abs_(ElemType a){
  return a > 0 ? a : -a;
}
int findMinofTrip(ElemType A[], int m, ElemType B[], int n, ElemType C[], int p){
   int i = 0, j = 0, k = 0;
   int D_min = INT_MAX;
    while(i < m && j < n && k < p && D_min > 0){
        int D = abs_(A[i] -B [j]) + abs_(B[j] - C[k]) + abs_(A[i] - C[k]);
              if(D_min > D)
              D_min = D;
                 if(first_is_min(A[i], B[j], C[k])) i++;
                 else if(first_is_min(B[j],A[i],C[k]))  j++;
                 else k++;
    } 
    return D_min;
}
int main(){
    ElemType A[] = {1, 4, 5, 7};
    ElemType B[] = {10, 20, 30, 40};
    ElemType C[] = {100, 101, 102, 103};
    int m = 4, n = 4, p = 4;
    printf("%d\n", findMinofTrip(A, m, B, n, C, p));
    return 0;
}