#include <stdio.h>
/* Version 1 enkel inl�sning */
int main()
{
  char pnr[11];
  int n;
  printf("Ange personnummer som ��mmdd-xxxx\n"); 
  scanf("%s", pnr);
  n = pnr[8] - '0';    /* fr�n teckenkod till sifferv�rde */
  if (n % 2 == 0) {
    printf("Kvinna\n");
  }
  else {
    printf("Man\n");
  }
}

/* Version 2, med kontroll */
/*
int main()
{
  int ar, man, dag, n, k;
  printf("Ange personnummer som ��mmdd-xxxx\n"); 
  if (scanf("%2d%2d%2d-%3d%1d", &ar, &man, &dag, &n, &k) == 5) {
    if (n % 2 == 0) {
      printf("Kvinna\n");
    }
    else {
      printf("Man\n");
    }
  }
  else {
    printf("Felaktigt personnummer\n");
  }
}
*/
