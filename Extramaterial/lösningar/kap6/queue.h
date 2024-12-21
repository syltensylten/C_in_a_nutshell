/* queue.h */
/* Specifikation av modulen queue */

extern void insert_back(char);
  /* Lägger ett tecken sist i kön */

extern char remove_front(void);
  /* Returnerar och tar bort 1:a tecknet i kön */

extern int empty(void);
  /* Testar om kön är tom */

