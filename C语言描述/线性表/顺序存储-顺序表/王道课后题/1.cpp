#include<stdio.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;

int main(void){
    SeqList L;
    L.length=5;
    for(int i=0;i<L.length;i++){
        L.data[i]=i+1;
    }
    printf("原顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    for(int i=0;i<L.length/2;i++){
        ElemType temp=L.data[i];
        L.data[i]=L.data[L.length-1-i];
        L.data[L.length-1-i]=temp;
    }
    printf("逆置后的顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    return 0;
}