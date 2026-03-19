#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int a[1000][1000];
int v[1000][1000];

void set0(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			a[i][j]=0;
			v[i][j]=0;
		}
	}
}

int main(){
	srand(time(NULL));
    char s[100][100];
    FILE* fout[11];
	for(int i=3;i<=10;i++){
		set0();
		srand(time(NULL));
	    ///FISIER
	    sprintf(s[i], "test%d.in", i);
	    fout[i]=fopen(s[i],"w+");
		///AFLARE INTERVAL
		int ba=10;
		int ab=1;
		///RANDOM NUMBER
		srand(clock());
		int n = rand()%(ba-ab)+ab;
		int m = rand()%(ba-ab)+ab;
		for(int j=1;j<=m;j++){
            v[j][0]=1;
		}
		fprintf(fout[i],"%d %d \n",n,m);
		
		///MA ASIGUR CA AM TOATE ORASELE MACAR ODATA
		for(int j=1;j<=n;j++){
			int Jptoras = rand()%n+1;
			a[Jptoras][0]++;
			a[Jptoras][a[Jptoras][0]]=j;
			v[Jptoras][j]=1;
		}
		///GENEREZ RESTUL DE ORASE ALEATORII CU NUMAR ALEATORIU PE JUDET
		for(int j=1;j<=m;j++){
			int d=rand()%(n)+1;
			if(d==0)d=1;
			if(d<a[j][0])
                d=a[j][0];
			for(int k=a[j][0];k<d;k++){
				int nextnr = 0;
				while(v[j][nextnr]==1){
					nextnr = rand()%n+1;
					if(v[j][nextnr]==0){
						v[j][nextnr]=1;
						break;
					}
				}
                a[j][0]++;
				a[j][a[j][0]]=nextnr;
			}
		}
		///PRINTEZ MATRICEA GENERATA
		for(int j=1;j<=m;j++){
			for(int k=0;k<=a[j][0];k++){
				fprintf(fout[i],"%d ",a[j][k]);
			}
			fprintf(fout[i],"\n");
		}
	}
	for(int i=3;i<=10;i++){
	   fclose(fout[i]);
	}
	return 0;
}
