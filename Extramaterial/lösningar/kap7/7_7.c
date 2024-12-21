/* 7_7.c */
/* Implementering. OBS minnet hanteras som en stack, dvs
 * avallokering måste göras i omvänd ordning mot allokeringen
 * (i annat fall råkar det hela i olag).
 */

#include "7_7.h"

#define ALLOCSIZE 10000

static unsigned char  allocbuffer[ALLOCSIZE];
static unsigned char  *allocptr = allocbuffer;


void  *calloc(unsigned numElem, unsigned elemSize)
{
  unsigned i, n = elemSize*numElem;

  if (allocbuffer + ALLOCSIZE - allocptr >= n) {
    for (i=0; i < n; i++)
      *allocptr++ = 0;  /* Nollställer minnet: */
    return allocptr - n;
  }
  else   /* Utrymme saknas */
    return 0;
}


void  free(char *block)
{
  if (block >= allocbuffer && block < allocbuffer + ALLOCSIZE)
    allocptr = block;
}

