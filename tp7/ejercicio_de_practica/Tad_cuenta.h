#ifndef TAD_CUENTA_H
#define TAD_CUENTA_H

typedef struct{
	long dni;
	int numero;
	float saldo;
}Tcuenta;

typedef Tcuenta vect[10];

Tcuenta cargar_cuenta();
void mostrar_cuenta(Tcuenta);
void modifica_saldo_sum(Tcuenta *,float);
void modifica_saldo_resta(Tcuenta *,float);
void agregar_saldo(Tcuenta *);
void retirar_saldo(Tcuenta *);
void mostrar_cuenta_dni(Tcuenta);
int busqueda_secuencial(vect , int, int);
#endif
