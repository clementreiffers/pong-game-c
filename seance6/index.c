#include <stdio.h>
#include <stdlib.h>

typedef int nombre;

int longueur_tableau(char*);
int longueur_tableau_leo(char *);
int longueur_tableau_3(char *);
int longueur_tableau_rec(char *);

int main(int argc, char const *argv[]){
    // nombre nombre;
    // char word[20];
    // printf("Pouvez-vous entrer un nombre : ");
    // scanf("%d", &nombre);
    // printf("%d\n", nombre);

    // printf("donne un mot mon brave :");
    // scanf("%s", word);
    // printf("%s\n", word);

    // premiere methode : NE PAS UTILISER
    // long int tab[nombre];
    // printf("%ld\n", sizeof(tab[0]));
    // printf("%ld\n", sizeof(tab));

    // deuxieme methode : mieux
    // int* tab2;
    // tab2 = malloc(nombre * sizeof(int)); // on alloue de la memoire 
    // if(tab2!=NULL) {
    //     printf("%d \n", tab2[2]);
    // }
    // free(tab2); // liberer la memoire

    char tab3[] = "salut !!";
    printf("%ld \n", sizeof(tab3));

    printf("longueur de la chaine : %d \n", longueur_tableau_rec(tab3));

    return 0;
}
int longueur_tableau_rec(char* tab) {
    // if(tab[0]==0)
    //     return 0;
    // else 
    //     return 1+longueur_tableau_rec(tab+1);
    return *tab==0 ? 0 : 1+longueur_tableau_rec(tab+1);
}

int longueur_tableau_3(char* tab) {
    int i = 0;
    while(*(tab+i)) // equivalent à tab[i]
        i++;
    return i;
}

int longueur_tableau_leo(char* tab) {
    int placement = 0;
    char a;
    do {
        a = tab[placement];
        printf("%d %c \n",placement, a);
        placement++;
    } while(a);
    return placement -1;
}

int longueur_tableau(char* tab) {
    int etat = 1, placement = 0;
    while(etat == 1) {
        char a = tab[placement];
        printf("%d %c \n",placement, a);
        if(a != 0) {
            placement++;
        }
        else {
            etat = 0;

        }

    }
    return placement;
}