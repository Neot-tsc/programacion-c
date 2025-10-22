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
	
void mostrar_uno(Tcuenta a){
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

/*int busqueda_secuencial(vect a, int n, int buscado){
	int i,pos;
	pos=0;
	i=1;
	while(i<=n && a[i].numero!= buscado)
		i++;
	if(i<n)
		pos=i;
	return pos;
}
	
 void cargar_lista(vect a, int *n){
	int i;
	printf("\ningrese la cantidad de cuentas de la lista:");
	scanf("%d", n);
	if(*n<=max){
		for(i=1; i<=*n; i++)
			a[i]=cargar_cuenta();
	}
	else
		printf("\nse supero el tamanio maximo de la lsita. ingrese menos elementos o elimine algun elemento ya existente");
 }
	
void mostrar_todo(vect a, int n){
	int i;
	printf("\ndatos de la lista\n");
	for(i=1; i<=n; i++){
		printf("\ncuenta pos %d", i);
		mostrar_uno(a[i]);
	}
}
	
void ordena_secuencial(vect a, int n){
	int i,j;
	Tcuenta aux;
	for(i=1; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[j].numero<a[i].numero){
				aux=a[j];
				a[j]=a[i];
				a[i]=aux;
			}
		}
	}
}
*/
