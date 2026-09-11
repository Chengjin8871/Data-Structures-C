#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;   //定义顺序表
void Del_Min(SeqList &L) {
    if (L.length == 0) {
        printf("顺序表为空，无法删除最小值\n");
        return;
    }
    int minIndex = 0,min=L.data[0];
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] < L.data[minIndex]) {
            minIndex = i;
            min = L.data[i];
        }
    }
    for (int j = minIndex; j < L.length - 1; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
}
int main() {
    SeqList L;
    L.length = 5;
    for (int i = 0; i < L.length; i++) {
        L.data[i] = i + 1;
    }
    printf("原顺序表为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    
    Del_Min(L);
    printf("删除最小值后的顺序表为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return 0;
}