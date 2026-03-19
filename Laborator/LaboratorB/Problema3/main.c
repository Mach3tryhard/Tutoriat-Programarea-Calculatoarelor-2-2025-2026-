#include <stdio.h>

int mink=1,maxk,s[100005],vf[100005],n;

int solpart(int k){
    int sum=0;
    for(int i=0;i<=k;i++){
        sum+=s[i];
        if(vf[s[i]]>1)
            return 0;
    }
    if(sum<=n)
        return 1;
    return 0;
}

int solfin(int k){
    int sum=0;
    for(int i=0;i<=k;i++){
        sum+=s[i];
        if(vf[s[i]]>1)
            return 0;
    }
    if(sum==n)
        return 1;
    return 0;
}

void afis(int k){
    for(int i=0;i<=k;i++){
        printf("%d ",s[i]);
    }
    printf("\n");
}

void bkt(int k){
    maxk=n-k+1;
    for(int i=mink;i<=maxk;i++){
        s[k]=i;
        vf[i]++;
        if(solpart(k)==1){
            if(solfin(k)==1){
                afis(k);
            }
            else {
                bkt(k+1);
            }
        }
        vf[i]--;
    }
}

int main(){
    scanf("%d",&n);
    maxk=n;
    bkt(0);
    return 0;
}
