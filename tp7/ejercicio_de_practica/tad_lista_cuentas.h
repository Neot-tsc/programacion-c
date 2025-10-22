#ifndef TAD_LISTA_CUENTAS_H
#define TAD_LISTA_CUENTAS_H

#include "TAD_CUENTA_H"
#define max 50

typedef Tcuenta vect[max];
typedef struct{
	vect lista;
	int tam
}tlista;


tlista cargar_lista();
void mostrar_lista(tlista);
void ordenar_lista(tlista*);
void mostrar_cuenta(tlista);

#endif
