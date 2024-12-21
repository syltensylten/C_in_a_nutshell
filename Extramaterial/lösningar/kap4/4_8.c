/* 4_8.c */

/* I programmet förutsätts att int lagras med 16 bitar.
 * Skulle ditt system ha 32 bitars int,
 * kan du byta ut unsigned int mot unsigned short int, UINT_MAX
 * mot USHRT_MAX och %u mot %hu.
 */

#include <stdio.h>  
#include <limits.h> 

int main()  /* Med test */
{
  unsigned  int  m, temp;
  unsigned  char rest;
  int       siffra;
  char      s[5];

  puts("OMVANDLING TILL HEX\n");
  printf("Ange ett heltal (0-%u): ", UINT_MAX); scanf("%u", &m);
  temp = m;
  for (siffra = 3; siffra >= 0; siffra--) {
    rest = temp % 16;
    s[siffra] = rest + (rest >= 0 && rest <= 9 ? '0' : 'A'-10);
    temp >>= 4;
  }
  s[4] = '\0';
  printf("\nHeltalet %u är %s i hexadecimal form\n", m, s);
}

