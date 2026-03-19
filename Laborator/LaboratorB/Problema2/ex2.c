/*
Aceiasi problema, dar acm doar o solutie distincta (2+1+1) e la fel ca (1+1+2)
*/

#include <stdio.h>
#include <stdlib.h>
int n, s[100];


int is_ord_cresc(int k)
{
    int ok = 1;
    for(int i = 1; i < k; i++)
    {
        if(s[i] > s[i+1])
            ok = 0;
    }
    if(ok)
        return 1;
    return 0;
}

int sol_partial(int k)
{
    int sol = 0;
    for(int i = 1; i <=k; i++)
        sol += s[i];
    if(sol <= n && is_ord_cresc(k))
        return 1;
    return 0;
}

int sol_fin(int k)
{
    int sol = 0;
    for(int i = 1; i <=k; i++)
        sol += s[i];
    if(sol == n && is_ord_cresc(k))
        return 1;
    return 0;
}

void sol_print(int k)
{
    for(int i = 1; i <= k; i++)
        printf("%d ", s[i]);
    printf("\n");
}

void bkt(int k)
{
    for(int i = 1; i <= n - k +1; i++)
    {
        s[k] = i;
        if(sol_partial(k))
            if(sol_fin(k))
                sol_print(k);
            else
                bkt(k+1);
    }
}



int main()
{
    scanf("%d", &n);
    bkt(1);



    return 0;
}