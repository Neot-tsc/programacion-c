#include <stdio.h>
#include <stdlib.h>



typedef struct nodo{
    int dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;


void pila(tptr*,tptr);
void cola(tptr*,tptr);
tptr retorna_nodo(int);
tptr carga_lista(void);
void carga_lista_ordenado(tptr *,tptr);
void elimina_nodo(tptr*);
void elimina_uno(tptr*, int);
void mostrar(tptr);



int main(void){
    tptr lista;
    lista=NULL;
    lista=carga_lista();
    mostrar(lista);
    elimina_nodo(&lista);
    mostrar(lista);



    return 0;
}


void pila(tptr *cab,tptr nuevo){
    nuevo->sig=*cab;
    *cab=nuevo;
}
void cola(tptr *cab,tptr nuevo){
    tptr aux;
    aux=*cab;
    if(*cab!=NULL){
        while (aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
    else 
        *cab=nuevo;

}

tptr retorna_nodo(int n){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=n;
    aux->sig=NULL;
    return aux;
}
tptr carga_lista(void){
    tptr cab,nuevo;
    cab=NULL;
    nuevo=NULL;
    int n;
    do
    {
        printf("\ningrese un numero para aniadir a la lista(ingresee 0 para finalizar):");
        scanf("%d", &n);
        if(n>0){
            nuevo=retorna_nodo(n);
            carga_lista_ordenado(&cab,nuevo);
        }
        else
            printf("\nlista cargada con exito");
    } while (n>0);
    return cab;
}

void carga_lista_ordenado(tptr *cab,tptr nuevo){
    tptr aux,ant;
    aux=NULL;
    ant=NULL;
    if(*cab==NULL)
        *cab=nuevo;
    else{
        aux=*cab;
        while((aux!=NULL) && (aux->dato<nuevo->dato)){
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


void elimina_nodo(tptr *cab){
    int n;
    if(*cab!=NULL){
        printf("\ningrese el numero a eliminar:");
        scanf("%d", &n);
        elimina_uno(cab,n);
        printf("\nnumero eliminado con exito");
    }
    else
        printf("\nlista vacia");
}

void elimina_uno(tptr *cab, int n){
    tptr ant,aux;
    ant=NULL;
    aux=*cab;
    while(aux!=NULL&& aux->dato!=n){
        ant=aux;
        aux=aux->sig;
    }
    if(aux==NULL)
        printf("\nno encontrado");
    else{
        if(ant==NULL){
            *cab=aux->sig;
            free(aux);
            aux=NULL;
            printf("\narticulo eliminado");
        }
        else{
            ant->sig=aux->sig;
            free(aux);
            aux=NULL;
            printf("\narticulo eliminado");
        }
    }
}

void mostrar(tptr cab){
    if(cab==NULL)
        printf("\nlista vacia");
    else{
        while(cab!=NULL){
            printf("%d,", cab->dato);
            cab=cab->sig;
        }
        printf("\nlista finalizada");
    }
}
