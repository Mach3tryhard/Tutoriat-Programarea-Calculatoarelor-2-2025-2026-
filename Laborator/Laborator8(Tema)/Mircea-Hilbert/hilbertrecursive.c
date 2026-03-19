#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Dec     bin
0       0000 => Primii doi biti al acestui numar imi vor da in ce punct ma aflu in curba de ordinul 1,
1       0001    respectiv (00 -> 0, 01 -> 1, 10 -> 2, 11 -> 3)
2       0010
3       0011 
4       0100
5       0101
6       0110
7       0111

*/

typedef struct
{
    int x;
    int y;
}Point;


Point FirstOrder[] = {
    {0, 0}, 
    {0, 1}, 
    {1, 1},
    {1, 0}
};


Point hilbert_recursive(int i, int k, int x, int y, int size)
{
    if (k == 0) {
        return (Point){x, y};
    }

    int half = size / 2;
    Point p;

    if (i < half * half) {
        p = hilbert_recursive(i, k - 1, x, y, half);
    } else if (i < 2 * half * half) {
        p = hilbert_recursive(i - half * half, k - 1, x + half, y, half);
    } else if (i < 3 * half * half) {
        p = hilbert_recursive(i - 2 * half * half, k - 1, x + half, y + half, half);
    } else {
        p = hilbert_recursive(i - 3 * half * half, k - 1, x, y + half, half);
    }

    return p;
}
Point hilbert(int i, int k)
{
    int size = (int)pow(2, k);
    return hilbert_recursive(i, k, 0, 0, size);
}


int main()
{
    int k, Cx, Cy;
    scanf("%d %d %d", &k, &Cx, &Cy);
    
    
    
    int N = (int)pow(2, k);
    int nrTotal = N * N; // Numarul de noduri
    Point *HilbertCurve = (Point*)malloc(sizeof(Point) * nrTotal);

    for(int i = 0; i < nrTotal; i++)
        HilbertCurve[i] = hilbert(i, k);
    
    for(int i = 0; i < nrTotal; i++)
    {
        printf("%d %d\n", HilbertCurve[i].x, HilbertCurve[i].y);
    }
    
    return 0;
}