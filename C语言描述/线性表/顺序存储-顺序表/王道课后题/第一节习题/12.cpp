#include <stdio.h>
typedef int ElemType;
int Majority(ElemType A[], int n){
    int i,k=0;
    int c = A[0];
    for(i=1;i<n;i++){
        if(A[i]==c)
            k++;
        else{
            if(k>0)
                k--;
            else{
                c = A[i];
                k = 1;  
            }
        }

    }
if(k > 0)   {
    for(k=0;k<n;k++){
        if(A[k] == c)
            k++;}
        if(k > n/2)
            return c;
        //else
            return -1;
    }
}
int main(){
    ElemType A[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int n = 9;
    printf("%d\n", Majority(A, n));
    return 0;
}