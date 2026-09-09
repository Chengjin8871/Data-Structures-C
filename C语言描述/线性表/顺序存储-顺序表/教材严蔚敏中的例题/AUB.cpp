#include <stdio.h>
#define MaxSize 100

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

bool GetElem(SeqList L, int i, ElemType *e) {
    if (i < 0 || i >= L.length) return false;
    *e = L.data[i];
    return true;
}

int LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i;  //一旦找到元素，立即返回其下标并终止该函数后面的所有操作
    }
    return -1;
}

bool ListInsert(SeqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1 || L.length >= MaxSize) return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

void Union(SeqList &La, SeqList &Lb) {
    ElemType e;
    for (int i = 0; i < Lb.length; i++) {
        GetElem(Lb, i, &e);
        if (LocateElem(La, e) == -1) {
            ListInsert(La, La.length + 1, e);
        }
    }
}

int main(void) {
    SeqList La, Lb;
    La.length = 5;
    for (int i = 0; i < La.length; i++) {
        La.data[i] = i + 1;      // 1 2 3 4 5
    }

    Lb.length = 3;
    for (int i = 0; i < Lb.length; i++) {
        Lb.data[i] = i + 4;      // 4 5 6
    }

    printf("La顺序表为：");
    for (int i = 0; i < La.length; i++) {
        printf("%d ", La.data[i]);
    }
    printf("\n");

    printf("Lb顺序表为：");
    for (int i = 0; i < Lb.length; i++) {
        printf("%d ", Lb.data[i]);
    }
    printf("\n");

    Union(La, Lb);
    printf("合并后的顺序表为：");
    for (int i = 0; i < La.length; i++) {
        printf("%d ", La.data[i]);
    }
    printf("\n");

    return 0;
}
