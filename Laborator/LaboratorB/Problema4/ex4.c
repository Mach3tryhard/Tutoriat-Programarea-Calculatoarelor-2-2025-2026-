#include <stdio.h>
#include <stdlib.h>

/*
Sa se afiseze toate nr de n cifre distincte cu suma cifrelor egala cu s.
*/

int s[1000], n;
int suma;



void bkt(int k)
{
    for(int i = 1; i <= n; i++)
    {
        s[k++] = i;
    }
}

int main()
{


    return 0;
}