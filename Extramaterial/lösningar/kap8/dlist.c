/* dlist.c */

#include <stdio.h>
#include <stdlib.h>    /* malloc(), free() */
#include "dlist.h"


ListType  NewList (void)
{
  ListType  hp;

  hp = (ListType) malloc(sizeof(struct listobject));
  hp->first = NULL;
  hp->last  = NULL;
  return(hp);
}


NodeType  NewNode (char  ch)
{
  NodeType  lp;

  lp = (NodeType) malloc(sizeof(struct nodeobject));
  lp->before = NULL;
  lp->after  = NULL;
  lp->data   = ch;
  return(lp);
}


void  InsertFirst (NodeType  node, ListType  list)
{
  if (list->first != NULL) {
    list->first->before = node;
    node->after = list->first;
  }
  else {
    node->after = NULL;
    list->last = node;
  }
  node->before = NULL;
  list->first = node;
}


void  InsertLast (NodeType  node, ListType  list)
{
  if (list->last != NULL) {
    list->last->after = node;
    node->before = list->last;
  }
  else {
    list->first = node;
    node->before = NULL;
  }
  node->after = NULL;
  list->last = node;
}
NodeType  FirstNode (ListType  list)
{
  return(list->first);
}


NodeType  LastNode (ListType  list)
{
  return(list->last);
}


NodeType  NodeBefore (NodeType  node)
{
  return(node->before);
}


NodeType  NodeAfter (NodeType  node)
{
  return(node->after);
}


int  IsEmptyList (ListType  list)
{
  return(list->first == NULL);
}


int  IsFirstNode (NodeType  node)
{
  return(node->before == NULL);
}


int  IsLastNode (NodeType  node)
{
  return(node->after == NULL);
}


char  Element (NodeType  node)
{
  return(node->data);
}


void  RemoveNode (NodeType  node, ListType  list)
{
  if (node == list->first)
    list->first = node->after;
  if (node == list->last)
    list->last = node->before;
  if (node->before != NULL)
    node->before->after = node->after;
  if (node->after != NULL)
    node->after->before = node->before;
  free(node);
}
