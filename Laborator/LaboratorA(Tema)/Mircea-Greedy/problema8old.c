#include <stdio.h>
#include <stdlib.h>
/*
    8. Partitionarea intervalelor
    Avem n activitati pt care stim o ora de inceput si o ora de sfarsit. Avem posibilitatea sa folosim oricat de multe sali, insa dorim minimizarea nr.
de sali pt a scadea costurile administrative. Doua activitati care se suprapun trebuie planificate in sali diferite. Nr minim de sali este numarul maxim
de sali ocupate in orice moment.
*/

/*
TO DO: RESCRIE CODUL. E O PROBLEMA LA COUNT IN ACCESARE. PROBABIL E DE LA FAPTUL CA INDEXAM DE LA 12 LA 1 IN LOC DE LA 1 LA N
*/


typedef struct
{
    int timp; // in minute, in functie de miezul noptii
    int tip; // 1 = eveniment de tip START, 0 = END
    int nr; // index, [1, n]
}Eveniment;

int cmpEveniment(const void *a, const void *b) //Ordonare dupa timp, iar daca timpul se suprapune
{                                               //punem evenimentul de tip END inaintea celui de START
    const Eveniment *a1 = (const Eveniment*)a;
    const Eveniment *a2 = (const Eveniment*)b;
    if(a1->timp != a2->timp)
        return a1->timp - a2->timp;
    return a1->tip - a2->tip;
}

int main()
{
    FILE *f = fopen("lista.in", "r");
    if(f == NULL)
    {
        printf("file\n");
        return 1;
    }

    int n;

    fscanf(f, "%d", &n);
    Eveniment *events = malloc(sizeof(Eveniment) * 2 * n);
    if(events == NULL)
        return 1;

    for(int i = 1; i <=n; i++)
    {
        int ora1, min1, ora2, min2;
        fscanf(f, "%d:%d %d:%d", &ora1, &min1, &ora2, &min2);
        int inceput = ora1 * 60 + min1;
        int sfarsit = ora2 * 60 + min2;
        events[2*(i-1)]   = (Eveniment){ inceput,
                                         1, // eveniment de tip START
                                         i };

        events[2*(i-1)+1] = (Eveniment){ sfarsit,
                                         0, // eveniment de tip END
                                         i};
    }
    //sortam crescator evenimentele
    qsort(events, 2*n, sizeof(Eveniment), cmpEveniment);

    //Stiva de sali libere
    int *camere_libere = malloc(sizeof(int) * n);
    int k = 0; // contor
    for(int i = 1; i <= n; i++)
        camere_libere[k++] = i;
    
    //look up array pt fiecare activitate cu indexul i (retinem nr salii in care a fost alocata o activitate)
    int *camere_activitate = malloc(sizeof(int) * (n+1));

    int **activitati_per_camera = malloc(sizeof(int*) * (n+1)); // pt fiecare camera i, ce activitati a avut
                                                               // activitati_per_camera[i][0] prima activitate din zi in camera i
                                                               //                      [i][1] a doua activitate si asa mai departe
    int *count_camera = calloc(n+1, sizeof(int)); // count pt cate activitati a fost intr-o camera, init = 0;
    for(int i = 1; i <=n; i++)
        activitati_per_camera[i] = malloc(sizeof(int) * n);
    
    int max = 0; // nr maxim de camere

    for(int i = 0; i < 2 * n; i++)
    {
        Eveniment ev = events[i];
        if(ev.tip == 1) // START, vom aloca o sala
        {
            int camera = camere_libere[--k];
            camere_activitate[ev.nr] = camera;
            activitati_per_camera[camera][count_camera[camera]++] = ev.nr;
            count_camera[camera]++;
            int cam_folosite_acum = n - k; //cate camere sunt folosite la acest moment
            if(cam_folosite_acum > max) max = cam_folosite_acum;
        }
        else           // END, eliberam o sala
        {
            int camera = camere_activitate[ev.nr];
            camere_libere[k++] = camera;
        }
    }

    printf("Se folosesc maxim %d camere\n", max);
    for(int i = 1; i <= max; i++)
    {
        printf("Sala %d: activitatile ", i);
        for(int j = 0; j < count_camera[i]; j++)
        {
            printf("%d", activitati_per_camera[i][j]); // printam ce activitate a avut
            if(j + 1 < count_camera[i]) printf(", ");
        }
        printf("\n");
    }


    for(int i = 1; i <= n; i++) free(activitati_per_camera[i]);
    free(activitati_per_camera);
    free(count_camera);
    free(camere_activitate); // e sala curenta, editeaza pt viitor
    free(camere_libere);
    free(events);

    fclose(f);
    return 0;
}