#include <stdio.h>
/*dados dos numeros enteors a y b realice las siguientes operaciones en funcion de una opcion ingresada por el usuario: si el usuario ingresa 1 muetra a+b 2 muestra a*b
3 muestra a-b*/

int main(int argc, char *argv[]) {
	int a,b, op=0,r;
	printf("\ningrese el valor de a:");
	scanf("%d", &a);
	printf("\ningrese el valor de b:");
	scanf("%d", &b);
	printf("\nmenu");
	printf("\n1)suma");
	printf("\n2)producto");
	printf("\n3)resta");
	printf("\nseleccione una opcion");
	scanf("%d",&op);
	switch(op){
		case 1:
			r=a+b;
			printf("el resultado es :%d", r);
			break;
		case 2:
			r=a*b;
			printf("el resultado es :%d", r);
			break;
		case 3:
			r=a-b;
			printf("el resultado es :%d", r);
			break;
		default : printf("\nopcion incorrecta");
	}
	
	return 0;
}

