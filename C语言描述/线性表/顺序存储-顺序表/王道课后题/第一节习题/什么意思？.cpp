#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;

bool SearchExchangeInsert(SeqList &L, ElemType e) {
    int i = 0;

    while (i < L.length && L.data[i] < e) {
        i++;
    }

    if (i < L.length && L.data[i] == e) {
        if (i + 1 < L.length) {
            ElemType tmp = L.data[i];
            L.data[i] = L.data[i + 1];
            L.data[i + 1] = tmp;
        }
        return true;
    }

    if (L.length >= MAXSIZE) {
        return false;
    }

    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i] = e;
    L.length++;
    return true;
}

int main(void) {
    SeqList L;
    L.length = 5;
    for (int i = 0; i < L.length; i++) {
        L.data[i] = i + 1;
    }

    ElemType e = 3;
    SearchExchangeInsert(L, e);

    printf("顺序表为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}

