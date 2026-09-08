#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;  // 定义顺序表

bool InitList(SeqList &L) {
    L.length = 0;  // 初始化顺序表长度为 0
    return true;
}  // 结构体引用变量，初始化顺序表

bool ListInsert(SeqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return false;  // 判断插入位置是否合法
    if (L.length >= MAXSIZE) return false;         // 判断顺序表是否已满

    for (int j = L.length; j >= i; j--) {  // 将插入位置之后的元素后移
        L.data[j] = L.data[j - 1];
    }

    L.data[i - 1] = e;  // 在第 i 个位置插入元素 e
    L.length++;         // 顺序表长度加 1
    return true;
}

int main(void) {
    SeqList L;  // 声明顺序表
    InitList(L);
    printf("顺序表初始化完成，当前长度为：%d\n", L.length);
    printf("目前占用内存 %zu 字节\n", sizeof(L.data));

    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);

    printf("插入元素后，顺序表长度为：%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("L.data[%d] = %d\n", i, L.data[i]);
    }

    return 0;
}