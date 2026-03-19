#include <stdio.h>
#include <stdlib.h>
/*
nr elem neg dintr-un sir de n nr intregi
*/

int nrNegative(int *v, int n)
{
    if(n >= 0)
        return (v[n] < 0) ? 1 + nrNegative(v, n - 1): 0 + nrNegative(v, n - 1);
    return 0;
}//funny ternary operators

int main() {

    int v[] = {-2, -1, -3, -4};

    printf("%d", nrNegative(v, 4));

    return 0;
}