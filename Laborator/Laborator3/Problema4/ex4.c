#include <stdio.h>

int main()
{
    FILE* fin1 = fopen("1.txt","r");
    FILE* fin2 = fopen("2.txt","r");
    FILE* fout = fopen("3.txt","a+");
    if(fout==NULL){
        perror("Error opening file");
        return 1;
    }
    char c;
    while( (c=fgetc(fin1))!=EOF ){
        fprintf(fout,"%c",c);
    }
    while( (c=fgetc(fin2))!=EOF ){
        fprintf(fout,"%c",c);
    }
    return 0;
}
