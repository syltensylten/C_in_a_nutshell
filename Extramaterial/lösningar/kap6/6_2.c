/* 6_2.c */

#include <stdio.h>

void skriv_flera (char c, unsigned int n)
{
  unsigned int i;

  for (i = 0; i < n; i++)
    putchar(c);
}

int main()
{
  skriv_flera('_', 80);
}
