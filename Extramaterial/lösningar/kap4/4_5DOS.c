/* 4_5.c */



#include <stdio.h>

/* Vi antar en †ttabitars kodning med ASCII f”r de f”rsta 128 tecknen, t.ex. LATIN_1 */
/* Om detta program k”rs p† Windows m†ste man anv„nda en texteditor som anv„nder
   DOS-kodning f”r att programmet skall fungera korrekt */

int main()  /* test */
{
  unsigned char  c1, c2;
  int            bokstavsordning;

  puts("ALFABETISK ORDNING\n");
  printf("Skriv en liten bokstav: ");
  scanf(" %c", &c1);   /* OBS blanktecknet f”re %c */
  printf("Skriv en liten bokstav: ");
  scanf(" %c", &c2);

  bokstavsordning =
    (c1 <= 'z' && c1 < c2) ||
    (c1 == (unsigned char) '†' && (c2 == (unsigned char) '„' || c2 == (unsigned char) '”')) ||
    (c1 == (unsigned char) '„' && c2 == (unsigned char) '”');

  printf("\nTecknen %c och %c „r ", c1, c2);
  if (!bokstavsordning)
    printf("inte ");
  printf("i bokstavsordning", c1, c2);
}

