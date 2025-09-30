#include <stdio.h>

typedef int TLis[10] ;

int main(void){
	int i, N;
	TLis Lista;


	
N=12;
	for(i=0; i<N; i++)
		Lista[i]=i+5;
	
	for(i=0; i<N; i++)
		printf("\n valor de lista[%d], %d", i, Lista[i]);
	
	printf("\n Contenido de lista %p", (void*)Lista);
	
	for(i=0; i<N; i++)
		printf("\n posicion de lista[%d], %p", i, (void*)&Lista[i]);

	printf("\n posición de las variables, apreciar el desbordamiento: i: %p, N: %p, lista: %p", (void*) &i,(void*) &N, (void*) &Lista);
	
}

	/*Dada una lista de N numeros naturales, mostrar primero los primos y luego los compuestos
	Dada una lista con una cantidad no determinada de num nat, modificarla ubicando primero los primos y luego los no primos*/
