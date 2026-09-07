#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;   //定义顺序表

SeqList L;   //声明顺序表

void InitList(SeqList *L) { 
    L->length = 0;         //初始化顺序表长度为0
}    //结构体指针变量   初始化顺序表

int main(void) {
    InitList(&L);   
    printf("顺序表初始化完成，当前长度为：%d\n", L.length);
    printf("目前占用内存%zu字节\n", sizeof(L.data));
    return 0;
}