#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **a;

void allocate_matrix(int n, int m) {
	a = (int **)malloc((n + 5) * sizeof(int *));
	for (int i = 0; i <= n; i++) {
		a[i] = (int *)malloc((m + 5) * sizeof(int));
	}
}

void free_matrix(int n) {
	for (int i = 0; i <= n; i++) {
		free(a[i]);
	}
	free(a);
}

int cax,cay,cbx,cby,n,m,gasit=0;

void set1(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            a[i][j]=1;
        }
    }
}

void fill(int x,int y,int start){
    int f[4]={0,0,0,0};
    if((x>0 && y>0 && x<n && y<m && gasit==0) || start==1){
        if(x==cbx && y==cby)
            gasit=1;
        a[x][y]=0;
        int loop=1;
        while(loop){
            loop=0;
            for(int i=0;i<4;i++){
                if(f[i]==0)
                    loop=1;
            }
            srand(clock());
            int ran = rand()%4;
            if(f[ran]==0){
                if(ran==0 && x+2<n && a[x+2][y]==1){
                    a[x+1][y]=0;
                    fill(x+2,y,0);
                }
                if(ran==1 && y+2<m && a[x][y+2]==1){
                    a[x][y+1]=0;
                    fill(x,y+2,0);
                }
                if(ran==2 && x-2>0 && a[x-2][y]==1){
                    a[x-1][y]=0;
                    fill(x-2,y,0);
                }
                if(ran==3 && y-2>0 && a[x][y-2]==1){
                    a[x][y-1]=0;
                    fill(x,y-2,0);
                }
            }
            f[ran]=1;
        }
    }
}

int main(){
    FILE *fin=fopen("test.in","r");
    FILE *fout=fopen("test.out","w");
    fscanf(fin,"%d %d %d %d",&cax,&cay,&cbx,&cby);
    fscanf(fin,"%d %d",&n,&m);
    allocate_matrix(n, m);
    set1();
    for(int i=0;i<=n;i++) a[i][0]=2;
    for(int i=0;i<=m;i++) a[0][i]=2;
    for(int i=0;i<=m;i++) a[n][i]=2;
    for(int i=0;i<=n;i++) a[i][m]=2;
    a[cbx][cby]=0;
    fill(cax,cay,1);
    if(cbx==n)
        a[cbx-1][cby]=0;
    if(cby==m)
        a[cbx][cby-1]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            fprintf(fout,"%d ",a[i][j]);
        }
        fprintf(fout,"\n");
    }
    fclose(fin);
    fclose(fout);
    free_matrix(n);
    return 0;
}
