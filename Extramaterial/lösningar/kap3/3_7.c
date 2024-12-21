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
Provk�r programmet! Om det fungerar som de ska betraktas char som signed char i ditt system.
�ndra d� deklarationen av c till unsigned char och testa igen.

Om c betraktas som en unsigned char h�nder f�ljande:
Anv�ndaren markerar end of file => getchar returnerar v�rdet -1
-1 tilldelas till c som kommer att inneh�lla bitm�nstret 11111111
Eftersom c �r unsigned tolkas detta som v�rdet +255.
Detta skall sedan j�mf�ras sedan med makrot EOF som har v�rdet -1
Men -1 �r en int och c en char => v�rdet i c m�ste omvandlas till en int innan j�mf�relsen
En int �r minst 16 bitar. Vi antar 16 bitar.
D� omvandlas v�rdet i c 11111111 till 0000000011111111 eftersom det betraktas som ett positivt v�rde.
Allts� kommer detta v�rde att j�mf�ras med -1 som har m�nstret 1111111111111111.
Dessa v�rden �r alltid olika => programmet hamnar i en o�ndlig loop.
*/

