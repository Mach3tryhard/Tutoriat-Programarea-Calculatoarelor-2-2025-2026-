#include <stdio.h>
#include <stdlib.h>

int gasit=0;

int divimp(int v[],int st,int dr,int x){
    if(st==dr){
        if(v[st]==x){
            printf("%d ",st);
            return 1;
        }
        return 0;
    }
    else{
        int mij=(st+dr)/2;
        int nr1=divimp(v,st,mij,x);
        int nr2=divimp(v, mij+1,dr,x);
        return nr1+nr2;
    }
    return 0;
}

int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int *v=malloc(n*sizeof(n));
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    gasit=divimp(v,0,n-1,x);
    if(gasit==0)
        printf("Nu exista");
    free(v);
    return 0;
}
