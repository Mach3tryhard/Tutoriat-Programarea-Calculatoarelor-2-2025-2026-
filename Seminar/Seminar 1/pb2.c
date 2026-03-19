#include <stdio.h>
#include <stdlib.h>

void afisare(int n,int* v){
    for (int i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");
}

void citire(int *an, int **av){
    FILE *in=fopen ("date.in","r");
fscanf(in,"%d",an);

*av=(int*)malloc((*an)*sizeof(int));

for (int i=0;i<*an;i++){
    fscanf(in,"%d",&(*av)[i]);//(*av)+i
}
fclose (in);
}

void incrementare (int n,int *v,int x){
for(int i=0;i<n;i++)
    if (v[i]==x) v[i]++;
}
void eliminare(int *an,int **av,int x)
{
    int liber=0;
    for (int i=0;i<*an;i++)
    {
        if ((*av)[i]!=x)
        {
            (*av)[liber]=(*av)[i];
            liber++;
        }
    }
    *an=liber;
    *av=(int *)realloc(*av,(*an)*sizeof(int ));
}
void adaugare(int *an,int **av,int x)
{
     int liber=0;
     int nr_zero=0;
     for(int i = 0 ; i < *an ; i++)
        if((*av)[i]==x)nr_zero++;
     *av=(int *)realloc(*av,((*an)+nr_zero)*sizeof(int ));
     liber = (*an) + nr_zero - 1;
     for(int i = *an - 1; i >= 0 ; --i)
     {
         if((*av)[i]==x)(*av)[liber--]=0;
         (*av)[liber--]=(*av)[i];
     }
     *an = (*an) + nr_zero;
}
int main()
{
    int n,*v;
    citire (&n,&v);
    afisare (n,v);
    incrementare(n,v,3);
    afisare(n,v);
   // eliminare(&n,&v,4);
    adaugare(&n, &v, 4);
    afisare(n,v);
    free(v);
    return 0;
}
