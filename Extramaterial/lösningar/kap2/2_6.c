/* 2_6.c */

#include <stdio.h>   /* printf(), scanf() */

int  kvad(int k)
{
  return k*k;
}


int  kub(int k)
{
  return k*k*k;
}


int main()
{
  int i, n;

  printf("Ange högsta i-värdet: ");
  scanf("%d", &n);
  printf(" i        i*i        i*i*i\n");
  printf("===      =====      =======\n\n");
  for (i = 1; i <= n; i++) {
    printf("%2d%11d%13d\n", i, kvad(i), kub(i));
  }
}

