#include <stdio.h>
#include "TAD_NUM_COMPLEJOS.H"


int menu(void);

int main(void){
	tcomplejo A,B,C;
	int op;
	A=carga_uno();
	B=carga_uno();
	do{
		op=menu();
		switch(op){
		case 1:
			C=suma(A,B);
			mostrar_uno(C);
			break;
		case 2:
			C=resta(A,B);
			mostrar_uno(C);
			break;
		case 3:
			C=producto(A,B);
			mostrar_uno(C);
			break;
		case 4:
			C=divicion(A,B);
			mostrar_uno(C);
			break;
		case 0:
			printf("\nsaliendo del programa...  ... . . .");
			break;
		default:
			printf("\ningrese una opcion valida.");
		}
	}while(op!=0);
	
	
	return 0;
}
	

int menu(void){
	int op;
	printf("\n-----MENU-----\n");
	printf("\n1) sumar A+B y mostrar resultado.");
	printf("\n2) restar A+B y mostrar resultado.");
	printf("\n3) producto de A*B y mostrar resultado.");
	printf("\n4) divicion de A/B y mostrar resultado.");
	printf("\n0) salir del programa.");
	printf("\nselecione una opcion:.");
	scanf("%d", &op);
	return op;
}
