#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct info{
    int min,vine;
};

//struct info v[10005];
//int sol[10005];

int minim(int a,int b){
    if(a<=b)
        return a;
    else
        return b;
}

int main(){
    FILE *fin=fopen("test.in","r");
    FILE *fout=fopen("test.out","w");
    int n;
    fscanf(fin,"%d",&n);
    struct info *v=malloc((n+1)*sizeof(struct info));
    int *sol=malloc((n+1)*sizeof(int));

    ///---CALCULARE---
    v[1].min=0;
    v[1].vine=1;
    for(int i=2;i<=n;i++){a
        v[i].min=INT_MAX;
        v[i].vine=0;
    }
    for(int i=2;i<=n;i++){
        if(v[i].min>v[i-1].min+1){           ///+1
            v[i].min = minim(v[i-1].min+1,v[i].min);
            v[i].vine = i-1;
        }
        if(i%2==0 && v[i].min>v[i/2].min+1){ ///*2
            v[i].min = minim(v[i/2].min+1,v[i].min);
            v[i].vine = i/2;
        }
        if(i%3==0 && v[i].min>v[i/3].min+1){ ///*3
            v[i].min = minim(v[i/3].min+1,v[i].min);
            v[i].vine = i/3;
        }
    }

    ///---DEBUG---
    /*for(int i=1;i<=n;i++){
        fprintf(fout,"numarul:%d minim:%d vine:%d\n",i,v[i].min,v[i].vine);
    }
    fprintf(fout,"\n");*/

    ///---SOLUTIE---
    int m=v[n].min,k=n;
    fprintf(fout,"%d\n",m);
    for(int i=n;i>=1;i--){
        if(i==k){
            sol[m]=k;
            m--;
            k=v[i].vine;
        }
    }
    for(int i=0;i<=v[n].min;i++){
        fprintf(fout,"%d ",sol[i]);
    }

    free(sol);
    free(v);
    fclose(fin);
    fclose(fout);
    return 0;
}
