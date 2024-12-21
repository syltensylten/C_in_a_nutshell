/* 8_3.c */

#include <stdio.h>
#include "stack.h"


int main()
{
  StackType  stack;
  char       tecken;

  Create(&stack);
  while ((tecken = getchar()) != '\n')
    Push(tecken, &stack);
  while (! Empty(stack)) {
    Pop(&stack, &tecken);
    putchar(tecken);
  }
  putchar('\n');
}

