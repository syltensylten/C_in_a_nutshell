/* 8_7.c */

#include <stdio.h>
#include <stdlib.h>   /* malloc(), free() */
#include <string.h>
#include "gstack.h"

#define FALSE 0
#define TRUE  1

struct vpost  {
    long          varunr;
    int           antal;
    struct vpost  *v, *h;
};

struct vpost  *rot;


struct vpost  *hittapost (long  vnr)
{
    struct vpost         *vp;
    extern struct vpost  *rot;
    
    vp = rot;
    while (vp != NULL && vp->varunr != vnr)
        if (vnr < vp->varunr)
            vp = vp->v;
        else
            vp = vp->h;
    return vp;
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


struct vpost  *skapavpost (void)
{
    struct vpost  *vp;
    
    vp = (struct vpost *) malloc(sizeof(struct vpost));
    if (vp == NULL) {     /* Kortare: if (! vp) { */
        fprintf(stderr, "Minnet slut\n");
        exit(99);
    }
    else
        return vp;
}


void  ini_traed (struct vpost  **rotref, struct vpost  *vp)
{
    if (*rotref == NULL)     /* Även: if (!(*rotref)) */
        *rotref = vp;
    else if (vp->varunr < (*rotref)->varunr)
        ini_traed(&(*rotref)->v, vp);
    else
        ini_traed(&(*rotref)->h, vp);
}


void  nyvara (long  vnr)
{
    struct vpost         *ny;
    extern struct vpost  *rot;
    
    if (hittapost(vnr) == NULL) {
        ny = skapavpost();
        ny->varunr = vnr;
        ny->antal = 0;
        ny->v = NULL;
        ny->h = NULL;
        ini_traed(&rot, ny);
    }
    else
        printf("Varunummer %ld finns redan\n", vnr);
}


/* Ta bort en post med givet varunummer */
/* Följande tre funktioner utgör rekursiv "standardlösning av borttag "
 */

struct vpost  *minpek (struct vpost  **rot)
{
    struct vpost  *tp;
    
    if ((*rot)->v == NULL) {
        tp = *rot;
        *rot = (*rot)->h;
        return tp;
    }
    else
        return (minpek(&(*rot)->v));
}


void bort (long  vnr, struct vpost  **rot)
{
    struct vpost  *tp;
    
    if (*rot != NULL) {
        if (vnr < (*rot)->varunr)
            bort(vnr, &(*rot)->v);
        else if (vnr > (*rot)->varunr)
            bort(vnr, &(*rot)->h);
        else {
            tp = *rot;
            if ((*rot)->v == NULL && (*rot)->h == NULL)
                *rot = NULL;
            else if ((*rot)->v == NULL)
                *rot = (*rot)->h;
            else if ((*rot)->h == NULL)
                *rot = (*rot)->v;
            else {
                tp = minpek(&(*rot)->h);
                (*rot)->varunr = tp->varunr;
                (*rot)->antal = tp->antal;
            }
            free(tp);
        }
    }
}

void  tabort (long  vnr)
{
    extern struct vpost  *rot;
    
    bort(vnr, &rot);
}


/* Iterativ inorderutskrift av träd. Utnyttjar generisk stack. */

void inordning (struct vpost  *rot)
{
    StackType  stack;
    
    Create(&stack);
    do {
        if (rot != NULL) {
            Push(rot, &stack, sizeof(struct vpost));
            rot = rot->v;
        }
        else
            if (! Empty(stack)) {
                Pop(&stack, (void  **) &rot);
                printf("%10ld: %8d\n", rot->varunr, rot->antal);
                rot = rot->h;
            }
    } while (! Empty(stack) || rot != NULL);
}


void  skrivallt (void)
{
    extern struct vpost  *rot;
    
    printf("Varunummer     Antal\n");
    inordning(rot);
}


void  sluta (void)
{
    printf("Tack för denna gång\n");
    exit(0);
}


/* Tabell med kommandon, motsv funktion och parameterantal */

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
            return kp;
    return NULL;
}


int main()
{
    long                 arg1;
    int                  arg2;
    char                 inkomm[100];
    struct komtyp        *kp;
    extern struct vpost  *rot;
    
    rot = NULL;
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

