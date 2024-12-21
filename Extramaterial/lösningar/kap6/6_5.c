/* 6_5.c */

#include <stdio.h> 
#include <math.h>  


double rot(double x)
{
  double  g, ny_gissning = x/2.0;

  do {
    g = ny_gissning;
    ny_gissning = (g + x/g) / 2.0;
  } while (fabs(g - ny_gissning) >= 1E-6);
  return ny_gissning;
}


/* Test */
int main()
{
  double  tal;

  printf("Ange ett tal/(sluta <= 0): "); scanf("%lf", &tal);
  while (tal > 0.0) {
    printf("Roten ur %f = %f\n", tal, rot(tal));
    printf("Ange ett tal/(sluta <= 0): "); scanf("%lf", &tal);
  }
}
