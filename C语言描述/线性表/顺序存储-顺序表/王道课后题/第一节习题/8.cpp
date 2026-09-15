r  #include <stdio.h>
typedef int ElemType;

bool SearchExchange(ElemType a[], int n, ElemType x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            if (mid != n - 1) {
                ElemType temp = a[mid];
                a[mid] = a[mid + 1];
                a[mid + 1] = temp;
            }
            return true;
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
i
    for (int i = n - 1; i >= low; --i) {
        a[i + 1] = a[i];
    }
    a[low] = x;
    return true;
}

int main(void) {
    int a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    int n = 10;
    int x = 11;

    SearchExchange(a, n, x);

    for (int i = 0; i < n + 1; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}