#include <stdio.h>
#include <string.h>

int main()
{
    FILE* fin = fopen("date.txt","r");
    if(fin==NULL){
        perror("Error opening file");
        return 1;
    }
    char s[1005],fis[1005];
    scanf("%s",s);
    int n=strlen(s);
    char c;
    int kon=0,m=0;
    while( (fis[m]=fgetc(fin))!=EOF ){
        m++;
    }

    for(int i=0;i<m;i++){
        int cnt=0,k=0;
        for(int j=i;j<n+i;j++){
            if(fis[j]!=s[k])
                cnt=1;
            k++;
        }
        if(cnt==0)
        {
            kon++;
        }
    }

    printf("%d",kon);
    return 0;
}
