/* 8_5.c */

#include <stdio.h>
#include <stdlib.h>    /* malloc(), free() */
#include <string.h>    /* strncmp() */


struct vpost {
               long          varunr;
               int           antal;
               struct vpost  *lnk;
             };


#define NHASH 5
static struct vpost  *vhash[NHASH];


int  hashfunk (long  vnr)
{
  return(vnr % NHASH);
}


struct vpost  *hittapost (long  vnr)
{
  struct vpost  *vp;

  vp = vhash[hashfunk(vnr)];
  while (vp != NULL && vp->varunr != vnr)
    vp = vp->lnk;
  return(vp);
}


void  uppdatera (long  vnr, int  ant)
{
  struct vpost  *vp;

  vp = hittapost(vnr);
  if (vp == NULL)
    printf("Varunummer %ld existerar ej\n", vnr);
  else {
    vp->antal += ant;
    if (vp->antal < 0) {
      printf("Det finns endast %d st att ta\n", vp->antal - ant);
      vp->antal = 0;
    }
    printf("Nu finns %d stycken\n", vp->antal);
  }
}


void  finns (long  vnr)
{
  struct vpost  *vp;

  if ((vp = hittapost(vnr)) == NULL)
    printf("Varunummer %ld finns ej\n", vnr);
  else
    printf("Det finns %d stycken\n", vp->antal);
}


void  skrivallt (void)
{
  int           i;
  struct vpost  *vp;

  printf("Varunummer     Antal\n");
  for (i = 0; i < NHASH; i++)
    for (vp = vhash[i]; vp != NULL; vp = vp->lnk)
      printf("%10ld: %8d\n", vp->varunr, vp->antal);
}


struct vpost  *skapavpost (void)
{
  struct vpost  *vp;

  vp = (struct vpost *) malloc(sizeof(struct vpost));
  if (vp == NULL) {    /* Även if (!vp) { */
    fprintf(stderr, "Minnet slut\n");
    exit(99);
  }
  else
    return(vp);
}


void  nyvara (long vnr)
{
  struct vpost  *ny;

  if (hittapost(vnr) == NULL) {
    ny = skapavpost();
    ny->varunr = vnr;
    ny->antal = 0;
    ny->lnk = vhash[hashfunk(vnr)];
    vhash[hashfunk(vnr)] = ny;
  }
  else
    printf("Varunummer %ld finns redan\n", vnr);
}


/* Ta bort en post med givet varunummer */

void  tabort (long  vnr)
{
  struct vpost  *vp, *sp, *hp;

  if ((vp = hittapost(vnr)) != NULL) {
    sp = vhash[hashfunk(vnr)];
    if (sp == vp)
      vhash[hashfunk(vnr)] = vp->lnk;
    else {
      hp = sp;
      while (hp->lnk != vp)
        hp = hp->lnk;
      hp->lnk = vp->lnk;
    }
    free(vp);
  }
  else
    printf("Varunummer %ld finns inte\n", vnr);
}


void  sluta (void)
{
  printf("Tack för denna gång\n");
  exit(0);
}


/* Tabell med kommandon, motsvarande funktion och parameterantal */

struct komtyp  {
                 char  *kstr;
                 void  (*funk)();
                 int   nparam;
               } kom[] = {
                           { "uppd",   uppdatera, 2 },
                           { "finns",  finns,     1 },
                           { "invent", skrivallt, 0 },
                           { "ny",     nyvara,    1 },
                           { "tabort", tabort,    1 },
                           { "sluta",  sluta,     0 }
                         };


struct komtyp  *hittakom (char  *str)
{
  struct komtyp  *kp;

  for (kp = kom; kp < kom + (sizeof(kom) / sizeof(kom[0])); kp++)
    if (strncmp(kp->kstr, str, 2) == 0)
      return(kp);
  return(NULL);
}

int main()
{
  long           arg1;
  int            i, arg2;
  char           inkomm[100];
  struct komtyp  *kp;

  for (i = 0; i < NHASH; i++)
    vhash[i] = NULL;
  while (1) {
    printf("\n\nKommando:"); scanf("%s", inkomm);
    if ((kp = hittakom(inkomm)) == NULL)
      printf("Felaktigt kommando");
    else
      switch (kp->nparam) {
        case 0: (*kp->funk)();
                break;
        case 1: if (scanf("%ld", &arg1) != 1)
                  printf("Felaktig parameter");
                else
                  (*kp->funk)(arg1);
                break;
        case 2: if (scanf("%ld%d", &arg1, &arg2) != 2)
                  printf("Felaktig parameter");
                else
                  (*kp->funk)(arg1, arg2);
                break;
      }
  }
}
