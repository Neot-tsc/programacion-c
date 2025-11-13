#include <stdio.h>
#include <stdlib.h>
#define max 50

typedef char tcad [max];

typedef struct{
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


//procedimiento y funciones del tarticulo
void leecad(tcad);
tarticulo retornar_articulo(long int);
void muestra_articulo(tarticulo);
void modifica_tarticulo_precio(tarticulo*);

//proceddimiento y funciones de tptr

tptr retorna_nodo(long int);
void carga_lista_nodos(tptr*);
void pila(tptr*,tptr);
void cola(tptr*,tptr);
void mostrar_lista_nodos(tptr);
void modifica_articulo_precio(tptr);\
void liberar_lista(tptr*);






















//procedimiento y funciones del tarticulo
void leecad(tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while(c!=EOF && c!='\n' && j<=max-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while (c!=EOF && c!='\n')
        c=getchar();
}

tarticulo retornar_articulo(long int n){
    tarticulo aux;
    aux.codigo=n;
    printf("\ningrese el nombre del articulo:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el stok del producto: ");
    scanf("%d", &aux.stok);
    printf("\ningrese el precio:");
    scanf("%f", &aux.precio);
    return aux;
}

void muestra_articulo(tarticulo a){
    printf("\ncodigo del articulo: %ld", a.codigo);
    printf("\nnombre del articulo: %s", a.nombre);
    printf("\ncantidad de stok del articulo: %d", a.stok);
    printf("\nprecio del articulo: %f.2", a.precio);
}

void modifica_tarticulo_precio(tarticulo *a){
    printf("\ningrese el nuevo precio:");
    scanf("%f", a->precio);
    printf("\nprecio modificado exitosamente.");
}

//proceddimiento y funciones de tptr

tptr retorna_nodo(long int);
void carga_lista_nodos(tptr*);
void pila(tptr*,tptr);
void cola(tptr*,tptr);
void mostrar_lista_nodos(tptr);
void modifica_articulo_precio(tptr);\
void liberar_lista(tptr*);