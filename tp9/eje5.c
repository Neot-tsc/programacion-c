/*Ej 5 - Un Almacén de Ramos Generales requiere de un programa que permita 
administrar una lista con los N artículos que comercializa, la información de 
cada artículo a registrar es: 

	~ Código de Artículo 
	~ Nombre de Artículo 
	~ Stock 
	~ Precio de venta.

El programa debe permitir ingresar la lista y que la misma se ordene por Código 
de Artículo a medida que se ingresan. Luego debe presentar un menú de opciones 
que permita las siguientes operaciones:

1) Agregar un nuevo artículo conservando el orden.
2) Modificar el precio de venta de un Artículo, dado su Código de Artículo.
3) Dado el Nombre de un Artículo mostrar Código de Artículo, Stock y Precio de 
venta de cada artículo que tenga ese nombre.
4) Eliminar un artículo, dado su Código de Artículo.
5) Crear una nueva lista con los Artículos cuyo Stock es menor a K, donde K es 
un número natural generado aleatoriamente, entre los valores [prom, 2*prom], 
donde prom es el valor promedio del Stock de los Artículos.*/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 50



//##############
typedef char tcad [max];

//funciondes de tcad
void leecad(tcad);
int compara_cad(tcad,tcad);

//fin

typedef struct 
{
    long int codigo;
    tcad nombre;
    int stok;
    float precio;
}tarticulo;
//funciones de tarticulo
tarticulo retorna_articulo(long int);
void mostrar_articulo(tarticulo);
void modifica_cod_art(tarticulo*);
int compara_nom_art(tarticulo, tarticulo);
int compara_cod_art(tarticulo,tarticulo);
int compara_codigo(long int, long int);
int compara_stok_art(int,int);

//fin


typedef struct nodo
{
    tarticulo dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

//funciones de tptr y nodo
tptr retorna_nodo(long int);
tptr retorna_lista(void);
void pila(tptr*,tptr);
void cola(tptr*,tptr);
void inserta_nodo_ordenado(tptr*,tptr);
void agrega_un_nodo(tptr*);
void mostrar_lista(tptr);
void liberar_lista(tptr*);
int compara_cod(tptr,tptr);
void modifica_nodo_precio(tptr);
int buscar_por_cod(tptr,long int);
void mostrar_nod_por_nom(tptr);
void elimina_nodo(tptr*);
void elimina_uno(tptr *, long int);
tptr nueva_lista(tptr);
int promedio_stok(tptr);
tptr copia_nodo(tptr);

//fin



// otras declaraciones de otras funciones
int nrorandom(int,int);
int menu(void);

//fin



//inicio del amin
int main(void){
    tptr cab,lis;
    int op;
    cab=NULL;
    lis=NULL;
    cab=retorna_lista();
    mostrar_lista(cab);
    do
    {
        op=menu();
        switch(op){
            case 1:
                agrega_un_nodo(&cab);
                break;
            case 2:
                modifica_nodo_precio(cab);
                break;
            case 3:
                mostrar_nod_por_nom(cab);
                break;
            case 4:
                elimina_nodo(&cab);
                break;
            case 5:
                lis=nueva_lista(cab);
                mostrar_lista(lis);
                break;
            case 6:
                mostrar_lista(cab);
                break;
            case 0:
                printf("\nsaliendo del programa.");
                break;
            default:
                printf("\ningrese una opcion valida.");
        }
    } while (op!=0);
    liberar_lista(&cab);
    liberar_lista(&lis);

    return 0;
}

//fin del main

// inicio del cuerpo de las funciones tarticulo
tarticulo retorna_articulo(long int n){
    tarticulo aux;
    aux.codigo=n;
    printf("\ningrese el nombre del articulo:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el stok del articulo:");
    scanf("%d", &aux.stok);
    printf("\ningrese el precio:");
    scanf("%f",&aux.precio);
    return aux;
}

void mostrar_articulo(tarticulo a){
    printf("\ncodigo: %ld", a.codigo);
    printf("\nnombre: %s", a.nombre);
    printf("\nstok: %d", a.stok);
    printf("\nprecio: %2.f\n", a.precio);
}

void modifica_cod_art(tarticulo *a){
    float nuevo;
    printf("\ningrese el nuevo precio del articulo:");
    scanf("%f", &nuevo);
    a->precio=nuevo;
    printf("\narticulo modificado con exito.");
}

int compara_nom_art(tarticulo a, tarticulo b){
    return compara_cad(a.nombre,b.nombre);
}

int compara_cod_art(tarticulo a,tarticulo b){
    return compara_codigo(a.codigo,b.codigo);
}

int compara_codigo(long int a, long int b){
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

// fin del cuerpo de las funciones tarticulo

//inicio del cuerpo de las funciones tptr y nodo

tptr retorna_nodo(long int n){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=retorna_articulo(n);
    aux->sig=NULL;
    return aux;
}
tptr retorna_lista(void){
    tptr cab;
    cab=NULL;
    int n,i;
    i=1;
    printf("\ningrese la cantidad de articulos a ingresar:");
    scanf("%d", &n);
    while(i<=n){
        printf("\ndatos del articulo %d\n",i);
        agrega_un_nodo(&cab);
        i++;
    }
    printf("\ncarga finalizada");
	
	return cab;
}
//a
void agrega_un_nodo(tptr *cab){
    tptr nuevo;
    long int cod;
    printf("\ningrese el codigo del nuevo articulo:");
    scanf("%ld", &cod);
    nuevo=retorna_nodo(cod);
    inserta_nodo_ordenado(cab,nuevo);
}



void pila(tptr *cab,tptr nuevo){
    nuevo->sig=*cab;
    *cab=nuevo;
}
void cola(tptr *cab,tptr nuevo){
    tptr aux;
    aux=*cab;
    if(*cab!=NULL){
        while (aux->sig != NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
    else    
        *cab=nuevo;
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

int compara_cod(tptr a,tptr b){
    return compara_cod_art(a->dato,b->dato);
}

void mostrar_lista(tptr cab){
    int i;
    i=1;
    if(cab==NULL)
        printf("\nlista vacia.");
    else{
        while(cab!=NULL){
            printf("\narticulo nro %d\n",i);
            mostrar_articulo(cab->dato);
            cab=cab->sig;
            i++;
        }
    }
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
//b
void modifica_nodo_precio(tptr cab){
    long int bus;
    if(cab!=NULL){
        printf("\ningrese el codigo del articulo a modificar:");
        scanf("%ld",&bus);
        if(buscar_por_cod(cab,bus)==1){
            modifica_cod_art(&cab->dato);
        }
        else
            printf("\narticulo no encontrado.");
    }
    else    
        printf("\nlista vacia.");
}

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

//c
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

//d
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
 
//e
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

tptr copia_nodo(tptr cab){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=cab->dato;
    aux->sig=NULL;
    return aux;
}

//fin del cuerpo de las funciones tptr y nodo

//otras funciones 

int nrorandom(int ini,int fin){
    return ini+rand()%(fin-ini+1);
}

int menu(void){
    int op;
    printf("\n-----MENU-----\n");
    printf("\n1) agregar un nuevo articulo.");
    printf("\n2) modificar el precio de un articulo.");
    printf("\n3) mostrar los articulos con un mismo nombre.");
    printf("\n4) eliminar un articulo.");
    printf("\n5) crear una nueva lista con stok menor que k.");
    printf("\n6) mostrar lista articulo.");
    printf("\n0) salir de la lista.");
    printf("\nseleccione una opcion: ");
    scanf("%d",&op);
    return op;
}

//fin del cuerpo de otras funciones


//inicio del cuerpo de las funciones tcad


void leecad(tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while (c!=EOF && c!='\n' && j<max-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while (c!=EOF && c!='\n')
        c=getchar();
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

//fin del cuerpo de las funciones tcad

//punto c
void mostrar_nod_por_nom(tptr);

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