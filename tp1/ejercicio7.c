#include <stdio.h>

/*Ejercicio 7: Dadas las estaturas de tres personas, calcular la estatura promedio. (No utilizar ciclos)*/

int main(int argc, char *argv[]) {
	float per1, per2, per3, prom;
	int suma;
	printf("\ningrese las alturas sin comas o puntos");
	printf("\ningrese la altura de la primera persona:");
	scanf("%f", &per1);
	printf("\ningrese la altura de la segunda persona persona:");
	scanf("%f", &per2);
	printf("\ningrese la altura de la tercera persona:");
	scanf("%f", &per3);
	suma=per1+per2+per3;
	prom=(float)suma/3; /*para comvertir un numero en real o a lo que necesite*/
	printf("el promedio es: %.2f", prom); /*el .2 es para visualizar la cantidad de 0 */
	return 0;
}

