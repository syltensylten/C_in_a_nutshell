/* stack.h */

typedef struct object  *StackType;

typedef struct object  {
                         StackType  next;
                         char       ch;
                       };


void  Create (StackType  *);
  /* Skapar en ny, tom stack */

void  Push   (char, StackType  *);
  /* L�gger ett tecken �verst p� stacken */

void  Pop    (StackType  *, char  *);
  /* Tar bort och skickar tillbaka �versta tecknet p� stacken */

int   Empty  (StackType);
  /* Testar om stacken �r tom */

