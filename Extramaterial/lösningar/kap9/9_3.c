/* 9_3.c */

#include <stdio.h>



int main()
{
    if (__STDC__)
    {
        printf("C-kompilatorn f�ljer ANSI-standarden.\n");
        printf("Version: %d\n", __STDC_VERSION__);
    }
    else
        printf("C-kompilatorn f�ljer inte ANSI-standarden.\n");
    printf("__LINE__ st�r p� rad nr: %d  ", __LINE__);
    printf("i k�llkodsfilen: %s\n", __FILE__);
    printf("Datum = %s\n", __DATE__);
    printf("Klockan = %s\n", __TIME__);
}
