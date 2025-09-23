#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int nrandom(int, int);


int main(void){
    int a,b,n,k,i,x;
    i=0;
    printf("\ningrese un numero naturale: ");
    scanf("%d", &a);
    printf("\ningrese otro numero natural: ");
    scanf("%d", &b);
    printf("\ningrese el ultimo numero natural: ");
    scanf("%d", &n);
    k=b-a;
    printf("k es %d, resultado de b-a",k);
    while (i<=n)
    {
        x=nrandom(a,b);
        if(k%x==0){
            printf("\n %d es divisor de %d", x,k);
            i++;
        }
    }
    return 0;
}

int nrandom(int a, int b){
    int num;
    srand(time(NULL));
    num=a+rand()%(b-a+1);
    return num;
}