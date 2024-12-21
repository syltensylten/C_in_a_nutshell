/* 4_3.c */

#include <stdio.h>   /* printf(), scanf() */

int main()
{
  int  pris, sum, rest, n;

  printf("Ange varans pris (i hela kr): ");
  scanf("%d", &pris);
  printf("Ange lämnat belopp (i hela kr): ");
  scanf("%d", &sum);
  printf("Växel tillbaka:\n");
  rest = sum - pris;
  n = rest/100;
  if (n > 0) {  
    printf("%d hundrakronorssed%s\n", n, n == 1 ? "el" : "lar");
  }
  rest %= 100;
  n = rest/50;
  if (n > 0) {
    printf("1 femtiokronorssedel\n");
  }
  rest %= 50;
  n = rest/10;
  if (n > 0)
    printf("%d tiokronorssed%s\n", n, n == 1 ? "el" : "lar");
  rest %= 10;
  n = rest/5;
  if (n > 0) {
    printf("1 femkronorsmynt\n");
  }
  rest %= 5;
  if (rest > 0) {
    printf("%d enkron%s\n", rest, rest == 1 ? "a" : "or");
  }
}

