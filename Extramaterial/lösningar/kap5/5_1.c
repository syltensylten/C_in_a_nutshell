/* 5_1.c a och b */

#include <stdio.h> 

float f(float x)
{
  return ((3*x - 5)*x + 2) * x - 20;
}

int main()
{
  float     x;

  /* a */
  printf("      x                         f(x)\n");
  for (x = -10; x <= 10; x += 1) {
    printf("%10.4f%28.4f\n", x, f(x));
  }

  /* b */
  printf("      x                         f(x)\n");
  for (x = -2; x <= 2; x += 0.1) {
    printf("%10.4f%28.4f\n", x, f(x));
  }
}

