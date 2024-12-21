/* 4_7.c */

#include <stdio.h> 

int main()  /* Test */
{
  unsigned char  c;
  unsigned int   temp, nibblesumma;
  
  printf("Ge ett heltal (0 - 15): "); scanf("%d", &temp);
  c = temp << 4;
  printf("Ge ett heltal (0 - 15): "); scanf("%d", &temp);
  c = c | temp;   /* Kortare c |= temp; */
  nibblesumma = (c & 0xf) + (c >> 4);   /* Uttrycket */
  printf("\nTalsumma = %d\n", nibblesumma);
}

