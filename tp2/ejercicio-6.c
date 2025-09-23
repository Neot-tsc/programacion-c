#include <stdio.h>

int defproducto(int, int);

int main(void){
    int a,b;
    printf("\ningrese un numero natural: ");
    scanf("%d", &a);
    printf("\ningrese otro numero natural: ");
    scanf("%d", &b);
    printf("\n el producto de %d y %d es: %d", a,b,defproducto(a,b));
    return 0;
}

int defproducto(int a, int b){
    int i,r;
    r=a;
    for ( i = 1; i < b; i++)
        r=r+a;
    return r;
}