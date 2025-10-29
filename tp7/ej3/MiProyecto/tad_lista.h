#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_persona.h"
#define max 50

typedef tpersona tvector[max];

typedef struct{
	tvector a;
	int tam;
}tlista;

tlista cargar_lista();
void cargar_vector(tvector, int);
void mostrar_lista(tlista);
void ordena_lista(tlista*);
void agregar_uno(tlista*);


#endif
