#include <stdio.h>
#define MaxSize 100
typedef int ElemType;
typedef struct{
    int length;
    ElemType data[MaxSize];
}SeqList;
bool Merge(SeqList &La,SeqList &Lb,SeqList &Lc){
    if(La.length+Lb.length>MaxSize)
        return false;
    int i=0,j=0,k=0;
    while(i<La.length&&j<Lb.length){
        if(La.data[i]<=Lb.data[j])
            Lc.data[k++]=La.data[i++];
        else
        Lc.data[k++]=Lb.data[j++];
    }
    while(i<La.length)
         Lc.data[k++]=La.data[i++];
    while(j<Lb.length)
         Lc.data[k++]=Lb.data[j++];
    Lc.length=k;
    return true;
}
int main(void){
    SeqList La,Lb,Lc;
    La.length=5;
    for(int i=0;i<La.length;i++)
        La.data[i]=i+1;      // 1 2 3 4 5
    Lb.length=3;
    for(int i=0;i<Lb.length;i++)
        Lb.data[i]=i+4;      // 4 5 6
    Merge(La,Lb,Lc);
    printf("Lc顺序表为：");
    for(int i=0;i<Lc.length;i++)
        printf("%d ",Lc.data[i]);
    printf("\n");
    return 0;
}