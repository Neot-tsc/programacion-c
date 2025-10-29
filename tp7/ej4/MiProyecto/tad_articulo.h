#ifndef TAD_ARTICULO_H
#define TAD_ARTICULO_H
#include <stdio.h>
#include "tad_cadena.h"

typedef struct{
	int codigo,stok;
	tcad nombre, proveedor;
	float precio;
}Tarticulo;

Tarticulo retorna_uno();
void muestra_uno(Tarticulo);


#endif
