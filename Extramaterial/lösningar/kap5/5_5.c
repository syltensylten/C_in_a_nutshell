/* 5_5.c */

#include <stdio.h> 

#define  MAXLEN  81

int main()
{
  char  ch, s[MAXLEN];  /* Bered plats f�r '\0' */
  int   i, len;

  printf("Skriv en textstr�ng (max %d tkn)\n", MAXLEN-1);
  fgets(s, MAXLEN, stdin);

  /* Best�m str�ngl�ngd: */
  for (len = 0; s[len] != '\0'; len++)
    ;   
  for (i = 0, --len; i < len; ++i, --len) {
    ch = s[i]; 
    s[i] = s[len];
    s[len] = ch;
  }

  printf("Texten bakl�nges:%s", s);
}

