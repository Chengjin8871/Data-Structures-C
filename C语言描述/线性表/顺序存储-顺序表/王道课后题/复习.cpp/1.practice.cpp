#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;   
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;
bool Del_x(SeqList &L, ElemType &min) {
        min=L.data[0];
        int pos,i;                           
    for(i=1;i<L.length;i++)
        if(L.data[i]<min)
            {min=L.data[i];
                pos=i;}
L.data[pos]=L.data[L.length-1];
L.length--;
return true;
} 
int main(){
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
    ElemType min;
    Del_x(L,min);
    printf("删除最小值后的顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}