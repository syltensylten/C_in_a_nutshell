/* 5_4.c */

#include <stdio.h> 

int main()
{
  char  s[12];
  int   ok, i, sum, temp;

  printf("PERSONNUMMERKONTROLL\n");
  printf("Skriv ett personnummer (format YYMMDD-XXXX): ");
  scanf("%11s", s);      /* L�ser max 11 tkn */

  for (i = 0; s[i]; i++)
    ;
  if (i != 11)    /* Kontrollera str�ngl�ngd */
  {
    ok = 0;
  }
  else {
    for (i = 6; s[i] = s[i+1]; i++)      /* Avl�gsna - */
      ;
    /* Kontrollera att �terstoden �r siffror */
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
      ;
    if (s[i] != '\0')   /* Kortare: if (s[i]) */
    {
      ok = 0;
    }
    else {
      /* Borde �ven testa att datum �r rimligt */
      sum = 0;
      for (i = 0; i < 10; i++) {
        temp = (s[i] - '0');
        sum += (i % 2) ? temp : (temp *= 2, temp/10 + temp % 10);
      }
      ok = sum % 10 == 0;
    }
  }
  printf("\nPersonnumret �r %s.", ok ? "korrekt" : "felaktigt");
}

