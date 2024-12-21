/* 7_1.c */

#include <stdio.h>      /* printf(), gets() */
#include <string.h>     /* strlen()         */

void  reverse(char *s)
{
  char  c, *tail;

  for (tail = s+strlen(s)-1; s < tail; s++, tail--)
  {
    c = *s;
    *s = *tail;
    *tail = c;
  }
}


#define  MAXLEN 80

int main() /* Testprogram */
{
  char     s[MAXLEN+1];

  printf("STR�NGHANTERING MED PEKARE\n\n");
  printf("Skriv en str�ng (max %u tkn) : ", MAXLEN);
  gets(s);
  reverse(s);
  printf("\nStr�ngens utseende efter v�ndning = %s\n", s);
}
