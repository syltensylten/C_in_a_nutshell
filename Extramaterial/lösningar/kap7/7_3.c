/* 7_3.c */

#include <stdio.h>      /* printf(), gets() */
#include <string.h>     /* strlen()         */

#define  TRUE  1
#define  FALSE 0

int  strcopy(unsigned max, char *original, char *copy)
{
 /* OBS max måste vara större än längden av original, ty sista 
  * positionen (max-1) är reserverad för '\0': 
  */
  if (strlen(original) >= max)
    return FALSE;
  else {
    while (*copy++ = *original++)
      ;
    return TRUE;
  }
}


/* Testprogram:*/

#define  MAXLEN 10

int main()
{
  char     original[81], copy[MAXLEN];

  printf("STRÄNGKOPIERING\n\n");
  printf("Skriv en teckensträng: ");
  gets(original);
  printf("\nOriginal: %s\n", original);
  if (strcopy(MAXLEN, original, copy))
    printf("Kopia   : %s\n", copy);
  else
    printf("\nKopieringen avbruten (kopiefältet för litet)!\n");
}

