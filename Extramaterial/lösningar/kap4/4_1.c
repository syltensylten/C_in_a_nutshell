/* 4_1.c */

#include <stdio.h>

int i = 3, j = 7;

int main()
{
  printf("a.  %d\n", i <= j);
  printf("b.  %d\n", i = j);
  i = 3; j = 7;
  printf("c.  %d\n", 2 + j % i);
  printf("d.  %d\n", j/i*2);
  printf("e.  %d\n", i && i - 3);
  printf("f.  %d\n", (++i < 3) ? !i : j);
  i = 3; j = 7;
  printf("g.  %d\n", i & j);
  printf("h.  %d\n", j <<= i);
}

