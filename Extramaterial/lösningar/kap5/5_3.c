/* 5_3.c */

#include <stdio.h> 
#include <math.h>  

#define  DEGTORAD 3.1415926536/180;
#define  EPSILON  1E-8

int main()
{
  double  degrees, x, x2, term = 1., sum = 0.;
  unsigned int i = 0;

  printf("Beräkning av cos(x) med Maclaurinserie\n");
  printf("Ange x-värdet (i grader): ");
  scanf("%lf", &degrees);
  x  = degrees*DEGTORAD;
  x2 = x*x;
  do {
    sum += term;
    i += 2;
    term *= -x2/(i*(i - 1));
  } while (fabs(term) >= EPSILON);
  printf("\ncos(%.2f) = %f\n", degrees, sum);
}

