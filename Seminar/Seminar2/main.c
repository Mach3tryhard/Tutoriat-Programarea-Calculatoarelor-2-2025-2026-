
#include <stdio.h>
#include <stdlib.h>

void afiseazaElemente(int NL, int NC, int** mat){
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void citireElemente(int *aNL, int *aNC, int ***amat){
    FILE *f;
    f=fopen("text.txt","r");
    fscanf(f,"%d %d",aNL,aNC);
    *amat= (int**)malloc((*aNL)*sizeof(int*));
    for(int i=0;i<(*aNL);i++){
        (*amat)[i]= (int*)malloc((*aNC)*sizeof(int));
        //*(*amat + i)=
        for(int j=0;j<(*aNC);j++){
            fscanf(f,"%d",&(*amat)[i][j]);
            // *(*amat +i)+j
        }
    }
}
int vecini(int NL, int NC, int **mat){
    int nr=0, ok=1;
    for(int i=0;i<NL;i++){
        for(int j=0;j<NC;j++){
            if(mat[i][j] %2==0){
                ok=1;
                if(i+1<NL && mat[i+1][j] %2 ==0)ok=0;
                if(i-1>=0 && mat[i-1][j] %2 ==0)ok=0;              
                if(j+1<NC && mat[i][j+1] %2 ==0)ok=0;
                if(j-1>=0 && mat[i][j-1] %2 ==0)ok=0;
            }
            if(ok == 1)nr++;
        }
    }
    return nr;
}
void stegereLinie (int *aNL, int NC, int ***amat, int k )
{
    free((*amat)[k]);
    for (int i=k+1;i<*aNL;i++)
        (*amat)[i-1]=(*amat)[i];
    (*aNL)--;
    *amat=(int **)realloc(*amat,(*aNL)*sizeof(int *));
}
void stergereColoana (int NL,int *aNC,int **mat, int k)
{
    for (int i=0;i<NL;i++)
    {
        for (int j=k+1;j<*aNC;j++)
            mat[i][j-1]=mat[i][j];
        mat[i]=(int **)realloc(mat[i],((*aNC)-1)*sizeof(int));
    }
    (*aNC)--;
}

void inserarelinie(int *aNL, int NC, int ***amat, int k)
{
    *amat=(int**)realloc(*amat,((*aNL)+1)*sizeof(int*));
    for(int i=*aNL-1;i>=k+1;i--)
    {

    (*amat)[i+1]=(*amat)[i];    
    }
    (*amat)[k+1]=(int*)calloc(NC, sizeof(int));
    (*aNL)++;
}

void inserarecoloana(int NL, int *aNC, int **mat, int k)
{
    for(int i=0;i<NL;i++)
    {
        mat[i]=(int*)realloc(mat[i],((*aNC)+1)*sizeof(int));
        for(int j=*aNC-1;j>=k+1;j--)
        {
            mat[i][j+1]=mat[i][j];
        }
    
        mat[i][k+1]=0;
    }
    (*aNC)++;
}
int main(){
    int n,m;
    int **a;
    citireElemente(&n,&m, &a);
    afiseazaElemente(n,m, a);
    printf("%d \n", vecini(n,m,a));
    stegereLinie(&n,m,&a,6);
    afiseazaElemente(n,m,a);
    stergereColoana(n,&m,a,3);
    afiseazaElemente(n,m,a);
    inserarelinie(&n,m,&a,2);
    afiseazaElemente(n,m, a);
    inserarecoloana(n,&m, a, 3);
    afiseazaElemente(n,m, a);
    for(int i=0;i<n;i++){
        free(a[i]);
    }
    
    free(a);
}