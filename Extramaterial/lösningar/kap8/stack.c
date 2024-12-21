/* stack.c */

#include <stdlib.h>    /* malloc(), free() */
#include "stack.h"


void  Create (StackType  *stack)
{
  *stack = NULL;
}


void  Push (char  ch, StackType  *stack)
{
  StackType  sp;

  sp = (StackType) malloc(sizeof(struct object));
  sp->next = *stack;
  sp->ch = ch;
  *stack = sp;
}


void  Pop (StackType  *stack, char  *ch)
{
  StackType  sp;

  *ch = (*stack)->ch;
  sp = *stack;
  *stack = (*stack)->next;
  free(sp);
}


int  Empty (StackType  stack)
{
  return (stack == NULL);
}

