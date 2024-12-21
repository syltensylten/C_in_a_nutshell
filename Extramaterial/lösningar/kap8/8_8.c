/* 8_8.c */

#include <stdio.h>

typedef struct {
                 unsigned bit0  : 1;
                 unsigned bit1  : 1;
                 unsigned bit2  : 1;
                 unsigned bit3  : 1;
                 unsigned bit4  : 1;
                 unsigned bit5  : 1;
                 unsigned bit6  : 1;
                 unsigned bit7  : 1;
                 unsigned bit8  : 1;
                 unsigned bit9  : 1;
                 unsigned bit10 : 1;
                 unsigned bit11 : 1;
                 unsigned bit12 : 1;
                 unsigned bit13 : 1;
                 unsigned bit14 : 1;
                 unsigned bit15 : 1;
               }  Integer;

typedef union {
                int     heltal;
                Integer bitar;
              }  Heltalstyp;

int main()
{
  Heltalstyp  tal;
  char        tecken;

  do {
    printf("\nAnge ett decimalt heltal: ");
    scanf("%d%*c", &tal.heltal);
    printf("Heltalet i binär form = ");
    printf("%u", tal.bitar.bit15);
    printf("%u", tal.bitar.bit14);
    printf("%u", tal.bitar.bit13);
    printf("%u ", tal.bitar.bit12);
    printf("%u", tal.bitar.bit11);
    printf("%u", tal.bitar.bit10);
    printf("%u", tal.bitar.bit9);
    printf("%u  ", tal.bitar.bit8);
    printf("%u", tal.bitar.bit7);
    printf("%u", tal.bitar.bit6);
    printf("%u", tal.bitar.bit5);
    printf("%u ", tal.bitar.bit4);
    printf("%u", tal.bitar.bit3);
    printf("%u", tal.bitar.bit2);
    printf("%u", tal.bitar.bit1);
    printf("%u", tal.bitar.bit0);
    printf("\nFortsätt (J/N): "); tecken = getchar();
  } while (tecken == 'j' || tecken == 'J');
}
