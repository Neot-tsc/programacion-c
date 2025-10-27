#ifndef TAD_LISTA_CUENTAS_H
#define TAD_LISTA_CUENTAS_H
#include "TAD_CUENTAS_H"
#define max 50

typedef tcuenta vector[max];

typedef struct{
	vector lista;
	int tam;
}tlista;

tlista cargar_lista();
void mostrar_lista(tlista);

#endif
