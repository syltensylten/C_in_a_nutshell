/* 6_9.c */

#include <stdio.h>
#include "queue.h"

/* Test */
main()
{
  char  tecken, nyrad;

  printf("KÖTEST\n");
  do {
    if (empty()) {
      printf("Kön är tom!");
    }
    printf("1) Insätt   2) Ta bort   3) Töm   0) Sluta");
    printf("Ange alternativ: "); scanf("%c%c", &tecken, &nyrad);
    switch (tecken) {
      case '1' : printf("Ange tecken: ");
                 scanf("%c%c", &tecken, &nyrad);
                 insert_back(tecken);
                 break;
      case '2' : if (! empty())
                   printf("%c är borttagen!\n", remove_front());
                 break;
      case '3' : if (! empty()) {
                   printf("Kön = ");
                   while (! empty())
                     putchar(remove_front());
                   putchar('\n');
                 }
                 break;
      case '0' : break;
      default  : puts("Felaktigt alternativ!");
    }
  } while (tecken != '0');
}

