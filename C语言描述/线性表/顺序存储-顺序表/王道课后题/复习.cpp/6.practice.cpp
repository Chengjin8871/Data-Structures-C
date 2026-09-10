#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;   
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;
bool Merge(SeqList &La,SeqList &Lb,SeqList &Lc){
    if (La.length + Lb.length > MAXSIZE)
        return false;

    int i = 0, j = 0, k = 0;
    while (i < La.length && j < Lb.length) {
        if (La.data[i] <= Lb.data[j])
            Lc.data[k++] = La.data[i++];
        else
            Lc.data[k++] = Lb.data[j++];
    }

    while (i < La.length)
        Lc.data[k++] = La.data[i++];
    while (j < Lb.length)
        Lc.data[k++] = Lb.data[j++];

    Lc.length = k;
    return true;
}

int main(){
    SeqList La,Lb,Lc;
    La.length=5;
    Lb.length=5;
    ElemType valuesA[] = {1, 3, 5, 7, 9};
    ElemType valuesB[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < La.length; i++) {
        La.data[i] = valuesA[i];
    }
    for (int i = 0; i < Lb.length; i++) {
        Lb.data[i] = valuesB[i];
    }
    Merge(La,Lb,Lc);
    printf("合并后的顺序表为：");
    for(int i=0;i<Lc.length;i++){
        printf("%d ",Lc.data[i]);
    }
    printf("\n");
}