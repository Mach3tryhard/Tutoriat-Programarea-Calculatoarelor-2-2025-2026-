#include <stdio.h>

int v[1000];

int main(){
    int n,m,nr;
    scanf("%d %d %d",&n,&m,&nr);
    for(int i=1;i<=nr;i++){
        scanf("%d",&v[i]);
    }
    int kon=0,aj=0;
    for(int i=1;i<=nr;i++){
        int j=i;
        while(v[j]<=aj+m && j<=nr){
            j++;
        }
        j--;
        if(j<i){
            printf("NU se poate!");
            return 0;
        }
        printf("%d ",j);
        aj=v[j];
        i=j;
    }
    return 0;
}
