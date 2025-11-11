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
void agregar_lista_nodos(tptr*);
void agregar_pila(tptr*,tptr);
void agregar_cola(tptr*,tptr*,tptr);
void mostrar_un_nodo(tnodo);
void mostrar_lista_nodos(tptr);


int main(void){
    tptr lista;
    lista=NULL;
    agregar_lista_nodos(&lista);
    mostrar_lista_nodos(lista);

    return 0;
}


int random(void){
    return rand();
}

tptr retorna_nodo(int valor){
    tptr aux;
    aux = (tptr)malloc(sizeof(tnodo));
    if (aux == NULL)
    {
        printf("Error: no se pudo asignar memoria\n");
    }
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

void agregar_cola(tptr *inicio, tptr *fin, tptr nuevo){
    if (*inicio == NULL)
    {
        /* Cola vacia: el nuevo nodo es el inicio y el fin */
        *inicio = nuevo;
        *fin = nuevo;
    }
    else
    {
        /* Agregar al final */
        (*fin)->sig = nuevo;
        *fin = nuevo;
    }
}

void carga_lista_nodos(tptr *lista){
    tptr nuevo;
    tptr ini,fin;
    int r,b,n,i;
    b=0;
    printf("\ningrese el tamanio de la lista:");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        srand(time(NULL));
        r=random();
        if(b==0){
            nuevo=retorna_nodo(r);
            agregar_pila(lista,nuevo);
            b=1;
            ini=*lista;
            fin=*lista;
        }
        else{
            if((r%2)==0){
                nuevo=retorna_nodo(r);
                agregar_pila(lista,nuevo);
                ini=*lista;
            }
            else{
                nuevo=retorna_nodo(r);
                agregar_cola(&ini,&fin,nuevo);
            }
        }
    }
    
}
void mostrar_un_nodo(tnodo);
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
