/* 7_4.c */

/* Utnyttjar tidmätning (behandlas i lärobokens kapitel 10).
 * Om C-systemet saknar tidmätningsrutiner kan tiden tas för hand
 * (ersätt de aktuella satserna med satser som gör det möjligt att 
 * starta looparna med en tangentnedtryckning och utskriftssatser
 * som meddelar när resp loop är klar).
 */
#include <stdio.h>    /* printf()                                 */
#include <stdlib.h>   /* rand(), srand()                          */
#include <time.h>     /* clock(), CLOCKS_PER_SEC, clock_t, time() */
#include <limits.h>   /* INT_MAX                                  */

#define  MAX 20

/* Prototyper */
void InitMatrix(int m[][MAX][MAX]);
int  FindMinIdx(int m[][MAX][MAX]);
int  FindMinPek(int m[][MAX][MAX]);

int  matrix[MAX][MAX][MAX]; /* "global" variabel */

#define  MAXLOOP 10000

int main()
{
  int         minElem, i;
  clock_t     startTime;
  double      totalTime;
  extern int  matrix[][MAX][MAX];

  InitMatrix(matrix);
  printf("MINSTA HELTAL I TREDIMENSIONELL MATRIS\n\n");
  printf("Sökningen upprepas %d ggr för tidmätning.\n", MAXLOOP);

  printf("Sökning med indexering: ");
  startTime = clock();    
  for (i = 0; i < MAXLOOP; i++)
    minElem = FindMinIdx(matrix);
  totalTime = (clock() - startTime)/(double)CLOCKS_PER_SEC;
  printf("Min = %d    Tid = %.2f sek\n", minElem, totalTime);

  printf("Sökning med pekarstegning: ");
  startTime = clock();
  for (i = 0; i < MAXLOOP; i++)
    minElem = FindMinPek(matrix);
  totalTime = (clock() - startTime)/(double)CLOCKS_PER_SEC;
  printf("Min = %d    Tid = %.2f sek\n", minElem, totalTime);
}


void  InitMatrix(int m[][MAX][MAX])
{
  unsigned  i, j, k;

  srand((unsigned) time(NULL));  /* Slumptalsfrö från systemklocka */
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      for (k = 0; k < MAX; k++) m[i][j][k] = rand();
}


int  FindMinIdx(int m[][MAX][MAX])
{
  unsigned  i, j, k;
  int       min = INT_MAX;

  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      for (k = 0; k < MAX; k++)
        if (m[i][j][k] < min) min = m[i][j][k];
  return min;
}


int  FindMinPek(int m[][MAX][MAX])
{
  int  *p1;
  int  min = INT_MAX;

  for (p1 = &m[0][0][0]; p1 <= &m[MAX-1][MAX-1][MAX-1]; p1++)
    if (*p1 < min) min = *p1;
  return min;
}
