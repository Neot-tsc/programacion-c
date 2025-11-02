#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_datos.h"

#define max 50

typedef tdatos datos[max];

typedef struct 
{
    datos lista;
    int tam;
} tlista;

tlista cargar_lista();
void mostrar_lista(tlista);
void agregar(tlista*);
void eliminar(tlista*);
void ordenar_lista(tlista*);
void acreditar_saldo(tlista*);
void debitar_saldo(tlista*);
#endif