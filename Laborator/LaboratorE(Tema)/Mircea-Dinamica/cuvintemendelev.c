#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//top down / inapoi

/*
    Basically tot apelul recursiv merge pana la final
    EX: Bacon
    DPcanFOrm(0)
        ->DPcanForm(1)
            ->DPcanForm(3)
                ->DPcanForm(4)
                    ->DPcanForm(5) unde returneaza true
                return true
            return true
        return true
    return true

    (4) - > "N"
    (3) - > "O"
    (1) - > "Ac"
    (0) - > "B"
*/


char *Elemente[118] = {
      "H"  , "He" , "Li" , "Be" , "B"  , "C"  , "N"  , "O"  , "F"
    , "Ne" , "Na" , "Mg" , "Al" , "Si" , "P"  , "S"  , "Cl" , "Ar"
    , "K"  , "Ca" , "Sc" , "Ti" , "V"  , "Cr" , "Mn" , "Fe" , "Co"
    , "Ni" , "Cu" , "Zn" , "Ga" , "Ge" , "As" , "Se" , "Br" , "Kr"
    , "Rb" , "Sr" , "Y"  , "Zr" , "Nb" , "Mo" , "Tc" , "Ru" , "Rh"
    , "Pd" , "Ag" , "Cd" , "In" , "Sn" , "Sb" , "Te" , "I"  , "Xe"
    , "Cs" , "Ba" , "La" , "Ce" , "Pr" , "Nd" , "Pm" , "Sm" , "Eu"
    , "Gd" , "Tb" , "Dy" , "Ho" , "Er" , "Tm" , "Yb" , "Lu" , "Hf"
    , "Ta" , "W"  , "Re" , "Os" , "Ir" , "Pt" , "Au" , "Hg" , "Tl"
    , "Pb" , "Bi" , "Po" , "At" , "Rn" , "Fr" , "Ra" , "Ac" , "Th"
    , "Pa" , "U"  , "Np" , "Pu" , "Am" , "Cm" , "Bk" , "Cf" , "Es"
    , "Fm" , "Md" , "No" , "Lr" , "Rf" , "Db" , "Sg" , "Bh" , "Hs"
    , "Mt" , "Ds" , "Rg" , "Cn" , "Nh" , "Fl" , "Mc" , "Lv" , "Ts"
    , "Og"
};

const int nr_elem = sizeof(Elemente) / sizeof(Elemente[0]);

void formatSimbol(const char *s, char *simbol, int len)
{
    if(len == 1)
    {
        simbol[0] = toupper(s[0]);
        simbol[1] = '\0';
    } else if(len == 2)
    {
        simbol[0] = toupper(s[0]);
        simbol[1] = tolower(s[1]);
        simbol[2] = '\0';
    }
}

int ElementIndex(const char *s, int len) // id al elementului sau -1 daca nu-l gaseste
{
    char simbol[3];
    formatSimbol(s, simbol, len);
    for(int i = 0; i < nr_elem; i++)
    {
        if(strcmp(simbol, Elemente[i]) == 0)
            return i;
    }

    return -1;
}

bool DPcanForm(int pos, const char *cuv, int len, int *dp, int *drum_elem, int *drum_len)
{
    if(pos == len) return true;
    if(dp[pos] != -1) return dp[pos]; // continuam de la subsolutia gasita

    //1-char matching
    int idElem = ElementIndex(&cuv[pos], 1);
    if(idElem != -1 && DPcanForm(pos + 1, cuv, len, dp, drum_elem, drum_len))
    {
        dp[pos] = 1;
        drum_elem[pos] = idElem;
        drum_len[pos] = 1;
        printf("%d \n", pos);
        return true;
    }
    //2-char matching
    if(pos + 2 <= len) // ca sa nu iesim din cuv
    {
        idElem = ElementIndex(&cuv[pos], 2);
        if(idElem != -1 && DPcanForm(pos + 2, cuv, len, dp, drum_elem, drum_len))
        {
            dp[pos] = 1;
            drum_elem[pos] = idElem;
            drum_len[pos] = 2;
            return true;
        }
    }

    dp[pos] = 0;
    return false;
    
}

void afisareSolutie(int *drum_elem, int *drum_len, int len)
{
    int pos = 0;
    printf("Solutie: ");
    while(pos < len)
    {
        int idElem = drum_elem[pos];
        int size = drum_len[pos];
        if(idElem == -1 || size == 0)
        {
            printf("eroare?:(\n");
            return;
        }

        printf("%s ", Elemente[idElem]);
        pos += size;
    }

    printf("\n");
}


int main()
{
    char cuvant[36];
    scanf("%s", cuvant);
    int cuv_len = strlen(cuvant);
    for(int i = 0; i < cuv_len; i++)
        cuvant[i] = tolower(cuvant[i]);

    
    int *dp        = malloc(cuv_len * sizeof(int)); //pt memorarea rezultatelor subproblemelor
    int *drum_elem = malloc(cuv_len * sizeof(int));
    int *drum_len  = malloc(cuv_len * sizeof(int)); // durm_elem si drum)len pt reconstruirea cuvantului

    for(int i = 0; i < cuv_len; i++)
    {
        dp[i]        = -1; // -1 = inca necalculat, 0 = fals, 1 = adevarat
        drum_elem[i] = -1; //  pt fiecare i in ordine crescatoare, drum_elem[i] = nr elementului
        drum_len[i]  =  0; // length pt fiecare simbol, 1 sau 2
    }

    if(DPcanForm(0, cuvant, cuv_len, dp, drum_elem, drum_len))
    {
        printf("Cuvantul %s se poate forma folosind simboluri din Tabelul lui Mendelev.\n", cuvant);
        afisareSolutie(drum_elem,drum_len, cuv_len);
    }else
    {
        printf("Cuvantul %s nu se poate forma folosind simboluri din Tabelul lui Mendelev.\n", cuvant);
    }


    free(dp);
    free(drum_elem);
    free(drum_len);
    return 0;
}