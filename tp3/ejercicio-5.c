/*Ejercicio 5: Cree un programa que ingrese un n�mero real X, que trabaje con 4 d�gitos decimales de precisi�n, 
a partir de este n�mero real obtener la parte entera de X y su parte decimal convertida a un n�mero entero.
Nota: Generar un procedimiento que reciba X y devuelva PentX, PdecX. Ejemplo, si X= 123,5432, entonces PentX=123 y PdecX= 5432*/

#include <stdio.h>
#include <stdlib.h>


void separa_entero_decimal(float, int*, int*);


int main(int argc, char *argv[]) {
	float x;
	x=234.7345;
	int entera, decimal;
	separa(x,&entera,&decimal);
	decimal++;
	printf("%d, %d,", entera, decimal);
	return 0;
}

void separa_entero_decima(float x, int *entero, int *decimal){
	float aux;
	aux=x;
	*entero=(int)x;
	aux=x-(int)x;
	*decimal=aux*10000;
}

