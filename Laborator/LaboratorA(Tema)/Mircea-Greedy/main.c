#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int timp; // in minute
    int tip; // 1 = eveniment de tip START, 0 = END
    int nr; // index [1, 2n], n = nr evenimente
} Eveniment;

int cmpEveniment(const void *a, const void *b) // Ordonare dupa timp,
{   //iara daca evenimentele se suprapun, cel de tip END trebuie sa vina inaintea lui START
    const Eveniment *a1 = (const Eveniment*)a;
    const Eveniment *a2 = (const Eveniment*)b;
    if(a1->timp != a2->timp)
        return a1->timp - a2->timp;
    return a1->tip - a2->tip;
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Utilizare corecta ./main <nume_fisier>\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if(f == NULL)
    {
        printf("fisierul %s nu exista\n", argv[1]);
        return 1;
    }
    int n; fscanf(f, "%d", &n);
    Eveniment *events = malloc(sizeof(Eveniment) * 2 * n);
    if(events == NULL)
    {
        printf("fail malloc\n");
        return 1;
    }

    for(int i = 1; i <=n; i++)
    {
        int ora1, min1, ora2, min2;
        fscanf(f, "%d:%d %d:%d", &ora1, &min1, &ora2, &min2);
        int inceput = ora1 * 60 + min1;
        int sfarsit = ora2 * 60 + min2;
        events[2*(i-1)]   = (Eveniment){ inceput, 1, i }; //START
        events[2*(i-1)+1] = (Eveniment){ sfarsit, 0, i}; //END
    }
    //Sortam crescator evenimentele
    qsort(events, 2 * n, sizeof(Eveniment), cmpEveniment);

    //Stiva de sali libere
    int *sali_libere = malloc(sizeof(int) * n);
    int k = 0;//contor
    for(int i = 1; i<=n; i++)
        sali_libere[k++] = i;
    
    //sala_activa e vector care tine ce sala e folosita la un eveniment
    //astfel, stim ce sala putem sa eliberam dupa ev.nr
    int *sala_activa = malloc(sizeof(int) * (n+1));

    int **activitati_sali = malloc(sizeof(int*) * (n+1));
    //pt fiecare sala i, avem ce activitati a avut intr-un vector
    //activitati_sali[i][0] - prima activitate,
    //activitati_sali[i][1] - a doua, s.a.
    //nr max este dat de count_sali
    for(int i = 1; i <=n; i++)
        activitati_sali[i] = malloc(sizeof(int) * n);

    int *count_sali = calloc(n+1, sizeof(int));
    
    int max = 0;

    for(int i = 0; i < 2 * n; i++)
    {
        Eveniment ev = events[i];
        if(ev.tip == 1)
        {
            if(k == 0)
            {
                printf("0 evenimente\n");
                return 1;
            }
            int sala = sali_libere[0];//Luam prima sala libera
            for(int j = 0; j < k - 1; j++)
                sali_libere[j] = sali_libere[j + 1];//shiftam celelalte camere ca sa o scoatem din lista
            k--;
            
            sala_activa[ev.nr] = sala;
            activitati_sali[sala][count_sali[sala]++] = ev.nr;
            int sali_folosite = n - k;
            if(sali_folosite > max) max = sali_folosite;
        }
        else
        {
            int sala = sala_activa[ev.nr];
            int pos = 0;
            //Gasim pozitia potrivita pt a insera camera in ordinea crescatoare
            while(pos < k && sali_libere[pos] < sala) pos++;
            //Shiftam camerele ca sa o inseram
            for(int j = k; j > pos; j--)
                sali_libere[j] = sali_libere[j - 1];
            sali_libere[pos] = sala; //O reintroducem ca sala libera
            k++;
        }
    }

    printf("Se folosesc maxim %d camere\n", max);
    for(int i = 1; i <= max; i++)
    {
        printf("Sala %d: activitatile ", i);
        for(int j = 0; j < count_sali[i]; j++)
        {
            printf("%d", activitati_sali[i][j]);
            if(j + 1 < count_sali[i]) printf(", ");
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++) free(activitati_sali[i]);
    free(activitati_sali);
    free(count_sali);
    free(sala_activa);
    free(sali_libere);
    free(events);

    fclose(f);
    return 0;
}