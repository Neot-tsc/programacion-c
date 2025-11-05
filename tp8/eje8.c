/*Ejercicio  8:  Se  pide  crear  un  programa  recursivo  que  permita  generar  
aleatoriamente  una  lista  de  N 
números enteros en el intervalo [A, B], luego presentar un menú de opciones 
(el cual debe ser recursivo) 
que permita realizar las siguientes tareas: mostrar la lista, 
Insertar un nuevo elemento en una posición 
ingresada por teclado, buscar un elemento en la lista. */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 50


typedef int lista[max];

void cargar(lista, int*);
void carga_rec(lista, int,int,int);
int random(int, int);
void mostrar(lista, int);
void mostrar_rec(lista, int);
void agregar(lista, int*);
void agrega_rec(lista, int, int, int);
int bs_rec(lista, int, int);
int opciones(void);
void menu_rec(lista, int*);

int main(void){
    lista a;
    int n,pos;
    cargar(a,&n);
    mostrar(a,n);
    return 0;
}

void cargar(lista a, int *n){
    int ini,fin;
    printf("\ningrese el tamanio de la lista:");
    scanf("%d", n);
    printf("\ningrese el inicio del intervalo:");
    scanf("%d", &ini);
    printf("\ningrese el fin del intervalo:");
    scanf("%d", &fin);
    srand(time(NULL));
    carga_rec(a,*n,ini,fin);
}
void carga_rec(lista a, int n, int ini, int fin){
    if(n>0){
        carga_rec(a,n-1,ini, fin);
        a[n]=random(ini,fin);
    }
}

int random(int ini , int fin){
    int x;
    x=ini+rand()%(fin-ini+1);
    return x;
}

void mostrar(lista a, int n){
    if(n>0){
        printf("\nlos elemetos de la lista\n");
        mostrar_rec(a,n);
    }
    else    
        printf("\nlista vacia");
}
void mostrar_rec(lista a, int n){
    if(n>0){
        mostrar_rec(a,n-1);
        printf("%d,",a[n]);
    }
}

void agregar(lista a, int *n){
    int nuevo, pos;
    
    if(*n < max){
        printf("\ningrese el nuevo elemento: ");
        scanf("%d", &nuevo);
        printf("\ningrese la posicion en la que quiere agregarlo (1-%d): ", *n + 1);
        scanf("%d", &pos);
        if(pos>=1 || pos<=*n + 1){
            agrega_rec(a, *n, nuevo, pos);
            (*n)++;
        }
        else
            printf("\nPosicion invalida");
        
    }
}

void agrega_rec(lista a, int n, int nuevo, int pos){
    if(n > pos){
        a[n+1] = a[n];
        agrega_rec(a, n - 1, nuevo, pos);
    }
    a[pos] = nuevo;
}


int bs_rec(lista a, int n, int bus){
    if(n==0)
        return 0;
    else{
        if(a[n]==bus){
            return n;
        }
        else
            bs_rec(a,n-1,bus);
    }
}
int opciones(void){
    int op;
}
void menu_rec(lista, int*);
