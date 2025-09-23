
/*Ejercicio 8: Se necesita un programa en C, que simule el tiempo que esperan dos clientes, A y B, para 
realizar un trámite en el banco. El programa deberá mostrar cuál es el cliente que será atendido primero, 
considerando el menor tiempo de espera. (El tiempo de espera de cada cliente se asigna de forma 
aleatoria, siendo un número natural en el rango [1,30]) 
Nota: Si el rango es ingresado por el usuario, ¿cómo se modificaría la solución original?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tmin 1
#define tmax 30

int nrandom();


int main(void){
    int clienteA, clienteB;
    srand(time(NULL));
    clienteA=nrandom();
    clienteB=nrandom();
    if (clienteA < clienteB)
        printf("el siguiente es el cliente A: %d", clienteA);
    else 
        printf("el siguiente es el cliente B: %d", clienteB);
    return 0;
}

int nrandom(){
    int r;
    r=tmin+rand()%(tmax-tmin+1);;
    return r;
}