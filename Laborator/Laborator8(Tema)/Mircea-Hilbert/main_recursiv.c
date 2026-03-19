#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL3/SDL.h>
#define WIDTH 800
#define HEIGHT 800
//compilat cu gcc main_recursiv.c -o hilbert -lSDL3 -lm // pe linux
//pt windows trb link-uit cu acel dll.
//
typedef struct
{
    int x;
    int y;
} Point;

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
    int cadran = i / subCadran;   //singurele cadrane valabile (0, 1, 2, 3)
    int remainder = i % subCadran;    // Indexul din cadranul respectiv
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

void drawHilbertCurve(Point *points, int nr, int k, int steps)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Eroare la initializare! SDL_Error: %s\n", SDL_GetError());
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // if(SDL_CreateWindowAndRenderer("Hilbert Curve", WIDTH, HEIGHT, SDL_WINDOW_ALWAYS_ON_TOP, &window, &renderer) < 0)
    // {
    //     printf("Eroare la Window SDL_Error: %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return; 
    // }

    SDL_CreateWindowAndRenderer("Hilbert Curve", WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetRenderVSync(renderer, 1);

    int open = 1;
    int Notdrawn = 1;
    int OK = 1;
    int len = WIDTH / (int)pow(2, k);
    SDL_RenderClear(renderer);
    SDL_Event event;
    int currentStep = 0;
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rosu pt pana ce intalnim punctul (Cx, Cy)
while(open)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
            open = 0;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // background
    SDL_RenderClear(renderer);

    for(int i = 0; i < currentStep && i < nr - 1; i++)
    {
        if(i < steps)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderLine(renderer,
            points[i].x * len + len/2, points[i].y * len + len/2,
            points[i + 1].x * len + len/2, points[i + 1].y * len + len/2);
    }

    SDL_RenderPresent(renderer); 

    if(currentStep < nr)
        currentStep++;

    SDL_Delay(16); // ~60 FPS
}

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



int main()
{
    int k, Cx, Cy;
    scanf("%d %d %d", &k, &Cx, &Cy);
    
    if(k < 1)
    {
        printf("k >= 1\n");
        exit(1);
    }

    FILE *file = fopen("hilbert_points.txt", "w+");
    if (file == NULL)
    {
        perror("Eroare la fisier\n");
        return 1;
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
    
    for (int i = 0; i < nrTotal; i++)
    {
        fprintf(file, "%d %d\n", HilbertCurve[i].x, HilbertCurve[i].y);
    }
    
    int steps;

    for(int i = 0; i < nrTotal; i++)
    {
        if(HilbertCurve[i].x + 1 == Cx && HilbertCurve[i].y + 1 == Cy)
        {
            printf("Pentru a ajunge la (%d, %d), s-au facut %d pasi\n",Cx, Cy, i);
            steps = i;
            break;
        }
    }

    drawHilbertCurve(HilbertCurve, nrTotal, k, steps); 

    fclose(file);
    free(HilbertCurve);
    return 0;
}
