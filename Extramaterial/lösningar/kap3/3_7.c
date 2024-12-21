#include <stdio.h> 
int main()  
{ 
   char c; 
   int antal_tecken = 0; 
   while((c = getchar()) != EOF) {
      antal_tecken++;
   }
}

/*
Provkör programmet! Om det fungerar som de ska betraktas char som signed char i ditt system.
Ändra då deklarationen av c till unsigned char och testa igen.

Om c betraktas som en unsigned char händer följande:
Användaren markerar end of file => getchar returnerar värdet -1
-1 tilldelas till c som kommer att innehålla bitmönstret 11111111
Eftersom c är unsigned tolkas detta som värdet +255.
Detta skall sedan jämföras sedan med makrot EOF som har värdet -1
Men -1 är en int och c en char => värdet i c måste omvandlas till en int innan jämförelsen
En int är minst 16 bitar. Vi antar 16 bitar.
Då omvandlas värdet i c 11111111 till 0000000011111111 eftersom det betraktas som ett positivt värde.
Alltså kommer detta värde att jämföras med -1 som har mönstret 1111111111111111.
Dessa värden är alltid olika => programmet hamnar i en oändlig loop.
*/

