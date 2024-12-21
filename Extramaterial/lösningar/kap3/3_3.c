/* 3_3.c */

#include <stdio.h>    /* printf(), puts(), getchar() */
#include <limits.h>   /* CHAR_BIT = antal bitar/char */

int main()
{
  printf("Heltalstyp             Antal bitar\n\n");
  printf("signed char            %9d\n", CHAR_BIT);
  printf("unsigned char          %9d\n", CHAR_BIT);
  printf("         short int     %9d\n", CHAR_BIT*sizeof(short int));
  printf("unsigned short int     %9d\n", CHAR_BIT*sizeof(unsigned short int ));
  printf("         int           %9d\n", CHAR_BIT*sizeof(int));
  printf("unsigned int           %9d\n", CHAR_BIT*sizeof(unsigned int));
  printf("         long int      %9d\n", CHAR_BIT*sizeof(long));
  printf("unsigned long int      %9d\n", CHAR_BIT*sizeof(unsigned long));
  printf("         long long int %9d\n", CHAR_BIT*sizeof(long long));
  printf("unsigned long long int %9d\n", CHAR_BIT*sizeof(unsigned long long int));
}

