#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_registro.h"
#define TAMV 40
typedef Talumno Tvec[TAMV];
typedef struct{
	Tvec v;
	int tam;
}Tlista;

Tlista carga_lista();
void agregar(Tlista*);
int retorna_tam(Tlista);
void modificar_alumno(Tlista *);
void mostrar_lista(Tlista);
void dar_bajas(Tlista*);
Tlista generarOtra_estado(Tlista);
void ordenar_lista(Tlista *);

#endif
