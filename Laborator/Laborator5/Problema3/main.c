#include <stdlib.h>
#include <stdio.h>

int cmmd(int a,int b){
    if(b==0)
        return a;
    return cmmd(b,a%b);
}

int rec(int n,int v[],int d,int i){
    if(i==n-1)
        return 0;
    if(cmmd(v[i],v[i+1])==d){
        printf("(%d,%d)\n",v[i],v[i+1]);
    }
    rec(n,v,d,i+1);
}

int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int *v=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    rec(n,v,d,0);
    return 0;
}
