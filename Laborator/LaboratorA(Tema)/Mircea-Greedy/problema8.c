    #include <stdio.h>
    #include <stdlib.h>

    typedef struct 
    {
        int timp;
        int tip;
        int nr;
    }Eveniment;

    int cmpEveniment(const void *a, const void *b)
    {
        const Eveniment *a1 = (const Eveniment*)a;
        const Eveniment *a2 = (const Eveniment*)b;
        if(a1 -> timp != a2 -> timp)
            return a1 -> timp - a2 -> timp;
        return a1 -> tip - a2 -> tip;
    }

    int main()
    {
        FILE *f = fopen("lista.in", "r");
        if(f == NULL)
        {
            printf("fisierul lista.in nu exista\n");
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
            events[2*(i-1)]   = (Eveniment){ inceput,
                                            1, // eveniment de tip START
                                            i };

            events[2*(i-1)+1] = (Eveniment){ sfarsit,
                                            0, // eveniment de tip END
                                            i};
        }

        qsort(events, 2 * n, sizeof(Eveniment), cmpEveniment);

        int *sali_libere = malloc(sizeof(int) * n);
        int k = 0;
        for(int i = 1; i<=n; i++)
            sali_libere[k++] = i;
        
        int *sala_activa = malloc (sizeof(int) * (n+1));


        int **activitati_sali = malloc(sizeof(int*) * (n+1));
        for(int i = 1; i <=n; i++)
            activitati_sali[i] = malloc(sizeof(int) * n);

        int *count_sali = calloc(n+1, sizeof(int));
        
        int max = 0;

        for(int i = 0; i < 2 * n; i++)
        {
            Eveniment ev = events[i];
            if(ev.tip == 1)
            {
                int sala = sali_libere[--k];
                sala_activa[ev.nr] = sala;
                activitati_sali[sala][count_sali[sala]++] = ev.nr;
                int sali_folosite = n - k;
                if(sali_folosite > max) max = sali_folosite;
            }
            else{
                int sala = sala_activa[ev.nr];
                sali_libere[k++] = sala;
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