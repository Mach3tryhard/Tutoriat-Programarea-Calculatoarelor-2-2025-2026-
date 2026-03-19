#include <stdio.h>

int suma=0;

int divimp(int v[],int i,int j){
    int mij1=j/3+1;
    int mij2=2*j/3;
    if(j<=i)
        return v[j];
    else{
        int par1=divimp(v,i,mij1);
        int par2=divimp(v,mij1,mij2);
        int par3=divimp(v,mij2,j);
        return par1+par2+par3;
    }
}

int main(){
    int n,v[1005];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    suma = divimp(v,0,n-1);
    printf("%d",suma);
    return 0;
}
