#include <stdio.h>

int main () 
{
  float svarighet;
  float sum = 0;
  float minPoang=10;
  float maxPoang=0;
  float hoppPoang;
  unsigned int nr = 1;

  printf("Hoppets svårighetsgrad? ");
  scanf("%f", &svarighet); 
  for (nr=1; nr <= 7; nr++) { 
    float domarPoang;  
    printf("Poäng av domare nr %u ? ", nr);
    scanf("%f", &domarPoang); 
    sum = sum + domarPoang;
    if (domarPoang > maxPoang) {
      maxPoang = domarPoang;
    }
    if (domarPoang < minPoang) {
      minPoang = domarPoang;
    }
  }
  sum = sum - maxPoang - minPoang; 
  hoppPoang = sum / 5 * 3 * svarighet;
  printf("Hoppets poäng: %f\n", hoppPoang);
}
