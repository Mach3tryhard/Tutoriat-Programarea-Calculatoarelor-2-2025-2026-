#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	FILE* fout=fopen("test.txt","w");
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<1000;i++){	
		srand(clock());
		int nr=rand()%(b-a)+a;
		fprintf(fout,"%d\n",nr);
	}
	return 0;
}
