/* 2_8.c */

#include <stdio.h>   /* printf(), getchar(), EOF */

int main()
{
  int ch, radantal = 0;

  printf("Skriv in text. Avsluta med EOF.\n");
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      radantal++;
    }
  }
  printf("\nAntal rader = %d\n", radantal);
}

