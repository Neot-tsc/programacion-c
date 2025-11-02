#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_articulo.h"

#define max 50

typedef Tarticulo articulos [max];

typedef struct{
	articulos vect;
	int tam;
}tlista;

// recordar usar la particion de la structura par hacer le ejercicio

tlista cargar_lista();
void mostrar_lista(tlista);
void agregar(tlista*);
void eliminar(tlista*);
void mostrar_por_proveedor(tlista);
void mostrar_por_stok_minimo(tlista);


#endif
