#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int board[9][9];
    int init_board[9][9];
    int region[9][9];
    bool row_used[9][10];
    bool col_used[9][10];
    bool region_used[9][10];
    unsigned int mutari;
}gameState;

//Backtracking
bool can_place(gameState *st, int r, int c, int num) {
    return !st->row_used[r][num] && !st->col_used[c][num] && !st->region_used[st->region[r][c]][num];
}

void place(gameState *st, int r, int c, int num) {
    st->board[r][c] = num;
    st->row_used[r][num] = st->col_used[c][num] = st->region_used[st->region[r][c]][num] = true;
}

void remove_num(gameState *st, int r, int c, int num) {
    st->board[r][c] = 0;
    st->row_used[r][num] = st->col_used[c][num] = st->region_used[st->region[r][c]][num] = false;
}

void printBoard(gameState *st){
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++)
            printf("%d ", st->board[r][c]);
        printf("\n");
    }
}


bool BT_solve(gameState *st){
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(st->board[r][c] == 0){ // Daca cell e gol
                for(int num = 1; num <=9; num++){ // testam fiecare nr
                    if(can_place(st, r, c, num)){ // verificam daca putem sa il punem prin a verifica coloana/linie
                        place(st, r, c, num); // pune
                        st->mutari++; // nr de mutari / incercari de nr
                        if(BT_solve(st)) // intram recursiv in BT
                            return true; 
                        remove_num(st, r, c, num); // curatam cell-ul
                    }
                }
                return false; // nu avem nr valid si ne duce la a sterge acel nr pus
            }
        }
    }
    return true; //rezolvat

}



int main(int argc, char **argv){
    int n;
    char init_name[] = "./puzzles/";
    if(argc <2){
        printf("Utilizare corecta: ./jigsaw_sudoku <filename>\n");
        return 1;
    }
    char filename[64];
    strcpy(filename, init_name);
    strcat(filename, argv[1]);

    FILE *f = NULL;
    if((f = fopen(filename, "r")) == NULL){
        printf("FIsierul nu exista\n");
        return 1;
    }

    gameState state = {
        .board = { {0} },
        .init_board = { {0} },
        .region = { {0} },
        .row_used = { {false} },
        .col_used = { {false} },
        .region_used = { {false} },
        .mutari = 0
    };

    char read_buffer[64];
    char type = 0;
    int ij = 0;
    
    while (fgets(read_buffer, sizeof(read_buffer), f) != NULL) {
        if (read_buffer[0] == '/') {
            type++;
            continue; 
        } // Trecem peste comentarii
        if (type == 1) { // Citim regiunile
            int col = 0;
            for (int i = 0; i < strlen(read_buffer); i++) {
                if (read_buffer[i] != ' ' && read_buffer[i] != '\n') {
                    char c = read_buffer[i];
                    state.region[ij][col++] = c - '0';
                }
            }
            ij++;
        } else { // Citim valorile initiale
            int x, y, val;
            if (sscanf(read_buffer, "%d %d %d", &x, &y, &val) == 3) {
                state.init_board[x][y] = val;
            }
        }
    }
    
    // Setup state
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (state.init_board[i][j] != 0) {
                int val = state.init_board[i][j];
                state.board[i][j] = val;
                state.row_used[i][val] = true;
                state.col_used[j][val] = true;
                state.region_used[state.region[i][j]][val] = true;
            }
        }
    }
    

    printf("Regions:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", state.region[i][j]);
        printf("\n");
    }
    printf("Initial Board:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", state.board[i][j]);
        printf("\n");
    }

    if(BT_solve(&state)){
        printf("Rezolvare gasita:\n");
        printBoard(&state);
    }else{
        printf("Nu exista solutie!\n");
    }

    printf("Cu %d mutari.\n", state.mutari);


    fclose(f);
    return 0;
}
