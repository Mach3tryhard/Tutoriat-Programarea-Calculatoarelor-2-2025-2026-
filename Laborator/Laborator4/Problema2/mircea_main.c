#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//problema elementului majoritar dintr-un sir
// un nr x trb sa apara de cel putin n/2+1 ori
//exemplu n = 7 cu v = [2, 3, 4, 6, 3, 3, 3];R = 3 e element majoritar
int main(void) {
    //toate rezolvarile sunt pe curs
    // cu toate variantele

    FILE *fptr = fopen("date.txt","r");
    if(fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    int avantaj = 0;
    int previous;

    fseek(fptr, 0, SEEK_END);
    int n = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    char candidat[100]; int nr;
    for (int i = 0; i < n; i++) {
        fscanf(fptr, "%s ", candidat);
        nr = atoi(candidat);
        if (i == 0) {
            previous = nr;
            avantaj++;
        }
        else{
            if (nr != previous) {
            if (avantaj == 0) {
                previous = nr;
                avantaj++;
            }
            else avantaj--;
        }
        else if (previous == nr)
            avantaj++;
        }



    }
    printf("%d\n", previous);

    close(fptr);

    return 0;
}
