/* slump.c */
/* Kropp till modulen slump */

#include "slump.h"		/* OBS */

static unsigned long next = 1;

int rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned) (next/65536) % 32768;
}

void srand(unsigned seed)
{
  next = seed;
}


int krona_klave(void)
{
  return rand() % 2;
}

