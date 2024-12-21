/* 4_5.c */



#include <stdio.h> 

/* Vi antar en åttabitars kodning med ASCII för de första 128 tecknen, t.ex. LATIN_1 */
/* Om detta program körs på Windows måste man använda en texteditor som använder
   DOS-kodning för att programmet skall fungera korrekt */

int main()  /* test */
{
  unsigned char  c1, c2;
  int            bokstavsordning;

  puts("ALFABETISK ORDNING\n");
  printf("Skriv en liten bokstav: ");
  scanf(" %c", &c1);   /* OBS blanktecknet före %c */
  printf("Skriv en liten bokstav: ");
  scanf(" %c", &c2);

  bokstavsordning = 
    (c1 <= 'z' && c1 < c2) ||
    (c1 == (unsigned char) 'å' && (c2 == (unsigned char) 'ä' || c2 == (unsigned char) 'ö')) ||
    (c1 == (unsigned char) 'ä' && c2 == (unsigned char) 'ö');

  printf("\nTecknen %c och %c är ", c1, c2);
  if (!bokstavsordning)
    printf("inte ");
  printf("i bokstavsordning", c1, c2);
}

