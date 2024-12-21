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
  /* S�tter in en nod f�rst i listan */

void      InsertLast  (NodeType, ListType);
  /* S�tter in en nod sist i listan */

NodeType  FirstNode   (ListType);
  /* Returnerar f�rsta noden i listan */

NodeType  LastNode    (ListType);
  /* Returnerar sista noden i listan */

NodeType  NodeBefore  (NodeType);
  /* Returnerar f�reg�ende nod */

NodeType  NodeAfter   (NodeType);
  /* Returnerar efterf�ljande nod */

int       IsEmptyList (ListType);
  /* Testar om listan �r tom */

int       IsFirstNode (NodeType);
  /* Testar om det �r den f�rsta noden */

int       IsLastNode  (NodeType);
  /* Testar om det �r den sista noden */

char      Element     (NodeType);
  /* Returnerar tecknet i noden */

void      RemoveNode  (NodeType, ListType);
  /* Tar bort en nod ur listan */
