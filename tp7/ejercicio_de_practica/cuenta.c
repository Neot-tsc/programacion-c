#include "Tad_cuenta.h"
#include <stdio.h>



Tcuenta cargar_cuenta(){
	Tcuenta aux;
	printf("\ningrese el dni del usuario:");
	scanf("%ld", &aux.dni);
	printf("\ningrese el numero de cuenta:");
	scanf("%d", &aux.numero);
	aux.saldo=0;
	return aux;
}
	
void mostrar_cuenta(Tcuenta a){
	printf("\ndni de la cuenta: %ld", a.dni);
	printf("\nnumero de cuenta: %d", a.numero);
	printf("\nsaldo de la cuenta: %f", a.saldo);
}

void modifica_saldo_sum(Tcuenta *a,float nuevo){
	a->saldo=a->saldo+nuevo;
}
void modifica_saldo_resta(Tcuenta *a,float nuevo){
	a->saldo=a->saldo-nuevo;
}

void agregar_saldo(Tcuenta *a){
	float nuevo;
	printf("\ningrese el saldo:");
	scanf("%f", &nuevo ),
	modifica_saldo_sum(a,nuevo);
}
void retirar_saldo(Tcuenta *a){
	float nuevo;
	printf("\ningrese el saldo:");
	scanf("%f", &nuevo );
	modifica_saldo_resta(a,nuevo);
}
void mostrar_cuenta_dni(Tcuenta a){
	printf("\ndni: %ld", a.dni);
	printf("\nnumero de la cuenta: %d",a.numero);
	printf("\nsaldo disponible: %f", a.saldo);
}

 