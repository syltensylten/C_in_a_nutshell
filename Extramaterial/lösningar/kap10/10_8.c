/* 10_8.c */  /* VARNING! Programmet går inte att avbryta! */

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

jmp_buf  jumper;

void  Avbrottsrutin (int  signalnumber)
{
    extern jmp_buf  jumper;
    
    printf("signalnumber = %d. Du tryckte <Ctrl><C>\n", signalnumber);
    longjmp(jumper, 1);
}


int main()
{
    int             value;
    extern jmp_buf  jumper;
    
    value = setjmp(jumper);
    signal(SIGINT, Avbrottsrutin);
    for(;;)
        printf("setjmp returnerar %d. Avbryt med <Ctrl><C>\n", value);
}
