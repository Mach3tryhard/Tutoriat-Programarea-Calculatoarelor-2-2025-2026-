#include <stdio.h>
#include <stdlib.h>

int v[1001];

int main(){
    FILE* fin=fopen("fisier.txt","a+");
    int n=0;
    char c,uc=255;
    while( (c=fgetc(fin)) != EOF){
        if((uc>='0' && uc<='9') && (c==' ' || c=='\n'))
            n++;
        uc=c;
    }
    fseek(fin,SEEK_SET, 0);
    if((uc>='0' && uc<='9'))
        n++;
    printf("%d\n",n);
    int *v = malloc(n*sizeof(int));
    for(int i=1;i<=n;i++){
        fscanf(fin,"%d",&v[i]);
    }
    int ap=1;
    int cu=v[1];
    for(int i=2;i<=n;i++){
        if(cu==v[i])
            ap++;
        else
            ap--;
        if(ap==-1){
            ap=1;
            cu=v[i];
        }
    }
    int ap2=0;
    for(int i=1;i<=n;i++){
        if(v[i]==cu)
            ap2++;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",v[i]);
    }
    if(ap>0 && ap2>n/2){
        printf("Elementul majoritar este %d",cu);
    }
    else {
        printf("Nu exista element majoritar");
    }
    fclose(fin);
    return 0;
}
