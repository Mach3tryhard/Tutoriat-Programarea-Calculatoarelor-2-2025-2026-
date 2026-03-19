#include <stdio.h>
#include <stdlib.h>
/*
Numerele "frumoase" sunt acele nr naturale care au factori primi doar 2, 3, 5. Fiind dat un nr natural n, sa se determine
primele n numere frumoase.

n = 25
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36, 40, 45, 48, 50, 54
*/

int minCalc(int nr[], int min)
{
    int min_loc = min;
    int i_loc;
    for(int i = 0; i < 3; i++)
        if(nr[i] < min_loc){
            min_loc = nr[i];
            i_loc = i;}
    
    nr[i_loc] = nr[i_loc] * min_loc;
    return nr[i_loc];
        
}

int main()
{
    int n;
    int i = 0;
    scanf("%d", &n);
    int *v = malloc(sizeof(int) * (n+1));
    v[0] = 1;
    int nr[] = {2, 3, 5};
    int min = 9999;
    for(int i = 0; i < n; i++)
    {
        min = minCalc(nr, min);
        v[i+1] = min;
    }

    for(int i = 0; i <= n; i++)
        printf("%d ", v[i]);


    return 0;
}