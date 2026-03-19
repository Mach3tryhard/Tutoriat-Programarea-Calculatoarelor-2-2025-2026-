#include <stdio.h>

int frum[10005];

int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int main(){
    int n;
    scanf("%d",&n);
    frum[0]=1;
    int i2=0,i3=0,i5=0;
    int n2=2,n3=3,n5=5;
    for(int i=0;i<n;i++){
        int minim=min(min(n2,n3),n5);
        if(minim==n2){
            i2++;
            n2=frum[i2]*2;
        }
        if(minim==n3){
            i3++;
            n3=frum[i3]*3;
        }
        if(minim==n5){
            i5++;
            n5=frum[i5]*5;
        }
        for(int j=0;j<n;j++){
            printf("%d ",frum[j]);
        }
    }
    return 0;
}
