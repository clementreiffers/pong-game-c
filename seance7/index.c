/*

programme pour calculer la factorielle d'un entier 
avec une fonction récursive et une fonction itérative

    ./fact [n] [version_fonction]

    n : nombre entier 
    version_fonction : recu ou iter

on compilera d'abord factorielle.c en .o :
	gcc -c factorielle.c
puis on met cette compilation dans cette de index.c :
	gcc -o fact index.c factorielle.o 

on peut mettre aussi :
    -   gcc -c main.c
    -   gcc -c factorielle.c
    -   gcc -o main.o factorielle.o

*/

#include <stdio.h> // aller chercher dans certains répertoires (en general les usr/include)
#include <stdlib.h>
#include <string.h>

#include "factorielle.h" // aller chercher au chemin relatif donne, ici c'est le répertoire courant

int main(int argc, char* argv[]) {
    /*
    printf("nombre d'argument en entrée : %d \n", argc);
    for(int i=0; i<argc; i++) {
        printf("%s\n", argv[i]);
    }
    */
    long n = strtol(argv[1], NULL, 10); // string to long
    if(!strcmp(argv[2], "iter")) {
        printf("factorielle iterative \n");
        printf("%d\n" , factiter((int) n));
    }
    if(!strcmp(argv[2], "recu")) {
        printf("factorielle recursive \n");
        printf("%d\n" , factrecu((int) n));
    }

    return 0;
}