/* 5_6.c */

#include <stdio.h>

#define   MAXLEN 81

int main()
{
  char  s[MAXLEN+1], temp;
  int   i, bytt, len;

  printf("BUBBLESORT\n");
  printf("Skriv en textsträng (max %d tkn)\n", MAXLEN-1);
  fgets(s, MAXLEN, stdin);

  /* Bestäm stränglängd */
  for (len = 0; s[len]; len++)   /* alt: s[len] != '\0' */
    ;
  /* och sortera */
  do {
    bytt = 0;
    for (i = 0; i < len-1; i++) {
      if (s[i] > s[i+1]) {
        temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
        bytt = 1;
      }
    }
  } while (bytt);

  printf("Tecknen sorterade = %s", s);
}

