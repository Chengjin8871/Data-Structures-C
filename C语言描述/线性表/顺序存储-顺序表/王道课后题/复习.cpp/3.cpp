#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;   
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;
bool Del_x_1(SeqList &L,ElemType x){
	if(L.length==0) return false;
	int i,k=0;
	for(i=0;i<L.length;i++){
		if(L.data[i]==x)  
		k++;
		else
		L.data[i-k]=L.data[i];
	}
	L.length-=k;
	return true;
}
int main(){
    SeqList L;
    L.length=10;
    ElemType values[] = {1, 2, 3, 3, 5, 6, 3, 8, 3, 3};
    for (int i = 0; i < L.length; i++) {
        L.data[i] = values[i];
    }
    printf("原顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    ElemType x=3;
    Del_x_1(L,x);
    printf("删除指定值后的顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
