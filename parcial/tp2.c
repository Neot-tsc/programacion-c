/*Ejercicio 13: 
Realizar un programa que genere al azar una lista de N números naturales aleatorios, en 
el rango [A, B] (con A y B naturales) y muestre aquellos números aleatorios que cumplan con no ser 
deficientes. 
Nota: reutilizar la función generada en el ejercicio 11.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

typedef int Tlista[max];

void genera_lista(Tlista, int*);
int nrandom(int,int);
int suma_divisores(int);
int es_deficiente(int);
void mostrar_uno(Tlista, int);
void mostrar_todo(Tlista, int);


int main(){
    Tlista l;
    int n,i;

    genera_lista(l,&n);
    printf("\nlos numeros aleatorios que no son deficientes son:"); 
    for(i=1; i<=n; i++){
        if(es_deficiente(l[i])==0)
            mostrar_uno(l,i);
    }
    mostrar_todo(l,n);
    return 0;
}


void genera_lista(Tlista l, int *n){
    int a,b,i;
    printf("\ningrese el tamanio de la lista que desea generar:");
    scanf("%d",n);
    printf("\nigrese el inicio del rango (un numero entero):");
    scanf("%d",&a);
    printf("\nigrese el fin del rango (un numero entero):");
    scanf("%d",&b);
    srand(time(NULL));
    for(i=1; i<=*n; i++){
        l[i]=nrandom(a,b);
    }
}
int nrandom(int a,int b){
    int r;
    r=a+rand()%(b-a+1);
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
int es_deficiente(int num){
    int r;
    if(suma_divisores(num)==num)
        r=1;
    else
        r=0;
    return r;
}
void mostrar_uno(Tlista l, int i){
    printf("\n%d",l[i]);
}
void mostrar_todo(Tlista l, int n){
    int i;
    for(i=1; i<=n;i++){
        printf("%d-",l[i]);
    }
}