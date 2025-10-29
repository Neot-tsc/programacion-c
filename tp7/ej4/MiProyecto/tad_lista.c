#include "tad_lista.h"

void genera_lista(articulos, int);


tlista cargar_lista(){
    tlista aux;
    printf("\ningrese la cantidad de artuculos a ingresar:");
    scanf("%d", aux.tam);
    genera_lista(aux.vect, aux.tam);
    return aux;
}
void mostrar_lista(tlista);
void agregar(tlista*);
void eliminar(tlista*);


void genera_lista(articulos a, int n){
    int i,j;
    i=1;
    a[i]=retorna_uno();
    for(i=2; i<=n; i++){
        a[i]=retorna_uno();
        a[0]=a[i];
        j=i-1;
        while()
    }
}