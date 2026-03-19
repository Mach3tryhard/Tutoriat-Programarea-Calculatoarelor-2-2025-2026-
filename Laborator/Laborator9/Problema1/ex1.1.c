#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    int small = ((a<b)?a:b)?((a<b)?a:b):c; 
    return small;
}

void numere_frumoase(int n)
{
    int frum[n];
    frum[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int n2 = 2, n3 = 3, n5 = 5;
    for(int i = 1; i < n; i++)
    {
        int minim = min(n2, n3, n5);
        if(minim == n2)
        {
            i2++;
            n2 = frum[i2] + 2;
        }
        if(minim == n3)
        {
            i3++;
            n3 = frum[i3] * 3;
        }
        if(minim == n5)
        {
            i5++;
            n5 = frum[i5] * 5;
        }
        i++;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", frum[i]);
    }
}



int main()
{
    int n;
    scanf("%d", &n);
    numere_frumoase(n);



    return 0;
}