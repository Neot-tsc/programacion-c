#ifndef TAD_CUENTA_H
#define TAD_CUENTA_H



typedef struct{
	long dni;
	int numero;
	float saldo;
}Tcuenta;



Tcuenta cargar_cuenta();
//void cargar_lista(vect, int*);
void mostrar_uno(Tcuenta);
void modifica_saldo_sum(Tcuenta *,float);
void modifica_saldo_resta(Tcuenta *,float);
void agregar_saldo(Tcuenta *);
void retirar_saldo(Tcuenta *);
void mostrar_cuenta_dni(Tcuenta);
/*int busqueda_secuencial(vect , int, int);
void mostrar_todo(vect, int);void ordena_secuencial(vect, int);*/

#endif
