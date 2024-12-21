/* 11_3.c */

/* 
 Prova fšrst programmer med Summa skrivet i C
 sedan Summa skriven i assembler, se Summa.c 
 */

#include <stdio.h>      /* printf(), scanf() */

extern unsigned  Summa(unsigned, unsigned);

int main()
{
    unsigned a, b;
    
    printf("Ange 2 positiva heltal: ");
    scanf("%u%u", &a, &b);
    printf("Summan = %u", Summa(a, b));
}
