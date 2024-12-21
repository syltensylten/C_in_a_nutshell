/* 5_2.c */

#include <stdio.h> 

#define  POPULATION 26000
#define  BIRTHRATE      0.007
#define  DEATHRATE      0.006
#define  IMMIGRATION  300
#define  EMIGRATION   325

int main()
{
  unsigned  year, now, i, newPopulation;
  float     p;

  printf("BEFOLKNINGSUTVECKLING\n");
  printf("Vilket år är det nu? "); 
  scanf("%u", &now);   
  printf("Vilket år gäller prognosen för? "); 
  scanf("%u", &year);

  p = POPULATION;
  for (i = now; i < year; i++) {
    p = p*(1. + BIRTHRATE - DEATHRATE) + (IMMIGRATION - EMIGRATION);
  }
  newPopulation = p + 0.5;
  printf("Uppskattat invånarantal %u = %u\n", year, newPopulation);
}

