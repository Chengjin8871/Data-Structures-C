#include <stdio.h>
#include <stdlib.h>

#define InitSize 100

typedef int ElemType;

typedef struct {
    ElemType *data;  // 动态数组首地址
    int length;      // 当前长度
    int MaxSize;     // 最大容量
} SeqList;  // 定义顺序表

void InitList(SeqList &L) {
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));   
    if (L.data == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    L.length = 0;
    L.MaxSize = InitSize;
}

void ListInsert(SeqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        printf("插入位置非法\n");
        return;
    }
    if (L.length >= L.MaxSize) {
        ElemType *newData = (ElemType *)realloc(L.data, (L.MaxSize + InitSize) * sizeof(ElemType));
        if (newData == NULL) {
            printf("扩容失败\n");
            return;
        }
        L.data = newData;
        L.MaxSize += InitSize;
    }

    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
}

int main(void) {
    SeqList L;
    InitList(L);

    printf("顺序表初始化完成，当前长度为：%d\n", L.length);
    printf("顺序表最大容量为：%d\n", L.MaxSize);
    printf("当前数据区大小为：%zu字节\n", (size_t)L.MaxSize * sizeof(ElemType));

    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);

    printf("插入元素后，顺序表长度为：%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("L.data[%d] = %d\n", i, L.data[i]);
    }

    free(L.data);
    return 0;
}