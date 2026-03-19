#include <stdio.h>
#include <stdlib.h>

struct judet{
    int nr;
    int nrora;
    int *v;
};

int cmp(const void *a, const void *b){
    const struct judet *ja = (const struct judet *)a;
    const struct judet *jb = (const struct judet *)b;

    if (ja->nrora==jb->nrora)
        return ja->nr-jb->nr;
    return jb->nrora-ja->nrora;
}

int main(){
    FILE* fin=fopen("file.in","r");
    FILE* fout=fopen("file.out","w");
    int n,m,rez=0;

    fscanf(fin,"%d %d",&n,&m);

    struct judet *jud=malloc(m*sizeof(struct judet));
    int *folos = calloc(n+1, sizeof(int));

    for(int i=0;i<m;i++){
        int nro;
        fscanf(fin,"%d",&nro);
        jud[i].nrora=nro;
        jud[i].nr=i+1;
        jud[i].v = calloc(n+1, sizeof(int));
        for(int j=1;j<=nro;j++){
            int x;
            fscanf(fin,"%d",&x);
            jud[i].v[x]=1;
        }
    }

    int totfol=0;
    while(totfol==0){
        rez++;
        ///SORTARE
        qsort(jud,m,sizeof(struct judet),cmp);
        ///STERGERE ORASE din lista si din judet
        fprintf(fout,"J%d ",jud[0].nr);
        for(int j=1;j<=n;j++){
            if(jud[0].v[j]==1)
                folos[j]=1;
        }
        jud[0].nrora=0;
        ///STERGEM ORASELE FOLOSITE DIN TOATE JUDETELE
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++){
                if(folos[j]==1 &&  jud[i].v[j]==1){
                    jud[i].v[j]=0;
                    jud[i].nrora--;
                }
            }
        }
        ///VERIFICARE
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(folos[i]==1)
                cnt++;
        }
        if(cnt==n)
            totfol=1;
    }
    fprintf(fout,"\n%d\n",rez);

    fclose(fin);
    fclose(fout);
    free(folos);
    for(int i=0;i<m;i++){
        free(jud[i].v);
    }
    free(jud);
    return 0;
}
