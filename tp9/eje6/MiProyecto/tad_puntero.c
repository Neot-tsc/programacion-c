#include "tad_puntero.h"

tptr retorna_nodo(tlibro a){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=a;
    aux->sig=NULL;
    return aux;
}
//a
void carga_lista_nodos(tptr *cab){
    tptr nuevo;
    long int n;
    int r;
    printf("\ningrese el ISBN del nuevo libro:");
    scanf("%ld", &n);
    r=buscar(*cab,n);
    if(r==0){
        nuevo=retorna_nodo(retorna_libro(n));
        agrega_un_nodo_ordenado(cab,nuevo);
        printf("\nlibro agregado con exito.");
    }
    else
        printf("\nel libro ya se encuentra en la lista.");
}

void pila(tptr *cab, tptr nuevo){
    nuevo->sig=*cab;
    *cab=nuevo;
}

void cola(tptr *cab,tptr nuevo){
    tptr aux;
    aux=*cab;
    if(*cab!=NULL){
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
    else
        *cab=nuevo;
}
//c
void agrega_un_nodo_ordenado(tptr *cab,  tptr nuevo){
    tptr aux,ant;
    if(*cab==NULL)
        *cab=nuevo;
    else{
        aux=*cab;
        ant=NULL;
        while(aux!=NULL && get_isbn(nuevo->dato) > get_isbn(aux->dato)){
            ant=aux;
            aux=aux->sig;
        }
        if(ant==NULL)
            pila(cab,nuevo);
        else{
            ant->sig=nuevo;
            nuevo->sig=aux;
        }
    }
}

void mostrar_lista_nodos(tptr cab){
    int i;
    i=1;
    if(cab!=NULL){
        printf("\nlistade libros\n");
        while(cab!=NULL){
            printf("\nlibro nro %d\n", i);
            muestra_libro(cab->dato);
            i++;
            cab=cab->sig;
        }
    }
    else
        printf("\nlista vacia.");
}

void modifica_tipo_nodo(tptr cab){
    long int n;
    int r;
    r=0;
    printf("\ningrese el ISBN del libro a modificar:");
    scanf("%ld", &n);
    if(cab!=NULL){
        while (cab!=NULL && r==0){
            if(get_isbn(cab->dato)==n){
                r=1;
                modifica_tipo_libro(&cab->dato);
            }
            cab=cab->sig;
        }
        if(r==0)
            printf("\nlibro no encontrado");
    }
}

int buscar(tptr cab, long int bus){
    int r;
    r=0;
    if(cab!=NULL){
        while(cab!=NULL && r==0){
            if(get_isbn(cab->dato)==bus)
                r=1;
            cab=cab->sig;
        }
    }
    return r;
}

void liberar_lista(tptr *cab){
    tptr aux;
    while(*cab!=NULL){
        aux=*cab;
        *cab=(*cab)->sig;
        free(aux);
        aux=NULL;
    }
}

void mostrar_un_nodo_isbn(tptr cab){
    long int n;
    int r;
    r=0;
    if(cab!=NULL){
        printf("\ningrese el ISBN del libro a buscar:");
        scanf("%ld", &n);
        while(cab!=NULL && r==0){
            if(get_isbn(cab->dato)==n){
                r=1;
                muestra_libro(cab->dato);
            }
            cab=cab->sig;
        }
        if(r==0)
            printf("\nlibro no encontrado.");
    }
    else
        printf("\nlista vacia.");   
}


//fin
