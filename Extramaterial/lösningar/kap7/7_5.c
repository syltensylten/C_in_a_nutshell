/* 7_5.c */

#include <stdio.h>      /* printf(), puts(), scanf() */

void  SkrivDag(unsigned num)
{
  static char *dagnamn[] =
    {"söndag", "måndag",  "tisdag", "onsdag",
     "torsdag", "fredag", "lördag" };

  printf("Dag nr %u är en %s.\n", num, dagnamn[num % 7]);
 /* Alt med pekare:
  printf("Dag nr %u är en %s.\n", num, *(dagnamn + num % 7));
 */
}


int main()
{
  unsigned  dagnum;

  puts("Programmet skriver ut den veckodag som svarar mot");
  puts("visst dagnummer (räknat f o m 1/1 1990).\n");
  printf("Ange dagnummer (1..): ");
  scanf("%u", &dagnum);
  SkrivDag(dagnum);
}
