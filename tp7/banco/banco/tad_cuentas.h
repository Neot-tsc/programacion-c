#ifndef TAD_CUENTAS_H
#define TAD_CUENTAS_H
#include <stdlib.h>

typedef struct{
	long int dni;
	int numero;
	float saldo;
}tcuenta;

tcuenta cargar();
void mostrar_cuenta(tcuenta);


#endif
