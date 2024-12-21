/* 7_9.c */

#include <stdio.h>      /* printf() */
#include <stdlib.h>     /* qsort() rand() */
#include <time.h>


#define SIZE 30

void fyll(int array[])
{
    srand((unsigned int)time(0));
    for(int i=0; i<SIZE; i++)
    {
        array[i] = rand() % 100;
    }
    
}

void visa(int array[])
{
    
    for(int i=0; i<SIZE; i++)
    {
        printf("%3d ", array[i]);
        if (i % 10 == 9) printf("\n");
    }
    
}

int jmfint(void *i1, void *i2)
{
    /* konvertera void-pekarna till int-pekare och returnera
     skillnaden mellan de int:ar som pekas ut */
    return *((int *)i1) - *((int *)i2);
}



int main()  /* Test */
{
    int data[SIZE];
    fyll(data);
    printf("Osorterat:\n");
    visa(data);
    qsort(data, SIZE, sizeof(data[0]), jmfint);
    printf("Sorterat:\n");
    visa(data);
}


