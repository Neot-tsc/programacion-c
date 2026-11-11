/*Ejercicio 13: 
Realizar un programa que genere al azar una lista de N números naturales aleatorios, en 
el rango [A, B] (con A y B naturales) y muestre aquellos números aleatorios que cumplan con no ser 
deficientes. 
Nota: reutilizar la función generada en el ejercicio 11.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

typedef int Tlista[max];

void genera_lista(Tlista, int*, int, int);

int nrandom(int,int);
int suma_divisores(int);
int es_deficiente(int);
