#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
}Points;

int ng; // nr gauri
Points gauri[100];
Points st_max;
Points dr_max;

void arieMaxima(Points st, Points dr)
{
    int i;
    for(i = 0; i < ng; i++)
        if(st.x < gauri[i].x && gauri[i].x < dr.x
        && st.y < gauri[i].y < dr.y)
            break;
    if(i < ng)
    {
         Points aux;
         aux.x =    

    }
}


int main(int argc, int argv[])
{
    Points st_init;
    Points dr_init;
    st_init.x = atoi(argv[1]);
    st_init.y = atoi(argv[2]);
    dr_init.x = atoi(argv[3]);
    dr_init.y = atoi(argv[4]);

    scanf("%d", &ng);
    for(int i = 0; i < ng; i++)
        scanf("%d %d", &gauri[i].x, &gauri[i].y);
    
    

}