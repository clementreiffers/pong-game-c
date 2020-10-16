#include <stdio.h>

struct Complexe
{
    double re;
    double im;
};

typedef struct Complexe complexe;
typedef int entier;

void afficherComplexe();

int main(int argc, char const *argv[]) {
    struct Complexe z;
    printf("%ld\n", sizeof(double)); // on affiche le nombre d'octets d'un double, donc ici 8bits
    printf("%ld \n", sizeof(struct Complexe)); // on affiche le nombre d'octets d'une structure de 2 doubles

    z.re = 4;
    z.im = 6;

    printf("%.2f %.2f \n", z.re, z.im);
    
    struct Complexe z2; 
    
    z2.re = 8 ;
    z2.im = 9;
    afficherComplexe(z2);
    complexe z3;
    z3.re = 8;
    z3.im = 4;
    afficherComplexe(z3);

    entier n = 10;


    return 0;
}

void afficherComplexe(complexe z) {
    // le parametre est passé par valeur
    printf("%.2f + i%.2f \n", z.re, z.im);
}
