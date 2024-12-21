/* 6_3.c */

#include <stdio.h>  
#include <math.h>  

double upphoj(double x, double y)
{
  return exp(y*log(x));
}

/* Test */
int main()
{
  double  bas, exponent;

  printf("Ange en positiv bas/(sluta <= 0): ");
  scanf("%lf", &bas);
  while (bas > 0.0) {
    printf("Ange exponent: "); scanf("%lf", &exponent);
    printf("%f^%f = %f\n", bas, exponent, upphoj(bas, exponent));
    printf("Ange en positiv bas/(sluta <= 0): ");
    scanf("%lf", &bas);
  }
}
