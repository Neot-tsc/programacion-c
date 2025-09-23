/*Ejercicio 12:
Dado un número natural N, generar al azar N números naturales X, de a lo sumo 6 cifras y 
determinar, para cada número X, si es capicúa, en caso de no serlo, generar un nuevo valor Y, que será 
igual al producto de todos los dígitos de X.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 999999
#define min 1


int det_capicua(int);
int producto_dig(int);


int main (void){
    int n,i,x,y,b;
    printf("\ningrese un numero natural: ");
    scanf("%d",&n);
    srand(time(NULL));
    for (i=1; i<=n; i++){
        x=min+rand()%(max-min+1);
        b=det_capicua(x);
        if(b==1)
            printf("\nel numero %d es capicua",x);
            else{
                y=producto_dig(x);
                printf("\nel numero %d no es capicua, el producto de sus digitos es: %d",x,y);
            }
    }

    return 0;
}

int det_capicua(int num){
    int r,invertido, aux, dig;
    invertido=0;
    aux=num;
    while(aux!=0){
        dig=aux%10;
        invertido=invertido*10+dig;
        aux=aux/10;
    }
    if(invertido==num)
        r=1;
        else    
            r=0;

    return r;
}

int producto_dig(int n){
    int r,dig;
    r=1;
    while(n!=0){
        dig=n%10;
        r=r*dig;
        n=n/10;
    }
    return r;
}
