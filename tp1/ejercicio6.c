#include <stdio.h>
/*Ejercicio 6: Dados tres n�meros naturales correspondientes a d�a, mes y a�o de una fecha, indicar si dicha fecha es v�lida.*/


int main(int argc, char *argv[]) {
	int dia,mes,a�o;
	printf("\ningrese el dia:");
	scanf("%d", &dia);
	printf("\ningrese el mes:");
	scanf("%d", &mes);
	printf("\ningrese el a�o:");
	scanf("%d", &a�o);
	if(a�o<1900 || a�o>2025)
		printf("\ndatos no validos");
	
	return 0;
}

