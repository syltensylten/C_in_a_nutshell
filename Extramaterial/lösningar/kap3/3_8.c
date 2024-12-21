/* 3_8.c */

#include  <stdio.h> 
#include  <float.h>

enum veckodag {mandag=1, tisdag, onsdag, torsdag,
               fredag, lordag, sondag};

int main()
{
  enum veckodag  dag;
  unsigned int   dagantal = 0;
  float          temp, tempSum = 0, maxTemp = -FLT_MAX;

  printf("Ange temperaturen kl 13.00 (i grader C)\n");
  for (dag = mandag; dag <= sondag; dag++, dagantal++) {
    if (dag==1)      { printf("m�ndag:  "); }
    else if (dag==2) { printf("tisdag:  "); }
    else if (dag==3) { printf("onsdag:  "); }
    else if (dag==4) { printf("torsdag: "); }
    else if (dag==5) { printf("fredag:  "); }
    else if (dag==6) { printf("l�rdag:  "); }
    else if (dag==7) { printf("s�ndag:  "); }
    scanf("%f", &temp);
    if (temp > maxTemp) {
      maxTemp = temp;
    }
    tempSum = tempSum + temp;   /* tempSum += temp; */
  }
  printf("\nVeckans h�gsta temperatur: %.1f grader\n", maxTemp);
  printf("Medeltemperatur: %.1f grader\n", tempSum/dag);
}
