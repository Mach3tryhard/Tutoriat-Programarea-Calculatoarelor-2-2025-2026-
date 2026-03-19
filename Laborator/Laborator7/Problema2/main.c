#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int divimp(int v[],int st,int dr){
    if(st==dr)
        return v[st];
    if(dr-st==1)
        return v[st]+v[dr];
    int mij=st+(dr-st)/2;
    return max(divimp(v,st,mij)+divimp(v,mij+1,dr),max(divimp(v,st,mij),divimp(v,mij+1,dr)));
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
