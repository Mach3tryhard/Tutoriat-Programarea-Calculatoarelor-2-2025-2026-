/*
descompunere cu termeni distincti acm
*/
#include <stdio.h>
#include <stdlib.h>

int n;
int s[1000];

int is_distinct(int k)
{
    int vf[k+1];
    for(int i = 1; i <=k; i++)
        vf[i] = 0;
    for(int i = 1; i <=k; i++)
        vf[s[i]]++;

    for(int i = 1; i <=k; i++)
        if(vf[i] > 1)
            return 0;
    return 1;
    
}

int sol_partial(int k)
{
    int sol = 0;
    for(int i = 1; i <=k; i++)
        sol += s[i];
    if(sol <= n && is_distinct(k))
        return 1;
    return 0;
}

int sol_fin(int k)
{
    int sol = 0;
    for(int i = 1; i <=k; i++)
        sol += s[i];
    if(sol == n && is_distinct(k))
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