/*Ejercicio 13: 
Realizar un programa que genere al azar una lista de N números naturales aleatorios, en 
el rango [A, B] (con A y B naturales) y muestre aquellos números aleatorios que cumplan con no ser 
deficientes. 
Nota: reutilizar la función generada en el ejercicio 11.*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int nrandom(int, int);
int suma_divisores(int);

int main (void){
    int n,a,b,i,x;
    printf("\ningrese el tamanio de la lista que desea generar: ");
    scanf("%d",&n);
    printf("\ningrese el valor minimo del rango (un numero natural): ");
    scanf("%d",&a);
    printf("\ningrese el valor maximo del rango (un numero natural): ");
    scanf("%d",&b);
    srand(time(NULL));
    for(i=1; i<=n; i++){
        x=nrandom(a,b);
        if(suma_divisores(x)!=x)
            printf("\nnumero aleatorio no deficiente: %d", x);
    }
    return 0;
}


int nrandom(int min, int max){
    int r;
    r=min+rand()%(max-min+1);
    return r;
}

int suma_divisores(int num){
    int r,i;
    r=0;
    for(i=1; i<=num/2; i++){
        if(num%i==0)
            r+=i;
    }
    return r;
}
