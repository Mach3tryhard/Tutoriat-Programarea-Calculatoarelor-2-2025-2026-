#include <stdio.h>
#include <stdlib.h>

int Ecuatie(int n)
{
    if(n == 1)
        return 1;
    else if(n > 1)
        return 3 * n - 2 + Ecuatie(n - 1);
        else
            {
                printf("Numarul introdus nu este valid\n");
                exit(1);
            }
}

int main()
{
    int n;
    printf("Introduceti n: ");
    scanf("%d", &n);
    printf("Rezultatul este: %d\n", Ecuatie(n));

    return 0;
}