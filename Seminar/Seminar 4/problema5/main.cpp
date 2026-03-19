#include <stdio.h>
#include <math.h>

int a[1001][1001],n;

void Sierpinsky(int i1,int i2,int j1,int j2,int x)
{
    if(i2==i1)
    {
        a[i1][j1]=x;
    }
    else
    {
        int lat=(i2-i1+1)/3;
        int im1=i1+lat,im2=i1+2*lat,jm1=j1+lat,jm2=j1+2*lat;
        Sierpinsky(i1,im1-1,j1,jm1-1,x);
        Sierpinsky(i1,im1-1,jm1,jm2-1,x);
        Sierpinsky(i1,im1-1,jm2,j2,x);
        Sierpinsky(im1,im2-1,j1,jm1-1,x);
        Sierpinsky(im1,im2-1,jm1,jm2-1,1);
        Sierpinsky(im1,im2-1,jm2,j2,x);
        Sierpinsky(im2,i2,j1,jm1-1,x);
        Sierpinsky(im2,i2,jm1,jm2-1,x);
        Sierpinsky(im2,i2,jm2,j2,x);
    }
}

int main()
{
    scanf("%d",&n);
    n=pow(3,n);
    Sierpinsky(0,n-1,0,n-1,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}
