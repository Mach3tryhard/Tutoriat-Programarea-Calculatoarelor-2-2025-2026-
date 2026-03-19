#include <stdio.h>
#include <stdlib.h>
/*
Metoda backtracking - indicata in gasirea tuturor solutilor unei probleme;
Forma generala a unui algoritm

void bk(int k)
{
    for(int i = mink; i <= max k;  = succ(i)))
    {
        s[k] = i;
        if(s[1]....s[k] este solutie partiala)
        {
            if(s[1].....s[k] este solutie finala)
                //prelucreaza solutia sau afiseaza
            else
                bkt(k+1);
        }
    }

*/

/*
Problema 1: S se descompuna un nr nat n ca suma de numere naturale nenule
*/

int n;
int s[100];

int sol_partial(int k)
{
    int sol = 0;
    for(int i = 1; i <=k; i++)
        sol += s[i];
    if(sol <= n)
        return 1;
    return 0;
}

int sol_fin(int k)
{
    int sol = 0;
    for(int i = 1; i <=k; i++)
        sol += s[i];
    if(sol == n)
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