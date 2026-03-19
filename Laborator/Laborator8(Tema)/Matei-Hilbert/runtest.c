#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    for(int i=1;i<=10;i++){
        char command[50];
        sprintf(command, "./divimp test%d.in", i);
        system(command);
    }
}
