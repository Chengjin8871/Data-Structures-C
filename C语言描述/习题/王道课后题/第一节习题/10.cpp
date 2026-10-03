#include <stdio.h>
typedef int ElemType;
int p;
void Reverse(ElemType R[], int left, int right, int n){
    int mid = (left + right)/2;
    //for (int i = 0; i < (right-left+1)/2; i++){
    for (int i = 0; i <= mid-left; i++){
        int temp = R[right-i];
        R[right-i] = R[left+i];
        R[left+i] = temp;
    }
}

void Rotate(ElemType R[], int left, int right, int n){
    Reverse(R, 0, p-1, n);
    Reverse(R, p, n-1, n);
    Reverse(R, 0, n-1, n);
}
int main(){
    ElemType R[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    p = 5;
    Rotate(R, 0, n-1, n);
    for (int i = 0; i < n; i++){
        printf("%d ", R[i]);
    }
    return 0;
}