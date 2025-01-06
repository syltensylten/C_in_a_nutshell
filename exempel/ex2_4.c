#include <stdio.h>

int main()    /* Beraknar medelvarde och maxvarde */
{
    float tal, sum, storsta;
    int ant;
    sum = 0;
    storsta = 0;
    ant = 0;
    printf("Skriv in talen.\n");    printf("Avsluta med END OF FILE.\n");

    while (scanf("%f", &tal) == 1) {
      ant++;
      sum += tal;
      if (tal > storsta) {
        storsta = tal;
      }
    }
    printf("Medelvardet: %f\n", sum / ant);
    printf("Storsta talet: %f\n", storsta);
}