/* 2_3.c */

#include <stdio.h>   /* printf(), scanf() */

int main()
{
  int  n, i, i2;

  printf("Ange högsta i-värdet: ");
  scanf("%d", &n);
  printf(" i        i*i        i*i*i\n");
  printf("===      =====      =======\n\n");
  for (i = 1; i <= n; i++) {
    i2 = i*i;
    printf("%2d%11d%13d\n", i, i2, i2*i);
  }
}
