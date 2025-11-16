
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 50


typedef char tcad [max];

typedef struct 
{
    long int codigo;
    tcad nombre;
    int stok;
    float precio;
}tarticulo;

typedef struct nodo
{
    tarticulo dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

//punto c


void mostrar_nod_por_nom(tptr cab){
    tcad bus;
    int b;
    b=0;
    if(cab==NULL)
        printf("\nlista vacia");
    else{
        printf("\ningrese el nombre del producto a buscar:");
        fflush(stdin);
        leecad(bus);
        while (cab!=NULL){
            if(compara_cad(cab->dato.nombre,bus)==0){
                b=1;  
                mostrar_articulo(cab->dato);
            }
            cab=cab->sig;
        }
    }
    if(b==0)
        printf("\n articulo no encontrado.");
}

int compara_cad(tcad a,tcad b){
    int r;
    if(strcmp(a,b)>0)
        r=1;
    else{
        if(strcmp(a,b)<0)
            r=-1;
        else
            r=0;
    }
    return r;
}

void mostrar_articulo(tarticulo a){
    printf("\ncodigo: %ld", a.codigo);
    printf("\nnombre: %s", a.nombre);
    printf("\nstok: %d", a.stok);
    printf("\nprecio: %2.f\n", a.precio);
}

//punto d

void elimina_nodo(tptr *cab){
    long int n;
    if(*cab!=NULL){
        printf("\ningrese el codigo delarticulo a eliminar:");
        scanf("%ld", &n);
        elimina_uno(cab,n);
    }
    else
        printf("\nlista vacia.");
}

void elimina_uno(tptr *cab, long int n){
    tptr aux,ant;
    aux=*cab;
    ant=NULL;
    while (aux!=NULL && buscar_por_cod(aux,n)!=1){
        ant=aux;
        aux=aux->sig;
    }
    if(aux==NULL)
        printf("\narticulo no encontrado.");
    else{
        if(ant==NULL){
            *cab=aux->sig;
            free(aux);
            aux=NULL;
        }
        else{
            ant->sig=aux->sig;
            free(aux);
            aux=NULL;
            printf("\narticulo eliminado con exito.");
        }
    }
}
 
//debuelve 1 si esta 0 si no esta en la lista
int buscar_por_cod(tptr cab,long int bus){
    int r;
    r=0;
    while (cab!=NULL && r==0){
        if(cab->dato.codigo==bus)
            r=1;
        else
            cab=cab->sig;
    }
    return r;
}

//punto e
tptr nueva_lista(tptr cab){
    tptr lis,nuevo;
    lis=NULL;
    int k, prom;
    srand(time(NULL));
    if(cab!=NULL){
        prom=promedio_stok(cab);
        k=nrorandom(prom,2*prom);
        while(cab!=NULL){
            if(compara_stok_art(cab->dato.stok,k)==-1){
                nuevo=copia_nodo(cab);
                inserta_nodo_ordenado(&lis,nuevo);
            }
            cab=cab->sig;
        }  
    }
    else
        printf("\nlista vacia.");
    return lis;
}

//davuelde el promedio del stok
int promedio_stok(tptr cab){
    int acu,cont,prom;
    acu=0;cont=0;
    if(cab==NULL)
        prom=0;
    else{
        while(cab!=NULL){
            cont++;
            acu=acu+cab->dato.stok;
            cab=cab->sig;
        }
        prom=acu/cont;
    } 
    return prom;
}

//retorna un numero random entre ini y fin
int nrorandom(int ini,int fin){
    return ini+rand()%(fin-ini+1);
}

//compoara dos enteros de stok 0 si son iguales, 1 si a>b, -1 si a<b
int compara_stok_art(int a,int b){
    int r;
    r=0;
    if(a>b)
        r=1;
    else{
        if(a<b)
            r=-1;
    }
    return r;
}

tptr copia_nodo(tptr cab){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=cab->dato;
    aux->sig=NULL;
    return aux;
}

void inserta_nodo_ordenado(tptr *cab,tptr nuevo){
    tptr aux,ant;
    aux=NULL;
    ant=NULL;
    if(*cab==NULL)
        *cab=nuevo;
    else{
        aux=*cab;
        ant=NULL;
        while ((aux!=NULL)&&(compara_cod(nuevo,aux)==1)){
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