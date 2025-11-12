/*Ejercicio 2:   
Escribir un programa que cree una lista enlazada considerando lo siguiente:    
a) La lista debe ser de números enteros positivos al azar, respetando el criterio de que, si el número 
es par se agrega al principio de la lista y si es impar se agrega al final de la lista.   
b) Recorrer la lista para mostrar los elementos por pantalla.   
c) Mostrar todos los números que superen un valor determinado  */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

int random(void);
tptr retorna_nodo(int);
void muestra_lista_nodos(tptr);
void agregar_pila(tptr *, tptr);
void enqueue(tptr*,tptr*,tptr);
void carga_lista_nodos(tptr*,tptr*);
void liberar(tptr*);



int main(void){
    tptr ini,fin;
    ini=NULL;
    fin=NULL;
    carga_lista_nodos(&ini,&fin);
    muestra_lista_nodos(ini);
    return 0;
}


int random(void){
    int x,y;
    x=1;y=100;
    return x+rand()%(y-x+1);
}

tptr retorna_nodo(int valor){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato = valor;
    aux->sig = NULL;
    return aux;
}

/* PILA: agregar al principio (LIFO) */
void agregar_pila(tptr *cabeza, tptr nuevo)
{
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
}

void muestra_lista_nodos(tptr lista){
    if(lista!=NULL){
        printf("\nelementos de la lista de nodos:\n");
        while(lista!=NULL){
            printf("%d,",lista->dato);
            lista=lista->sig;
        }
        printf("\nlista finalizada.");
    }
    else
        printf("\nlista vacia.");
}

void enqueue(tptr *ini,tptr *fin,tptr nuevo){
    if(nuevo!=NULL){
        if(*ini!=NULL){
            *ini=nuevo;
            *fin=nuevo;
        }
        else{
            (*fin)->sig=nuevo;
            *fin=nuevo;
        }
    }
}

void carga_lista_nodos(tptr *ini,tptr *fin){
    tptr nuevo;
    int dato,n,i,b;
    b=1;
    printf("\ningrese el tamanio  de la lista:");
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        srand(time(NULL));
        dato=random();
        nuevo=retorna_nodo(dato);
        if(b==1){
            enqueue(ini,fin,nuevo);
            b=1;
        }
        else{
            if(dato%2==0){
                agregar_pila(ini,nuevo);
            }
            else
                enqueue(ini,fin,nuevo);
        }
    }
}

void liberar(tptr *ini){
    tptr aux;
    while(*ini!=NULL){
        aux=*ini;
        *ini=(*ini)->sig;
        free(aux);
        aux=NULL;
    }
}