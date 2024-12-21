/* 5_5.c */

#include <stdio.h> 

#define  MAXLEN  81

int main()
{
  char  ch, s[MAXLEN];  /* Bered plats för '\0' */
  int   i, len;

  printf("Skriv en textsträng (max %d tkn)\n", MAXLEN-1);
  fgets(s, MAXLEN, stdin);

  /* Bestäm stränglängd: */
  for (len = 0; s[len] != '\0'; len++)
    ;   
  for (i = 0, --len; i < len; ++i, --len) {
    ch = s[i]; 
    s[i] = s[len];
    s[len] = ch;
  }

  printf("Texten baklänges:%s", s);
}

