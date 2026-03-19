#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}Point;

Point PrimulOrder[] = {
    {0, 0},
    {0, 1},
    {1, 1},
    {1, 0}
};

/*
Daca suntem la ordinul 1, doar returnam din array-ul PrimulOrder, altfel:
Indexul i va fi folosit pt a calcula:
    cadran = i / (4^(k-1))
    remainder = i % (4^(k-1))
Calculam coordonatele unui punct de ordin k-1 si apoi facem transformari dupa in ce cadran se afla:
  - cadran 0: Rotim subcadranul la stanga (swap de x si y)
  - cadran 1: translatam sus subcadranul cu d = 2^(k-1)
  - cadran 2: translate sus si la dreapta cu d
  - cadran 3: Rotim la dreapta si translatam la dreapta cu d
*/

Point hilbert_recursive(int i, int k)
{
    if(k == 1)
    {
        return PrimulOrder[i & 3];
    }
    
    // Fiecare cadran are 4^k puncte -> Fiecare subcadran are 4^(k-1) puncte sasd...
    int subCadran = (int)pow(4, k - 1);
    int cadran = i / subCadran;   //singurele cadrane valabile (0, 1, 2, 3) (cel mare)
    int remainder = i % subCadran;    // Indexul di cadranul respectiv (pt curba mai mica)
    /*
        In exemplul cu curba de ordin 1, avem 4 puncte: (0,0), (0,1), (1,1), (1,0), cu indexii 0, 1, 2, 3
    */

    
    Point sub = hilbert_recursive(remainder, k - 1); 
    
    // d = distanta care da scale cu ordinea curbei, adica 2^(k-1)
    // d = 2^(k-1) => 2^0 = 1, 2^1 = 2, 2^2 = 4, 2^3 = 8, etc.
    int d = (int)pow(2, k - 1);
    Point result;
    
    switch(cadran)
    {
        case 0: // Cadran 0
            // Rotim la stanga (swap de x si y)
            result.x = sub.y;
            result.y = sub.x;
            break;
        case 1: // Cadran 1
            // Orientare normala, doar urcam in sus cu d
            result.x = sub.x;
            result.y = sub.y + d;
            break;
        case 2: // Cadran 2
            // Orientare normala, urcam in sus si la dreapta cu d
            result.x = sub.x + d;
            result.y = sub.y + d;
            break;
        case 3: // Cadran 3
            // Orientare inversa, rotim la dreapta (swap de x si y) si urcam in sus si dreapta cu d
            int temp = d - 1 - sub.y;
            result.x = d + temp;
            result.y = d - 1 - sub.x;
            break;
    }
    
    return result;
}


int main()
{
    FILE *fin = fopen("fractal.in", "r");
    if(fin == NULL)
    {
        perror("Eroare la fisier in\n");
        return 1;
    }
    FILE *fout = fopen("fractal.out", "w");
    if(fout == NULL)
    {
        perror("Eroare la fisier out\n");
        return 1;
    }
    int k = -1, Cx = -1, Cy = -1;

    if((fscanf(fin, "%d %d %d", &k, &Cx, &Cy)) != 3)
    {
        perror("Format fisier: <ordin> <x> <y>\n");
        exit(1);
    }

    if(k < 1)
    {
        perror("k >= 1\n");
        exit(1);
    }
    
    int N = (int)pow(2, k);

    if((Cx > N || Cy > N) || (Cx < 1 || Cy < 1))
    {
        printf("valori acceptate 1 <= x, y <= 2^k\n");
        exit(1);
    }

    int nrTotal = N * N; 
    Point *HilbertCurve = (Point*)malloc(sizeof(Point) * nrTotal);
    
    for(int i = 0; i < nrTotal; i++)
        HilbertCurve[i] = hilbert_recursive(i, k);
    
    int steps;

    for(int i = 0; i < nrTotal; i++)
    {
        if(HilbertCurve[i].x + 1 == Cx && HilbertCurve[i].y + 1 == Cy)
        {
            fprintf(fout, "%d", i);
            steps = i;
            break;
        }
    }
    
    fclose(fin);
    fclose(fout);
    free(HilbertCurve);
    

    return 0;

}