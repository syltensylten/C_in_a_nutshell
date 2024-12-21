/* 10_3.c */


#include <stdio.h>


int main()
{
    int eof = EOF;
    char ceof = EOF; /* kan bli fel (positivt tal) om char unsigned i detta system */
    printf("int  EOF = %d\n", eof);
    printf("char EOF = %d\n", ceof);
}
