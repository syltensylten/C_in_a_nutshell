/* 6_6.c */

#include <stdio.h>      /* printf(), scanf() */

unsigned int storsta_div (unsigned int m, unsigned int n)
{
  if (m == n) {
    return m;
  }
  else if (m > n) {
    return storsta_div(m-n, n);
  }
  else {
    return storsta_div(m, n-m);
  }
}

/* Test */
int main()
{
  unsigned heltal1, heltal2;

  printf("Ange 2 positiva heltal: "); 
  scanf("%u%u", &heltal1, &heltal2);
  printf("Största gemen divisor till %u och %u ", heltal1, heltal2);
  printf("är %u\n", storsta_div(heltal1, heltal2));
}
