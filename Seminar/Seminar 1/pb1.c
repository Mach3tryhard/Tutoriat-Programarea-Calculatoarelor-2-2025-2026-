#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nr_ord;
    int nr_albe;
    int nr_negre;
    char culoare;
}Pitic;

int N;
Pitic *v;

void citire ()
{
    FILE *f=fopen("pitici.in","r");
    if (!f) {
        printf("eroare la deschidere");
        free(v);
        exit(0);
    }
    fscanf(f,"%d",&N);
    v=(Pitic*)malloc(N*sizeof(Pitic));
    for (int i=0; i<N; ++i) {
            fscanf(f,"%d %d",&v[i].nr_albe,&v[i].nr_negre);
            v[i].nr_ord=i+1;
    }
    fclose(f);
}

void stabilire_culoare ()
{
    int cate_albe=0,cate_negre=0;
    for (int i=0; i<N; ++i) {
        if (v[i].nr_negre==cate_negre&&v[i].nr_albe==cate_albe) {
            v[i].culoare='A';
            ++cate_albe;
    }
    else {
        v[i].culoare='N';
        ++cate_negre;
    }
    }
}

int reordonare ()
{
    int cate_albe=0,cate_negre=0;
    for (int i=0; i<N; ++i) {
        int ok=0;
        for (int j=i; j<N&&!ok; ++j) {
            if (v[j].nr_albe==cate_albe&&v[j].nr_negre==cate_negre) {
                Pitic aux;
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
                ok=1;
                if (v[i].culoare=='A') ++cate_albe;
                else ++cate_negre;
            }
        }
        if (!ok) return 0;
    }
    return 1;
}

void afisare ()
{
    for (int i=0; i<N; ++i) {
        printf("%d %c\n",v[i].nr_ord,v[i].culoare);
    }
}

int main()
{
    citire();
    stabilire_culoare();
    afisare();
    printf("\n");
    if (reordonare()==1) afisare();
    else printf("Imposibil");
    free(v);
    return 0;
}
