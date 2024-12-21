#include <stdio.h>

int main () {
   float svarighet;
   printf("Hoppets sv�righetsgrad? ");
   while (scanf("%f", &svarighet) == 1) {
      float sum = 0;
      float minPoang=10;
      float maxPoang=0;
      float hoppPoang;
      unsigned int nr = 1;
    
      for (nr=1; nr <= 7; nr++) { 
        float domarPoang;  
        printf("Po�ng av domare nr %u ? ", nr);
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
      printf("Hoppets po�ng: %f\n", hoppPoang);
      printf("Hoppets sv�righetsgrad? ");
    }
}
