#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* sig;
}tnodo;

typedef tnodo* tlista;

tlista retorna_nodo(int);
void cargar_lista_nodos(tlista*);
void agregar_cabeza(tlista*, tlista);
void muestra_lista_nodos(tlista);


int main(void){
    tlista lista;
    lista=NULL;
    cargar_lista_nodos(&lista);
    muestra_lista_nodos(lista);
    return 0;
}



tlista retorna_nodo(int num){
    tlista aux;
    aux=(tlista)malloc(sizeof(tnodo));
    aux->dato=num;
    aux->sig=NULL;
    return aux;
}

void agregar_cabeza(tlista* cabeza, tlista nuevo){
    nuevo->sig=*cabeza;
    *cabeza=nuevo;
}

void cargar_lista_nodos(tlista* lista){
    tlista nuevo;
    int op, n;
    do
    {
        printf("\ningresar un nuevo nodo (1=si/0=no):");
        scanf("%d",&op);
        if(op!=0){
            printf("\ningrese el dato(un numero natural):");
            scanf("%d", &n);
            nuevo=retorna_nodo(n);
            agregar_cabeza(lista,nuevo);
        }
        else    
            printf("\ncarga finalizada.");
    } while (op!=0);
    
}
void muestra_lista_nodos(tlista lista){
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
