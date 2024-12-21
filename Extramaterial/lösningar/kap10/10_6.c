/* 10_6.c */

#include <stdio.h>
#include <string.h>  /* strchr, strtok, strcat */
#include <ctype.h>   /* isalpha, toupper */

#define  MAXLEN  80

void SmaTillStora(char *s)
{
  for (; *s; s++)
    switch (*s) {
      case 'å':
        *s = 'Å'; break;
      case 'ä':
        *s = 'Ä'; break;
      case 'ö':
        *s = 'Ö'; break;
      default:
        *s = toupper(*s);
    }
}


int  Vokal (char  tecken)
{
  return (strchr("aeiouyåäöAEIOUYÅÄÖ", tecken) != NULL && tecken);
}


int  KonsonantVokal(char *ord)
{
  return (isalpha(*ord) && Vokal(*(ord+1)));
}


int  Stavelse(char *ord) /* Testar om vokal finns i orddelen */
{
  int vok = 0;

  while (!vok && *ord)
    vok = Vokal(*ord++);
  return vok;
}


int  Forstavelse(char *ord, int *len)
{
  static char *s[] = {"CH", "CK", "NG", "X"};
  int i, antal = sizeof(s)/sizeof(char *);

  for (i=0; i < antal && strncmp(ord, s[i], strlen(s[i])); i++)
    ;
  if (i < antal)
    *len = strlen(s[i]);
  else
    *len = 0;
  return (*len > 0);
}


int  Efterstavelse(char *startord, char *ord, int *len)
{
  static char *s[] =
    {"SIO", "TIO", "SCH", "SKJ", "STJ", 
     "SJ", "SK", "TJ", "LJ",  "HJ"};

  int i, antal = sizeof(s)/sizeof(char *);

  *len = 0;
  if (ord > startord) {
    for (i=0; i < antal && strncmp(ord, s[i], strlen(s[i])); i++)
      ;
    if (i < antal)
      *len = strlen(s[i]);
    else if (KonsonantVokal(ord))
      *len = 1;
  }
  return (*len != 0);
}


void  Avstava (char  *ord, char  *nyord)
{
  char *ordstart = ord;
  char storord[MAXLEN], *storpek;
  int  len;

  strcpy(storord, ord);
  SmaTillStora(storord);
  while (! Vokal(*ord) && *ord)
    *nyord++ = *ord++;
  while (*ord) {
    storpek = storord + (ord - ordstart);
    if (Vokal(*ord) && Vokal(*(ord+1))) {
      *nyord++ = *ord++;
      *nyord++ = '-';
      *nyord++ = *ord++;
    }
    else if (Efterstavelse(storord, storpek, &len)) {
      if (*(nyord-1) != '-' && Stavelse(ord+len))
        *nyord++ = '-';
      while (len--)
        *nyord++ = *ord++;
    }
    else if (Forstavelse(storpek, &len)) {
      while (len--)
        *nyord++ = *ord++;
      if (Stavelse(ord))
        *nyord++ = '-';
    }
    else
      *nyord++ = *ord++;
  }
  *nyord = '\0';
}


int main()
{
  FILE  *intext, *uttext;
  char  rad[MAXLEN+1], nyrad[2*MAXLEN+1];
  char  *ord, *blankpos, nyord[2*MAXLEN+1];
  int   i;

  if ((intext = fopen("INFIL.TXT", "r")) == NULL)
    printf("INFIL.TXT kan inte öppnas!");
  else {
    uttext = fopen("UTFIL.TXT", "w");
    while (fgets(rad, MAXLEN, intext)) {
      nyrad[0] = '\0';
      blankpos = rad;
      ord = strtok(rad, " ");
      while (ord) {   /* Kort skrivsätt för while (ord != NULL) */
        Avstava(ord, nyord);
        for (i=0; i< ord-blankpos; i++)
          strcat(nyrad, " ");
        strcat(nyrad, nyord);
        blankpos = ord + strlen(ord);
        ord = strtok(NULL, " ");
      }
      fputs(nyrad, uttext);
    }
    fclose(intext);
    fclose(uttext);
  }
}
