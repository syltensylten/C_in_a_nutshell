/* 10_4.c */

/* Varulagret lagras internt i ett binärt träd */

/* Programmet använder makrokonstanterna SEEK_SET och SEEK_END som
 * ska finnas enligt ANSI-C. Om ditt C-system saknar dessa, kan de
 * ersättas med heltalen 0 resp 2.
 */

#include <stdio.h>
#include <stdlib.h>     /* malloc(), free() */
#include <string.h>     /* strncmp */

#define FILNAMN "VARU.DAT"

struct fpost  {
    long          varunr;
    int           antal;
};

struct vpost  {
    struct fpost  post;
    struct vpost  *v, *h;
};

struct vpost  *rot;


struct vpost  *hittapost (long  vnr)
{
    struct vpost         *vp;
    extern struct vpost  *rot;
    
    vp = rot;
    while (vp != NULL && vp->post.varunr != vnr)
        if (vnr < vp->post.varunr)
            vp = vp->v;
        else
            vp = vp->h;
    return(vp);
}


int  uppdatera (long  vnr, int  ant)
{
    struct vpost  *vp;
    
    vp = hittapost(vnr);
    if (vp == NULL)
        printf("Varunummer %ld existerar ej\n", vnr);
    else {
        vp->post.antal += ant;
        if (vp->post.antal < 0) {
            printf("Det finns bara %d st att ta\n", vp->post.antal - ant);
            vp->post.antal = 0;
        }
        printf("Nu finns %d stycken\n", vp->post.antal);
    }
    return 0;
}


int  finns (long  vnr)
{
    struct vpost  *vp;
    
    if ((vp = hittapost(vnr)) == NULL)
        printf("Varunummer %ld finns ej\n", vnr);
    else
        printf("Det finns %d stycken\n", vp->post.antal);
    return 0;
}


struct vpost  *skapavpost (void)
{
    struct vpost  *vp;
    
    vp = (struct vpost *) malloc(sizeof(struct vpost));
    if (vp == NULL) {     /* Även: if (! vp) { */
        fprintf(stderr, "Minnet slut\n");
        exit(99);
    }
    else
        return(vp);
}


void  ini_traed (struct vpost  **rotref, struct vpost  *vp)
{
    if (*rotref == NULL)
        *rotref = vp;
    else if (vp->post.varunr < (*rotref)->post.varunr)
        ini_traed(&(*rotref)->v, vp);
    else
        ini_traed(&(*rotref)->h, vp);
}


void  byggTrad (FILE  **varufil, long  min, long  max)
{
    long                 mitten;
    struct fpost         varupost;
    struct vpost         *vp;
    extern struct vpost  *rot;
    
    if (min <= max) {
        mitten = (min + max) / 2;
        fseek(*varufil, mitten * sizeof(struct fpost), SEEK_SET);
        fread(&varupost, sizeof(struct fpost), 1, *varufil);
        vp = skapavpost();
        vp->post = varupost;
        vp->v = NULL;
        vp->h = NULL;
        ini_traed(&rot, vp);
        if (min < mitten)
            byggTrad(varufil, min, mitten - 1);
        if (max >= mitten)
            byggTrad(varufil, mitten + 1, max);
    }
}


void  lasVarulager (FILE  **varufil)
{
    long  max;
    
    if ((*varufil = fopen(FILNAMN, "rb")) != NULL) {
        fseek(*varufil, 0L, SEEK_END);
        max = ftell(*varufil) / sizeof(struct fpost) - 1;
        if (max >= 0L)
            byggTrad(varufil, 0L, max);
        fclose(*varufil);
    }
}


int  nyvara (long  vnr)
{
    struct vpost         *ny;
    extern struct vpost  *rot;
    
    if (hittapost(vnr) == NULL) {
        ny = skapavpost();
        ny->post.varunr = vnr;
        ny->post.antal = 0;
        ny->v = NULL;
        ny->h = NULL;
        ini_traed(&rot, ny);
    }
    else
        printf("Varunummer %ld finns redan\n", vnr);
    return 0;
}


/* Ta bort en post med givet varunummer, iterativ variant */

int  tabort (long  vnr)
{
    struct vpost        *foregaende, *aktuell, *ersatt, *foralder, *s;
    int                 hittat = 0;
    extern struct vpost *rot;
    
    foregaende = NULL;
    aktuell    = rot;
    while (aktuell != NULL && ! hittat)
        if (vnr == aktuell->post.varunr)
            hittat = 1;
        else {
            foregaende = aktuell;
            if (vnr < aktuell->post.varunr)
                aktuell = aktuell->v;
            else
                aktuell = aktuell->h;
        }
    if (hittat) {
        if (aktuell->v == NULL)
            ersatt = aktuell->h;
        else
            if (aktuell->h == NULL)
                ersatt = aktuell->v;
            else {
                foralder = aktuell;
                ersatt = aktuell->h;
                s = ersatt->v;
                while (s != NULL) {
                    foralder = ersatt;
                    ersatt = s;
                    s = ersatt->v;
                }
                if (foralder != aktuell) {
                    foralder->v = ersatt->h;
                    ersatt->h = aktuell->h;
                }
                ersatt->v = aktuell->v;
            }
        if (foregaende == NULL)
            rot = ersatt;
        else
            if (aktuell == foregaende->v)
                foregaende->v = ersatt;
            else
                foregaende->h = ersatt;
        free(aktuell);
    }
    else
        printf("Varunummer %ld finns ej\n", vnr);
    return 0;
}


void  inordning (struct vpost  *rot)
{
    if (rot != NULL) {    /* Kortare: if (rot) { */
        inordning(rot->v);
        printf("%10ld: %8d\n", rot->post.varunr, rot->post.antal);
        inordning(rot->h);
    }
}


int  skrivallt (void)
{
    extern struct vpost  *rot;
    
    printf("Varunummer     Antal\n");
    inordning(rot);
    return 0;
    
}


int  sluta (void)
{
    printf("Tack för denna gång\n");
    return 1;
    
}


void  skrivTrad (FILE  **varufil, struct vpost  *rot)
{
    if (rot != NULL) {    /* Även: if (rot) {  */
        skrivTrad(varufil, rot->v);
        fwrite(&rot->post, sizeof(struct fpost), 1, *varufil);
        skrivTrad(varufil, rot->h);
    }
}


void  skrivVarulager (FILE  **varufil)
{
    extern struct vpost  *rot;
    
    *varufil = fopen(FILNAMN, "wb");
    skrivTrad(varufil, rot);
    fclose(*varufil);
}


/* Tabell med kommandon, motsvarande funktion och parameterantal */

struct komtyp  {
    char  *kstr;
    int   (*funk)();
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
    long                 arg1;
    int                  arg2, sluta = 0;
    char                 inkomm[100];
    struct komtyp        *kp;
    extern struct vpost  *rot;
    FILE                 *varufil;
    
    rot = NULL;
    lasVarulager(&varufil);
    do {
        printf("\n\nKommando:"); scanf("%s", inkomm);
        if ((kp = hittakom(inkomm)) == NULL)
            printf("Felaktigt kommando");
        else
            switch (kp->nparam) {
                case 0: sluta = (*kp->funk)();
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
    } while (! sluta);
    skrivVarulager(&varufil);
}
