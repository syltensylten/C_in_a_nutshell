#include <stdio.h>

int main() 
{
    float kap, onskat, ranta;
    int ar;
    printf("Insatt kapital? "); scanf("%f", &kap);
    printf("Onskat kapital? "); scanf("%f", &onskat);
    printf("Ranta? ");          scanf("%f", &ranta);
    ar = 0;

    while (kap < onskat) {
        ar += 1;
        kap = kap * (1 + ranta / 100);
    }

printf("Kapitalet måste spara i %d år.\n", ar);

}
