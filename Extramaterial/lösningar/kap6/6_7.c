/* 6_7.c */

#include <stdio.h>  

int main()
{
  /* externa variabler */
  extern char  rad[];
  extern int   nasta;

  /* externa funktioner */
  extern int   las_rad (void);
  extern void  ta_bort_blanka (void);
  extern int   identifierare (void);
  extern int   uttryck (void);
  extern void  fel (char text[]);

  /* lokala variabler */
  int  i = 0, tilldelning = 0;

  if (las_rad()) {
    while (rad[i] != ';' && rad[i] != '\0') {
      i++;
    }
    if (rad[i] == ';') {
      rad[i] = ' ';
      ta_bort_blanka();
      if (identifierare()) {
        ta_bort_blanka();
        if (rad[nasta++] == '=') {
          if (uttryck()) {
            tilldelning = 1;
          }
        }
      }
    }
    else {
      nasta = i;
      fel("; Saknas");
    }
  }
  if (tilldelning) {
    printf("Detta är en korrekt tilldelningssats.\n");
  }
  else {
    printf("Detta är en felaktig tilldelningssats.\n");
  }
}
