#include <stdio.h>

int main()
{
     char namn[20];
     printf("Vad heter du?\n");
     scanf("%19s", namn);
     printf("Hej %s\n", namn);
}
