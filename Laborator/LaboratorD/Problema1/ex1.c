#include <stdio.h>
#include <stdlib.h>

/*
    Un personaj se afla pe o insula de dimensiune m*n. Daca personajukl paseste in afara insulei jocul se considera pierdut. Sa se determine probabilitatea ca personajul
    sa se afle in interiorul insulei dupa x pasi stiind ca un pas reprezinta o deplasare cu o pozitie in una dintre cele 4 directii(SUS JOS ST DR)

    Date de intrare: m, n (matricea),
                     nr de pasi
                     pozitia de start


    ex: m = 2, n = 2, (0, 0) pct de start. Nr pasi = 1
    
    x 0
    0 0 -> probabilitatea e 50% Daca te duci in sus si in stanga iesi din insula, altfel e okay
*/

int mutari_bad = 0, mutari_bune = 0;

int esteInauntru(int x,int y,int m,int n)
{
    if(x > m && x < 0)
        return 0;
    if(y > n && y < 0)
        return 0;
    return 1;
}


void Plimbare(int x, int y, int m, int n, int pasi)
{
    if(esteInauntru)
        mutari_bune++;
    else
        mutari_bad++;
    if(pasi == 0)
        return;
    else{
        Plimbare(x+1, y, m, n, pasi-1);
        Plimbare(x-1, y, m, n, pasi-1);
        Plimbare(x, y+1, m, n, pasi-1);
        Plimbare(x, y-1, m, n, pasi-1);
    }
}

int main()
{
    int m, n, nr_pasi;
    scanf("%d %d %d", &m, &n, &nr_pasi);

    
    int x, y;
    printf("x, y = ");
    scanf("%d %d", &x, &y);

    Plimbare(x, y, m, n, nr_pasi);
    printf("\ndebug %d %d\n\n", mutari_bad, mutari_bune);

    /*
    nr_pasi * 4 ...... 100
    bune ..........  x
    */

    printf("Probabilitatea e %f la suta\n", (100 * mutari_bune) / (4*nr_pasi));


    return 0;
}