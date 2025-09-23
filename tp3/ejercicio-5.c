/*Ejercicio 5: Cree un programa que ingrese un número real X, que trabaje con 4 dígitos decimales de precisión, 
a partir de este número real obtener la parte entera de X y su parte decimal convertida a un número entero.
Nota: Generar un procedimiento que reciba X y devuelva PentX, PdecX. Ejemplo, si X= 123,5432, entonces PentX=123 y PdecX= 5432*/

#include <stdio.h>
#include <stdlib.h>


void separa(float, int*, int*);


int main(int argc, char *argv[]) {
	float x;
	x=234.7345;
	int entera, decimal;
	separa(x,&entera,&decimal);
	decimal++;
	printf("%d, %d,", entera, decimal);
	return 0;
}

void separa(float x, int *entero, int *decimal){
	float aux;
	aux=x;
	*entero=(int)x;
	aux=x-(int)x;
	*decimal=aux*10000;
}

