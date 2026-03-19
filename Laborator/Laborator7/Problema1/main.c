#include <stdio.h>
#include <stdlib.h>


int cmmdc(int a,int b){
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int divimp(int v[],int st,int dr){
    if(st==dr)
        return v[st];
    if(dr-st==1)
        return cmmdc(v[st],v[dr]);
    int mij=st+(dr-st)/2;
    return cmmdc(divimp(v,st,mij),divimp(v,mij,dr));
}

int main(){
    int n;
    scanf("%d",&n);
    int *v = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    int rez=divimp(v,0,n-1);
    printf("%d",rez);
    return 0;
}
