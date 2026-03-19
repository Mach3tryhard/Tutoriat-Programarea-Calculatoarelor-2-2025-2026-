#include <stdio.h>

int v[10];

int cifdif(int n){
    if(n > -1){
        v[n%10]++;
        cifdif(n/10);
    }
    return 0;
}

int parc(int n,int i){
    if(i<n){
        if(v[i]>0)
            return 1 + parc(n,i+1);
    }
    return 0;
}

int rec(){
    int nr;
    scanf("%d",&nr);
    for(int i=0;i<10;i++)v[i]=0;
    cifdif(nr);
    int kon=parc(nr,0);
    printf("%d ",kon);
    if(nr==0)
        return 0;
    rec();
}

int main(){
    rec();
    return 0;
}
