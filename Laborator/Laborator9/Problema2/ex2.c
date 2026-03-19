/*
O masina trebuie sa parcurga o distanta de n KM intre orasul A si orasul B. Stiind ca rezervorul masinii are o capacitate de m km,
sa se determine nr minim de opriri la statiile de alimentare aflate pe drum
    n = 800
    m = 300
    nr_statii = 4
    A(0 km)....200km....475......550....7250....B(800km)
    Raspuns : 3 (statiile 1, 2, 4)
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, nr_statii;
    scanf("%d %d %d", &n, &m, &nr_statii);

    int *st = malloc(sizeof(int) * nr_statii);
    for(int i = 0; i < nr_statii; i++)
    {
        scanf("%d", &st[i]);
    }
    
    int cur = 0;
    int opriri = 0;
    while(cur < n)
    {
        cur += m;
        if(cur < st[])
    }

    free(st);
    return 0;
}