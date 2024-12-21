/* 8_1.c */

/* Utnyttjar tidm�tning (behandlas i l�robokens kapitel 10)
 * Om C-systemet saknar rutiner f�r tidm�tning kan denna
 * utf�ras f�r hand i st�llet. 
 */

#include <stdio.h>    /* printf(), scanf() */
#include <time.h>     /* clock(), CLOCKS_PER_SEC, clock_t */

#define  ANTAL_BYTES 800



typedef struct {
                 char f[ANTAL_BYTES];
               } PostTyp;


void  VardeFunk (PostTyp  post)
{
}


void  RefFunk (PostTyp  *post)
{
}


int main()
{
  static PostTyp post;
  unsigned long  i, antal;
  clock_t        startTime;
  double         totalTime;

  printf("Ange antalet anrop: "); scanf("%lu", &antal);
  printf("\nStart v�rdeanrop!\n");
  startTime = clock();
  for (i = 0; i < antal; i++)
    VardeFunk(post);
  totalTime = (clock() - startTime)/(double)CLOCKS_PER_SEC;
  printf("Tid f�r v�rdeanrop = %.2f sek\n", totalTime);
  printf("\nStart referensanrop!\n");
  startTime = clock();
  for (i = 0; i < antal; i++)
    RefFunk(&post);
  totalTime = (clock() - startTime)/(double)CLOCKS_PER_SEC;
  printf("Tid f�r referensanrop = %.2f sek\n", totalTime);
}
