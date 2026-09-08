#include<stdio.h>
typedef int ElemType;
#define MaxSize 100;
typedef struct{
    int length;
    ElemType data[MaxSize];
}SeqList;
SeqList L;
void InitList(SeqList &L){
    L.length=0;
}
void ListDelete(SeqList &L,ElemType e){
    int i,k=0;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            k++;
        }
    else
        L.data[i-k]=L.data[i];
    }
L.length=L.length-k;
}
int main(void){
    InitList(L);
    L.length=5;
    for(int i=0;i<L.length;i++){
        L.data[i]=i+1;
    }
    printf("原顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    ListDelete(L,3);
    printf("删除元素3后，顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    return 0;
}
    