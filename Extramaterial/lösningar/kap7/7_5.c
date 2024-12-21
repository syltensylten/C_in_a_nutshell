/* 7_5.c */

#include <stdio.h>      /* printf(), puts(), scanf() */

void  SkrivDag(unsigned num)
{
  static char *dagnamn[] =
    {"s�ndag", "m�ndag",  "tisdag", "onsdag",
     "torsdag", "fredag", "l�rdag" };

  printf("Dag nr %u �r en %s.\n", num, dagnamn[num % 7]);
 /* Alt med pekare:
  printf("Dag nr %u �r en %s.\n", num, *(dagnamn + num % 7));
 */
}


int main()
{
  unsigned  dagnum;

  puts("Programmet skriver ut den veckodag som svarar mot");
  puts("visst dagnummer (r�knat f o m 1/1 1990).\n");
  printf("Ange dagnummer (1..): ");
  scanf("%u", &dagnum);
  SkrivDag(dagnum);
}
