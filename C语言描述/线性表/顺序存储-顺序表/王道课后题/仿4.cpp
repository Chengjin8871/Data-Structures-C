#include <stdio.h>
#define MaxSize 100

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

bool Del_s_t(SeqList &L, ElemType s, ElemType t) {
    int i, k = 0;
    if (L.length == 0 || s >= t)
        return false;

    for (i = 0; i < L.length; i++) {
        if (L.data[i] < s || L.data[i] > t) {
            L.data[k++] = L.data[i];
        }
    }

    L.length = k;
    return true;
}

int main(int argc, char *argv[]) {
    SeqList L;
    L.length = 8;
    for (int i = 0; i < L.length; i++) {
        L.data[i] = i + 1;
    }

    printf("原顺序表为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    Del_s_t(L, 3, 6);
    printf("删除[3,6]后，顺序表为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return 0;
}