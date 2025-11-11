#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_datos.h"
#define tmax 50

typedef datos lista[tmax];

typedef struct 
{
    lista persona;
    int tam;
}tclientes;


tclientes cargar_clientes(void);
void ordenar_clientes(tclientes*);
void mostrar_clientes(tclientes);






#endif