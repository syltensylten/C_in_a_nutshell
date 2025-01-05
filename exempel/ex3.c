#include <stdio.h>
#define ANTAL_AR 10
int main()
{
    float kap, ranta;
    int ar;
    printf("Insatt kapital? "); scanf("%f", &kap);
    printf("Ranta? ");          scanf("%f", &ranta);
    printf("\n Ar       Saldo\n ==       =====\n");
    for (ar = 1; ar <= ANTAL_AR; ar++) {
        kap = kap * (1 + ranta / 100);
        printf("%3d%13.2f\n", ar, kap);
    }
}
