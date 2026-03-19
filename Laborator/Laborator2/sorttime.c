#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t start,end,start2,end2;

int n=100;
int v[100],a[100],b[100];

int bbsort(){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]>a[j]){
				int aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
	}
}

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	FILE* fin=fopen("test.txt","r");
	FILE* fout=fout("output.txt","w");

	for(int i=0;i<100;i++){
		fscanf(fin,"%d",&v[i]);
		a[i]=v[i];
		b[i]=v[i];
	}
	start=clock();

	//n^2 sort
	bbsort();

	end=clock();
	double time1=((double)(end-start))/CLOCKS_PER_SEC;
	start2=clock();

	//nlogn sort
	qsort(b,n,sizeof(int),cmp);
	
	end2=clock();
	double time2 =((double)(end2-start2))/CLOCKS_PER_SEC;
	printf("%lf %lf\n",time1,time2);

	for(int i=0;i<n;i++){
		fprintf("%d %d ",a[i],b[i]);
	}
	return 0;
}

