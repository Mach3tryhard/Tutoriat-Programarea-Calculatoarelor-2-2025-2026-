#include <stdio.h>
#include <stdlib.h>

int suma=0,n;

int max(int a,int b){
    if(a>=b)
        return a;
    else
        return b;
}

int divimp(int v[],int st,int dr){
    if(st==dr){
        return v[st];
    }
    else{
        int mij=(st+dr)/2;
        int max1=divimp(v,st,mij);
        int max2=divimp(v, mij+1,dr);
        return max(max1,max2);
    }
}

int main(){
    scanf("%d",&n);
    int *v=malloc(n*sizeof(n));
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    suma = divimp(v,0,n-1);
    printf("%d",suma);
    free(v);
    return 0;
}
