/* stack.h */

typedef struct object  *StackType;

typedef struct object  {
                         StackType  next;
                         char       ch;
                       };


void  Create (StackType  *);
  /* Skapar en ny, tom stack */

void  Push   (char, StackType  *);
  /* Lägger ett tecken överst på stacken */

void  Pop    (StackType  *, char  *);
  /* Tar bort och skickar tillbaka översta tecknet på stacken */

int   Empty  (StackType);
  /* Testar om stacken är tom */

