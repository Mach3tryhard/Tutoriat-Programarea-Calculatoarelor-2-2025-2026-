#include <stdio.h>

int ex1(int n){
    if(n==1)
        return 1;
    else
        return ex1(n-1)+3*n-2;
}

int main(){
    int n;
    scanf("%d",&n);
    int rez=ex1(n);
    printf("%d",rez);
    return 0;
}
