#include <stdio.h>
#include <stdlib.h>

/*
Se citesc nr de la tastatura pana la 0. Sa se afiseze toate elem sirului cu nr max de cifre distrincte. 
Nu se vor folosi vectori pt stocarea sirului de nr.

ex: (233, 1474, 15, 9, 189, 0) se vor afisa nr 186 si 1474
*/

int nrDistince(int x)
{
    int vf[10] = { 0 }, cnt = 0;
    while(x)
    {
        vf[x % 10]++;
        x /=10;
    }

    for(int i = 0; i < 10; i++)
    {
        if(vf[i] != 0)
            cnt++;
    }

    return cnt;
}

void parcurgere(int v[], int i, int max) // e cu memorare
{
    int x; scanf("%d", &x);
    if(x == 0)
    {
        for(int j = 0; j < i; j++)
            if(nrDistince(v[j]) == max)
                printf("%d ", v[j]);
        return;
    }
    v = realloc(v, (i+1) * sizeof(int));
    v[i] = x;
    int cfr = nrDistince(x);
    parcurgere(v, i + 1, (cfr > max)?cfr:max); 
}


int main()
{
    int *v = (int*)malloc(sizeof(int));

    parcurgere(v, 0, 0);

    free(v);
}