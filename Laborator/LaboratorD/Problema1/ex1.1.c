#include <stdio.h>
#include <stdlib.h>

float suma = 0;

int interior(int x,int y,int m,int n)
{
    if(x > m && x < 0)
        return 0;
    if(y > n && y < 0)
        return 0;
    return 1;
}


float probabilitate(int m, int n, int x, int y, int pasi)
{
    if(!interior(m,n,x,y)) return 0;
    if(pasi == 0) return 1;
    if(probabilitate(m,n,x+1,y,pasi-1))
        suma += 0.25;
    if(probabilitate(m,n,x-1,y,pasi-1))
        suma += 0.25;
    if(probabilitate(m,n,x,y+1,pasi-1))
        suma += 0.25;
    if(probabilitate(m,n,x,y-1,pasi-1))
        suma += 0.25;
    return suma;
    
}


int main()
{
    int m, n, nr_pasi;
    scanf("%d %d %d", &m, &n, &nr_pasi);

    
    int x, y;
    printf("x, y = ");
    scanf("%d %d", &x, &y);

    probabilitate(m, n, x, y, nr_pasi);

    printf("%.2f\n", suma/2 * 100);

}