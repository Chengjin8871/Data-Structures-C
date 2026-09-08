#include <stdio.h>
#define MaxSize 100
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;
void ListDelete(SeqList &L, ElemType x) {
    int k = 0, i;   
    while( i <L.length)
{
        if(L.data[i] != x) {
            L.data[k++] = L.data[i];
        
        }i++;
    }
    L.length = k;
}

int main(void) {
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

    ListDelete(L, 3);
    printf("删除元素3后，顺序表为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return 0;
}

