#ifndef TAD_PUNTERO_H
#define TAD_PUNTERO_H
#include "tad_libro.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
    tlibro dato;
    struct nodo *sig;
} tnodo;

typedef tnodo *tptr;
//funciones y procedimientos de tptr
tptr retorna_nodo(tlibro);
void carga_lista_nodos(tptr*);
void pila(tptr*, tptr);
void cola(tptr*,tptr);
void agrega_un_nodo_ordenado(tptr*,tptr);
void mostrar_lista_nodos(tptr);
void mostrar_un_nodo_isbn(tptr);
void modifica_tipo_nodo(tptr);
int buscar(tptr, long int);
void liberar_lista(tptr*);
//fin
#endif
