#include <stdio.h>
#include <stdlib.h>

/*
de la tastatura -> un sir de n nr naturale. 
Sa se afiseze perechile de elemente consecutive din sir care au proprietatea ca CMMDC este egal cu o valoare citita
Cerinte:
    1) CMMDC recursiv (euclid sau scaderi succesive)
    2) Parcurgere perechi recursiva
*/

int CMMDC(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(a > b)
        return CMMDC(a - b, b);
    else if(a < b)
        return CMMDC(a, b - a);
    return a;
}

void parcurgere(int d, int v[], int i, int n)
{
    if(i == n - 1)
        return;
    else if(CMMDC(v[i], v[i+1]) == d)
        printf("(%d, %d) ", v[i], v[i+1]);
    parcurgere(d, v, i + 1, n);
}

int main()
{
    int n; int *v;
    printf("n = ");
    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    int d;
    printf("d = ");
    scanf("%d", &d);
    parcurgere(d, v, 0, n);

    free(v); 
    return 0;
}