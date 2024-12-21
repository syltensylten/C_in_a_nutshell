/* 8_4.c */

#include <stdio.h>
#include <stdlib.h>    /* malloc() */




struct tlist  {
                char          t;
                struct tlist  *rest;
              };


void  tinlist (struct tlist  *rad, struct tlist  *ny)
/* Att enbart ta bort referensanropet, som f�resl�s i problemtexten,
 * fungerar inte alls, inte ens om vi enbart anropar tinlist f�r att
 * infoga objekt inne i listan (dvs ins�ttning av element f�rst i
 * listan specialhanteras). F�r att kunna l�nka ihop listan beh�ver
 * vi h�r en "sl�ppekare", enligt nedan. 
 */
{
  struct tlist *fore;

  fore = NULL;
  while (rad != NULL && ny->t < rad->t) {
    fore = rad;
    rad = rad->rest;
  }
  ny->rest   = rad;
  fore->rest = ny;
}


void  skrivtlist (struct tlist  *rad)
{
  while (rad != NULL) {
    putchar(rad->t);
    rad = rad->rest;
  }
  putchar('\n');
}


int main()
{
  struct tlist  *ny, *rad;
  char          c;

  rad = NULL;

  while ((c = getchar()) != '\n') {
    ny = (struct tlist *) malloc(sizeof(struct tlist));
    /* malloc(n) motsvarar calloc(1, n) */
    ny->t = c;
    ny->rest = NULL;
    if (rad == NULL)
      rad = ny;
    else
      if (ny->t >= rad->t) {
        ny->rest = rad;
        rad = ny;
      }
      else
        tinlist(rad, ny);
  }
  skrivtlist(rad);
  getchar();
}
