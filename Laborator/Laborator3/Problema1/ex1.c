#include <stdio.h>

int main()
{
    FILE* fin = fopen("date.in","r");
    if(fin==NULL){
        perror("Error opening file");
        return 1;
    }
    int cnt=0;
    int c;
    while( (c=fgetc(fin))!=EOF ){
        if(c=='\n')
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
