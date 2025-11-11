#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_cadena.h"
#include <stdlib.h>
#define tmax 50

typedef tcad lista[tmax];

typedef struct{
    lista nombres;
    int tam;
}tdatos;

tdatos cargar_datos(void);
void ordenar(tdatos*);
void mostrar(tdatos);




#endif