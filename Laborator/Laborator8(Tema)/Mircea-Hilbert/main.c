#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL3/SDL.h>
#define WIDTH 800
#define HEIGHT 800


/*
Dec     bin
0       0000 => Primii doi biti al acestui numar imi vor da in ce punct ma aflu in curba de ordinul 1,
1       0001    respectiv (00 -> 0, 01 -> 1, 10 -> 2, 11 -> 3)
2       0010
3       0011 
4       0100
5       0101
6       0110
7       0111

Prin shiftari de biti, obtinem cadranul pt urmatorul nivel al unui punct dat.

*/

typedef struct
{
    int x;
    int y;
}Point;

void drawHilbertCurve(Point *points, int nr, int k)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_CreateWindowAndRenderer("Hilbert Curve", WIDTH, HEIGHT, 0, &window, &renderer) < 0)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return; 
    }

    
    
    int open = 1;
    int Notdrawn = 1;

    int len =  WIDTH  / (int)pow(2, k); // lungimea curbei

    SDL_Event event;
    while(open){
        SDL_RenderPresent(renderer); // tho acest lucru e cam yucky, next time nu mai face asta
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                open = 0;
            }
        }

        
        if(Notdrawn == 1)
            for(int i = 0; i < nr - 1; i++)
            {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderLine(renderer, points[i].x * len + len/2, points[i].y * len + len/2, points[i + 1].x * len + len/2, points[i + 1].y * len + len/2);
                SDL_RenderPresent(renderer);
                SDL_Delay(10); 
            }

        Notdrawn = 0; // am terminat de desenat curba
        

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Point FirstOrder[] = {
    {0, 0}, 
    {0, 1}, 
    {1, 1},
    {1, 0}
};

Point hilbert(int i, int k)
{
    int index = i & 3; 
    Point Curve = FirstOrder[index];

    for(int j = 1; j < k; j++)
    {
        i = i >> 2;
        index = i & 3;
        int len = (int)pow(2, j);
        /*
        MSB-urile imi pot da in ce cadran ne aflam, acestia fiind:
        1  4
                = > 1) Curba e rotita la stanga
        2  3        2) Curba este in orientarea normala
                    3) ------/-------
                    4) Curba este rotita la dreapta
        */
        if(index == 0){
        //suntem in cadranul din stanga
        int temp = Curve.x; // acest swap e necesar pentru a roti curba la stanga
        Curve.x = Curve.y;  // practic, din ordinea 0, 1, 2, 3 o transformam in 3, 0, 1, 2
        Curve.y = temp;
        }else if(index == 1){
            Curve.y += len;
        }else if(index == 2){
            Curve.x += len;
            Curve.y += len;
        }else if(index == 3){
            int temp = len - 1 - Curve.x;
            Curve.x = len - 1 - Curve.y;
            Curve.y = temp;
            Curve.x += len;
        
        }
    }

    return Curve;
}


int main()
{
    int k, Cx, Cy;
    scanf("%d %d %d", &k, &Cx, &Cy);
    
    FILE *file = fopen("hilbert_points.txt", "w+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    int N = (int)pow(2, k);
    int nrTotal = N * N; // Numarul de noduri
    Point *HilbertCurve = (Point*)malloc(sizeof(Point) * nrTotal);
    for(int i = 0; i < nrTotal; i++)
        HilbertCurve[i] = hilbert(i, k);
    
    for (int i = 0; i < nrTotal; i++) {
        fprintf(file, "%d %d\n", HilbertCurve[i].x, HilbertCurve[i].y);
    }
    
    for(int i = 0; i < nrTotal; i++)
    {
        if(HilbertCurve[i].x + 1== Cx && HilbertCurve[i].y + 1== Cy)
        {
            printf("%d", i);
            break;
        }
    }

    drawHilbertCurve(HilbertCurve, nrTotal, k); 

    fclose(file);
    free(HilbertCurve);
    return 0;
}