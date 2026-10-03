#include <stdio.h>

typedef int ElemType;

int M_Search(ElemType A[], ElemType B[], int n) {
    int s1 = 0, d1 = n - 1;
    int s2 = 0, d2 = n - 1;

    while (s1 <= d1 && s2 <= d2) {
        int m1 = (s1 + d1) / 2;
        int m2 = (s2 + d2) / 2;

        if (A[m1] == B[m2]) {
            return A[m1];
        }

        if (A[m1] < B[m2]) {
            s1 = m1 + 1;
e            d2 = m2;
        } else {
            s2 = m2 + 1;
            d1 = m1;
        }
    }

    if (s1 > d1) return B[s2];
    if (s2 > d2) return A[s1];

    return A[s1] > B[s2] ? A[s1] : B[s2];
}

int main() {
    ElemType A[] = {1, 3, 5, 7, 9};
    ElemType B[] = {2, 4, 6, 8, 10};
    int n = 5;

    printf("%d\n", M_Search(A, B, n));
    return 0;
}
    
