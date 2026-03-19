#include <stdio.h>
#include <time.h>

clock_t start,end;

double time1;

int apasare(){
	int you=0;
	while(time1<3)
	{
		time1 =((double)(end-start))/CLOCKS_PER_SEC;
		end=clock();
	}
	return you;
}

int main(){
	int a=0;
	start=clock();
	
	apasare();
	end=clock();
	time1 =((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf %lf %lf",time1,(double)start,(double)end);
	return 0;
}

