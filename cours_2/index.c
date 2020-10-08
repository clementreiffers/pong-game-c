#include <stdio.h>
int main(){
    char a; // caractere 1 octet
    short x; // entier 2 octets
    int n; // entier 4 octets
    long m; // entier 8 octets

    float s; // reel 4 octets
    double y; // reel 8 octets
    long double z; // reel 16 octets

    n = 1;
    printf(" < int > %d \n", sizeof(n));
    printf("Hello World !");
    return 0;
} 