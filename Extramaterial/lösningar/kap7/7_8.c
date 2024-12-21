/* 7_8.c */

#include <stdio.h>      /* printf() */
#include <math.h>       /* sqrt() */


double  TestFunc(double x)
{
  return sqrt(4 - x*x);
}


double  Simpson(double a, double b, double (*f)(double), int n)
{
  double  jamnSum, uddaSum, h;
  int     i;

  jamnSum = uddaSum = 0.0;
  h = (b - a)/(2.0*n);
  for (i = 1; i <= n - 1; i++)
    jamnSum += f(a + 2.0*i*h);
  for (i = 1; i <= n; i++)
    uddaSum += f(a + (2.0*i - 1)*h);
  return h*(f(a) + f(b) + 2.0*jamnSum + 4.0*uddaSum)/3.0;
}


int main()  /* Test */
{
  printf("%1.4f\n", Simpson(0, 2, TestFunc, 200));
}

