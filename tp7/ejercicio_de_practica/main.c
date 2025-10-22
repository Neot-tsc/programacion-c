#include <stdio.h>
#include "Tad_cuenta.h"





int menu();


int main(void){
	vect a;
	int n=3, pos;
	float nuevo;
	int op;
	a[1]=cargar_cuenta();
	a[2]=cargar_cuenta();
	a[3]=cargar_cuenta();
	int buscado;
	do
	{
		op=menu();
		switch (op)
		{
		case 1:
			printf("\ningrese el numero de cuenta a mostrar:");
			scanf("%d", &buscado);
			pos=busqueda_secuencial(a,n,buscado);
			mostrar_cuenta(a[pos]);
			break;
		case 2:
			printf("\ningrese el numero de la cuenta:");
			scanf("%d", &buscado);
			pos=busqueda_secuencial(a,n,buscado);
			printf("\ningrese el saldo a agregar:");
			scanf("%f", &nuevo);
			modifica_saldo_sum(&a[pos], nuevo);
			break;
		case 3:
			printf("\ningrese el numero de la cuenta:");
			scanf("%d", &buscado);
			pos=busqueda_secuencial(a,n,buscado);
			printf("\ningrese el saldo a retirar:");
			scanf("%f", &nuevo);
			modifica_saldo_resta(&a[pos], nuevo);
			break;
		case 0:
			printf("\nsaliendo del prgrama");
			break;
		default:
			printf("\ningrese una opcion valida.");
		}
	} while (op!=0);
	
	return 0;
}

int menu(){
	int op;
	printf("\n------MENU------");
	printf("\n1) mostrar cuenta.");
	printf("\n2) agregar saldo.");
	printf("\n3) restar saldo.");
	printf("\n0) salir.");
	printf("\nseleccione una opcion: ");
	scanf("%d",&op);
	return op;
}


