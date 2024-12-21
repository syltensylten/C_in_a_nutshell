/* 8_2.c */

#include <stdio.h>


struct person  {
                 char           namn[100];
                 int            alder;
                 struct person  *fader, *mor, *yngre_syskon;
               };


struct person  p1 = {"Johan Bengtsson", 45, NULL, NULL, NULL},
               p2 = {"Karin Bengtsson", 38, NULL, NULL, NULL},
               p3 = {"Pelle Bengtsson", 15,  &p1,  &p2, NULL},
               p4 = {"Maria Bengtsson", 17,  &p1,  &p2,  &p3};


void  slakttrad (struct person  *p)
{
  if (p != NULL) {
    printf("%s\n", p->namn);
    printf("%s's far heter: ", p->namn);
    slakttrad(p->fader);
    printf("%s's mor heter: ", p->namn);
    slakttrad(p->mor);
  }
  else
    printf("Uppgift saknas!\n");
}


int main()
{
  

  printf("Släktträd för: ");
  slakttrad(&p4);
}
