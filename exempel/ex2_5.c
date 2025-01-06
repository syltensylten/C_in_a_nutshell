#include <stdio.h>

float max(float x, float y)     /* funktion för att ge maxvärde */
{

  if (x > y) {
    return x;
  }
  else {
    return y;
  }
}

int main()                      /* Beräknar största värde samt medelvärde */
{
      float tal, sum, storsta;
      int ant;
      sum = 0;
      ant = 0;
      storsta = 0;
      printf("Skriv in talen.\n"); printf("Avsluta med EOF ( CTRL + D )\n");
      while (scanf("%f", &tal) == 1) {
        ant++;
        sum += tal;
        storsta = max(storsta, tal);
      }
      printf("Medelvardet: %f\n", sum / ant );
      printf("Storsta vardet: %f\n", storsta);
}