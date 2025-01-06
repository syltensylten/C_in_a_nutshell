#include <stdio.h>

int main(){
    float tid1, tid2;
    printf("Tid i forsta aket? \n");
    scanf("%f", &tid1);
    printf("Tid i andra aket? \n");
    scanf("%f", &tid2);
    printf("Total tid: %13.2f\n", tid1 + tid2);
    printf("Genomsnittlig tid: %.2f\n", (tid1 + tid2) / 2);
    return 0;
}