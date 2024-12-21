/* gstack.h */

typedef struct object  *StackType;

typedef struct object  {
                         StackType  next;
                         void       *node;
                       };


void  Create (StackType  *);

void  Push   (void  *, StackType  *, unsigned);

void  Pop    (StackType  *, void  **);

int   Empty  (StackType);
