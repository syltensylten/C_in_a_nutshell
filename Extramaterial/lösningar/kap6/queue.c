/* queue.c */

#include "queue.h"		/* OBS */

#define MAX 100

static char  queue[MAX];
static int   front = 0;
static int   rear  = 0;
static int   len   = 0;


void insert_back(char c)
{                             /* Alternativt: */
  queue[rear] = c;            /* queue[rear++] = c; */
  rear = (rear + 1) % MAX;    /* rear %= MAX; */
  ++len;
}


char remove_front(void)
{
  char  c;
                              /* Alternativt: */
  c = queue[front];           /* c = queue[front++]; */
  front = (front + 1) % MAX;  /* front %= MAX; */
  --len;
  return c;
}


int  empty(void)
{
  return (len == 0);
}

