#include <stdlib.h>
#include <stdio.h>

int rec(int v[],int n){
    if(n==-1)
        return 0;
    if(v[n]<0)
        return 1+rec(v,n-1);
    if(v[n]>0)
        return rec(v,n-1);
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int *v=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    int kon=rec(v,n-1);
    printf("%d",kon);
    free(v);
    return 0;
}
