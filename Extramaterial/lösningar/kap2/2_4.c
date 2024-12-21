/* 2_4.c */

#include <stdio.h>   /* printf() */

#define SLUTSUMMA 1000000.0

int main()
{
  int    dag = 0;
  float  sum = 0, lon = 0.01;

  while (sum < SLUTSUMMA) {
    sum = sum + lon;    /* Kortare: sum += lon; */
    lon = 2*lon;        /* Kortare: lon *= 2; */
    dag++;
  }
  printf("Han m�ste jobba %d dagar f�r %.0f kr.\n", dag, SLUTSUMMA);
}

