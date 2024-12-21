/* 8_6.c */
#include <stdio.h>
#include "dlist.h"

#define FALSE 0
#define TRUE  1



char  Meny (void)
{
    char tecken, nyrad;
    printf("\n\n%20sMENY\n\n", " ");
    printf("%20s1. Sätt in ett tecken först i listan.\n", " ");
    printf("%20s2. Sätt in ett tecken sist i listan.\n", " ");
    printf("%20s3. Skriv ut första tecknet i listan.\n", " ");
    printf("%20s4. Skriv ut sista tecknet i listan.\n", " ");
    printf("%20s5. Skriv ut listan framlänges.\n", " ");
    printf("%20s6. Skriv ut listan baklänges.\n", " ");
    printf("%20s7. Ta bort första tecknet i listan.\n", " ");
    printf("%20s8. Ta bort sista tecknet i listan.\n", " ");
    printf("%20s9. Ta bort hela listan.\n", " ");
    printf("%20s0. Sluta.\n", " ");
    printf("\n%20sAnge alternativ: ", " ");
    scanf("%c%c", &tecken, &nyrad);
    return(tecken);
}


void  SattInForst (ListType  *lista)
{
    char      tecken, nyrad;
    NodeType  nod;
    
    
    printf("Ange ett tecken: "); scanf("%c%c", &tecken, &nyrad);
    nod = NewNode(tecken);
    InsertFirst(nod, *lista);
}


void  SattInSist (ListType  *lista)
{
    char      tecken, nyrad;
    NodeType  nod;
    
    
    printf("Ange ett tecken: "); scanf("%c%c", &tecken, &nyrad);;
    nod = NewNode(tecken);
    InsertLast(nod, *lista);
}


void  SkrivUtForsta (ListType  lista)
{
    
    printf("Första tecken i listan: %c.\n",Element(FirstNode(lista)));
    
}


void  SkrivUtSista (ListType  lista)
{
    
    
    printf("Sista tecken i listan: %c.\n", Element(LastNode(lista)));
    
}


void  SkrivUtFramlanges (ListType  lista)
{
    NodeType  nod;
    
    
    printf("Listan framlänges är:");
    if (! IsEmptyList(lista)) {
        nod = FirstNode(lista);
        printf(" %c", Element(nod));
        while (! IsLastNode(nod)) {
            nod = NodeAfter(nod);
            printf(" %c", Element(nod));
        }
        printf(".");
    }
    printf("\n");
    
}


void  SkrivUtBaklanges (ListType  lista)
{
    NodeType  nod;
    
    
    printf("Listan framlänges är:");
    if (! IsEmptyList(lista)) {
        nod = LastNode(lista);
        printf(" %c", Element(nod));
        while (! IsFirstNode(nod)) {
            nod = NodeBefore(nod);
            printf(" %c", Element(nod));
        }
        printf(".");
    }
    printf("\n");
    
}

void  TabortForsta (ListType  *lista)
{
    RemoveNode(FirstNode(*lista), *lista);
}


void  TabortSista (ListType  *lista)
{
    RemoveNode(LastNode(*lista), *lista);
}


void  TabortAllt (ListType  *lista)
{
    while (! IsEmptyList(*lista))
        RemoveNode(FirstNode(*lista), *lista);
}


int main()
{
    ListType  lista;
    int       sluta;
    
    lista = NewList();
    sluta = FALSE;
    do {
        switch (Meny()) {
            case '1': SattInForst(&lista);
                break;
            case '2': SattInSist(&lista);
                break;
            case '3': SkrivUtForsta(lista);
                break;
            case '4': SkrivUtSista(lista);
                break;
            case '5': SkrivUtFramlanges(lista);
                break;
            case '6': SkrivUtBaklanges(lista);
                break;
            case '7': TabortForsta(&lista);
                break;
            case '8': TabortSista(&lista);
                break;
            case '9': TabortAllt(&lista);
                break;
            case '0': sluta = TRUE;
                break;
            default : printf("Felaktigt alternativ!\n");
                break;
            case '\n':
            case ' ':    ;
        }
    } while (! sluta);
    printf("Programkörningen avslutad.\n");
}
