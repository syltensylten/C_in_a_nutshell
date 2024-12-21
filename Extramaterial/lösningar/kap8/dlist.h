/* dlist.h */

typedef struct nodeobject  *NodeType;

typedef struct nodeobject  {
                             NodeType  before,
                                       after;
                             char      data;
                           };


typedef struct listobject  *ListType;

typedef struct listobject  {
                             NodeType  first,
                                       last;
                           };


ListType  NewList     (void);
  /* Skapar en ny tom lista */

NodeType  NewNode     (char);
  /* Skapar en ny nod med ett tecken */

void      InsertFirst (NodeType, ListType);
  /* Sätter in en nod först i listan */

void      InsertLast  (NodeType, ListType);
  /* Sätter in en nod sist i listan */

NodeType  FirstNode   (ListType);
  /* Returnerar första noden i listan */

NodeType  LastNode    (ListType);
  /* Returnerar sista noden i listan */

NodeType  NodeBefore  (NodeType);
  /* Returnerar föregående nod */

NodeType  NodeAfter   (NodeType);
  /* Returnerar efterföljande nod */

int       IsEmptyList (ListType);
  /* Testar om listan är tom */

int       IsFirstNode (NodeType);
  /* Testar om det är den första noden */

int       IsLastNode  (NodeType);
  /* Testar om det är den sista noden */

char      Element     (NodeType);
  /* Returnerar tecknet i noden */

void      RemoveNode  (NodeType, ListType);
  /* Tar bort en nod ur listan */
