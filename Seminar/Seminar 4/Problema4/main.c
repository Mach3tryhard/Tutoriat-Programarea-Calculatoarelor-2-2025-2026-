#include <stdio.h>
#include <stdlib.h>

int a[102][102],cnt=1,n;

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
}

void divimp(int i1,int i2,int j1,int j2,int ig,int jg){
    ///SOLUTIE DIRECTA
    if(i2-i1==1){
        if(a[i1][j1]==0)a[i1][j1]=cnt;
        if(a[i1][j2]==0)a[i1][j2]=cnt;
        if(a[i2][j1]==0)a[i2][j1]=cnt;
        if(a[i2][j2]==0)a[i2][j2]=cnt;
        cnt++;
    }
    else{
        int im=(i1+i2)/2,jm=(j1+j2)/2;
        if(ig<=im && jg<=jm){
            a[im][jm+1]=cnt;
            a[im+1][jm]=cnt;
            a[im+1][jm+1]=cnt;
            cnt++;
            divimp(i1,im,j1,jm,ig,jg);
            divimp(i1,im,jm+1,j2,im,jm+1);
            divimp(im+1,i2,j1,jm,im+1,jm);
            divimp(im+1,i2,jm+1,j2,im+1,jm+1);
        }else
        if(ig<=im && jg>jm){
            a[im][jm]=cnt;
            a[im+1][jm]=cnt;
            a[im+1][jm+1]=cnt;
            cnt++;
            divimp(i1,im,j1,jm,im,jm);
            divimp(i1,im,jm+1,j2,ig,jg);
            divimp(im+1,i2,j1,jm,im+1,jm);
            divimp(im+1,i2,jm+1,j2,im+1,jm+1);
        }else
        if(ig>im && jg<=jm){
            a[im][jm]=cnt;
            a[im][jm+1]=cnt;
            a[im+1][jm+1]=cnt;
            cnt++;
            divimp(i1,im,j1,jm,im,jm);
            divimp(i1,im,jm+1,j2,im,jm+1);
            divimp(im+1,i2,j1,jm,ig,jg);
            divimp(im+1,i2,jm+1,j2,im+1,jm+1);
        }else
        if(ig>im && jg>jm){
            a[im][jm]=cnt;
            a[im][jm+1]=cnt;
            a[im+1][jm]=cnt;
            cnt++;
            divimp(i1,im,j1,jm,im,jm);
            divimp(i1,im,jm+1,j2,im,jm+1);
            divimp(im+1,i2,j1,jm,im+1,jm);
            divimp(im+1,i2,jm+1,j2,ig,jg);
        }
    }
}

int main()
{
    int x,y;
    scanf("%d %d %d",&n,&x,&y);
    n=1<<n;
    a[x][y]=-1;
    divimp(0,n-1,0,n-1,x,y);
    print();
    return 0;
}
