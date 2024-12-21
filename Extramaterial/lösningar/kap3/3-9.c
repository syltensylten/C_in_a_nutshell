#include <stdio.h>

int main()
{
  int ar1, man1, dag1;
  int ar2, man2, dag2, n, k;
  printf("Ange dagens datum som 20åå-mm-dd\n");
  if (scanf("%4d-%2d-%2d", &ar1, &man1, &dag1) != 3) {
    printf("Felaktigt datum\n");
    return 1;
  }
  printf("Ange personnummer som ååmmdd-xxxx\n"); 
  if (scanf("%2d%2d%2d-%3d%1d", &ar2, &man2, &dag2, &n, &k) != 5) {
    printf("Felaktigt personnummer\n");
    return 2;
  }
  if (man1 == man2) {
    if (dag1 == dag2) {
      printf("Grattis!\n");
    }
  }
}
