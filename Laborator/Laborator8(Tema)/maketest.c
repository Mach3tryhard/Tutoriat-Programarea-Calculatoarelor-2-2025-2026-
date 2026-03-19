#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int power(int a,int b){
    int rez=1;
    for(int i=1;i<=b;i++){
        rez=rez*a;
    }
    return rez;
}

int main(){
    char s[11][20];
    FILE* fout[11];
	for(int i=1;i<=10;i++){
	    ///FISIER
	    sprintf(s[i], "test%d.in", i);
	    fout[i]=fopen(s[i],"w+");
		fprintf(fout[i],"%d\n",i);
		///AFLARE INTERVAL
		int a=1;
		int b=power(2,i);
		///RANDOM NUMBER
		srand(clock());
		int nr1 = rand()%(b-a)+a;
		int nr2 = rand()%(b-a)+a;
		fprintf(fout[i],"%d %d",nr1,nr2);
	}
	for(int i=1;i<=10;i++){
	   fclose(fout[i]);
	}
	return 0;
}
