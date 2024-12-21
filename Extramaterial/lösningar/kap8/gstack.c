/* gstack.c */

#include <stdlib.h>
#include "gstack.h"


void  Create (StackType  *stack)
{
  *stack = NULL;
}


void  Push (void  *node, StackType  *stack, unsigned  size)
{
  StackType  sp;

  sp = (StackType) malloc(size);
  sp->next = *stack;
  sp->node = node;
  *stack = sp;
}


void  Pop (StackType  *stack, void  **node)
{
  StackType  sp;

  *node = (*stack)->node;
  sp = *stack;
  *stack = (*stack)->next;
  free(sp);
}


int  Empty (StackType  stack)
{
  return(stack == NULL);
}
