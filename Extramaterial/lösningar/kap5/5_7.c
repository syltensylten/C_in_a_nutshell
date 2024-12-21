/* 5_7.c */

#include <stdio.h>   /* printf(), puts(), getchar(), EOF */

int main()
{
  float     medelradlangd;
  unsigned  radant = 0, tknant = 0;
  int       ch, oldCh;

  printf("Skriv in en text (avsluta med EOF)\n");
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      radant++;
    }
    else {
      tknant++;
    }
  }
  medelradlangd = (1.0*tknant)/radant;
  printf("Genomsnittligt antal tecken/rad = %.1f", medelradlangd);
}

