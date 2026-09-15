#include <stdio.h>
typedef int ElemType;
bool Reverse( ElemType a[], int left, int right, int arraysize) {
    if(left >= right || right >= arraysize )      //arraysize表示数组可以存放的元素个数  right表示数组下标
        return false;
    int mid = (left + right) / 2;
    for(int i = 0; i <= mid - left; i++) {
        int temp = a[left + i];
        a[left + i] = a[right - i];
        a[right - i] = temp;
    }
    return true;
}
void Exchange( ElemType a[], int m, int n, int arraysize) {
    Reverse(a, 0, m-1, arraysize);
    Reverse(a, m, m+n-1, arraysize);
    Reverse(a, 0, m+n-1, arraysize);
}
int main(void) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = 3; //前m个元素
    int n = 7; //后n个元素
    Exchange(a, m, n, sizeof(a)/sizeof(a[0]));
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    return 0;
}