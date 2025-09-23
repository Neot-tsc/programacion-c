#include <stdio.h>

/*Ejercicio 5: Calcular la cantidad de horas, minutos y segundos que existen en una cantidad de segundos ingresada por el usuario.*/

int main(int argc, char *argv[]) {
	int seging, horas=0, min=0, seg=0;
	printf("\ningrese la cantidad de segundos que desea calcular:");
	scanf("%d", &seging);
	if(seging>0){
		horas=seging/3600;
		seging=seging%3600;
		min=seging/60;
		seging=seging%60;
		seg=seging;
	}else printf("\ncantidad de segundos negativa, haga otro ingreso."); 
	printf("\nhoras:%d, minutos:%d, segundos:%d", horas, min, seg);
	
	return 0;
}
