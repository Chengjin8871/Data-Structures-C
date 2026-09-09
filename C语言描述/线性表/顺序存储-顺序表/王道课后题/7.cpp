#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;
void Reverse(ElemType a[], int left, int right, int arraysize) {
    if(left>=right || left<0 || right>=arraysize)
    return;
    int mid = (left + right) / 2;
    for(int i=0;i<=mid-left;i++)
    {
        ElemType tmp = a[left+i];
        a[left+i] = a[right-i];
        a[right-i] = tmp;
    }
}
void Exchange(ElemType a[], int m, int n, int arraysize) {
    Reverse(a, 0, m-1, arraysize);
    Reverse(a, m, n-1, arraysize);
    Reverse(a, 0, n-1, arraysize);
}
       int main( int argc, char *argv[]) {
    return 0;               
       }
    
