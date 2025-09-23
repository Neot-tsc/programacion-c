#include <stdio.h>
/*Ejercicio 6: Dados tres números naturales correspondientes a día, mes y año de una fecha, indicar si dicha fecha es válida.*/


int main(int argc, char *argv[]) {
	int dia,mes,año;
	printf("\ningrese el dia:");
	scanf("%d", &dia);
	printf("\ningrese el mes:");
	scanf("%d", &mes);
	printf("\ningrese el año:");
	scanf("%d", &año);
	if(año<1900 || año>2025)
		printf("\ndatos no validos");
	
	return 0;
}

