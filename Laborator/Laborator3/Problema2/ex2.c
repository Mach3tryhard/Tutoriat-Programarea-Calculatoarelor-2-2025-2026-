#include <stdio.h>

int main()
{
    FILE* fin = fopen("date.in","r");
    if(fin==NULL){
        perror("Error opening file");
        return 1;
    }
    int nrcuv=0;
    int nrchar=0;
    int c,uc;
    while( (c=fgetc(fin))!=EOF ){
        nrchar++;
        if(c==' ' || c=='.' || c==',' || c=='?' || c=='!' || c=='\n')
            if(uc!=' ' && uc!='.' && uc!=',' && uc!='?' && uc!='!' && uc!='\n')
                nrcuv++;
        uc=c;
    }
    if(uc!=' ' && uc!='.' && uc!=',' && uc!='?' && uc!='!' && uc!='\n')
        nrcuv++;
    printf("Numarul de charactere: %d \nNumarul de cuvinte: %d \n",nrchar,nrcuv);
    return 0;
}
