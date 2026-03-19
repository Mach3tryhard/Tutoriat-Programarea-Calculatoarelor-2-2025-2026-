#include <stdio.h>

int main()
{
    FILE* fout = fopen("date.txt","w+");
    if(fout==NULL){
        perror("Error opening file");
        return 1;
    }
    int n;
    scanf("%d",&n);
    char c=' ';// sau sscanf in loc de scanf ca sa nu mai faci primul for loop
    while(c!='\n')
        scanf("%c",&c);
    while(n>0){
        scanf("%c",&c);
        fprintf(fout,"%c",c);
        if(c=='\n')
            n--;
    }
    return 0;
}
