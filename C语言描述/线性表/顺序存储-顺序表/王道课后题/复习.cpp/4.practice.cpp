#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;   
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;
bool Del_s_t( SeqList &L, ElemType s, ElemType t){
	if(L.length==0||s>=t)
		return false;
	int k=0,i;
	for(i=0;i<L.length;i++){
		if(L.data[i]>t||L.data[i]<s)
			L.data[k++]=L.data[i];
	}
	L.length=k;
	return true;
}
int main(){
    SeqList L;
    L.length=10;
    ElemType values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < L.length; i++) {
        L.data[i] = values[i];
    }
    printf("原顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    ElemType s=3,t=7;
    Del_s_t(L,s,t);
    printf("删除指定范围后的顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}