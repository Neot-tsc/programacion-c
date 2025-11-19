#ifndef TAD_PUNTERO_H
#define TAD_PUNTERO_H
#include <stdio.h>
#include <stdlib.h>
#include "tad_alumno.h"

typedef struct nodo
{
    talumno dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

//funciones y procedimientos de tptr
tptr  retorna_nodo(talumno);
tptr carga_lista(void);
void agrega_uno_ordenado(tptr*, tptr);
void pila(tptr*, tptr);
void mostrar_lista(tptr);
void mostrar_un_alumno(tptr);
void elimina_nodo(tptr*);
void elimina_uno(tptr*, int);
void liberar_lista(tptr*);
void mostrar_reg_lib(tptr);
//fin


#endif