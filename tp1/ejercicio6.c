#include <stdio.h>
/*Ejercicio 6: Dados tres n�meros naturales correspondientes a d�a, mes y a�o de una fecha, indicar si dicha fecha es v�lida.*/
int validacion(int,int,int);

int main(int argc, char *argv[]) {
	int dia,mes,año;
	int fecha_valida;
	printf("\ningrese el dia:");
	scanf("%d", &dia);
	printf("\ningrese el mes:");
	scanf("%d", &mes);
	printf("\ningrese el año:");
	scanf("%d", &año);
	fecha_valida = validacion(dia, mes, año);
	if(fecha_valida)
		printf("\nfecha valida\n");
		else
			printf("\ndatos no validos\n");
	
	return 0;
}

int validacion(int dia, int mes, int año){
	int diasMes;

	if(año < 1900 || año > 2025 || mes < 1 || mes > 12 || dia < 1)
		return 0;

	if(mes == 2)
		diasMes = ((año % 400 == 0) || (año % 4 == 0 && año % 100 != 0)) ? 29 : 28;
	else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
		diasMes = 30;
	else
		diasMes = 31;

	return dia <= diasMes;
}