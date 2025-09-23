/*dado n numeros naturales, para cada num ingresado si es par modificarlo elimiando
todos sus dig impares, caso contrario calcular su triple, mostrar*/

#include <stdio.h>

int es_par(int);
int triple(int);

int main(int argc, char *argv[]) {
	int n,i,A,nA,;
	float a;
	printf("\ningrese la cantidad de nuemero naturares de la lista);
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		printf("\ningrese un numero natural:");
		scanf("%f",&n)
		A=(int)a;
		if(int es_par(int A)){
			
		}
		else {
			A=A*3;
			printf("\nel numero modificado es: $d",A);
		}
	}
	return 0;
}

int es_par(int a){
	int r;
	if(a%2==0)
		r=1;
	else 
		r=0;
	return r;
}
	
	
void entradafraccion(int *numerador, int *denominador){
	printf("ingrese el numerador");
	scanf("%d",n);
	do{
		printf("ingrese un denominador distinto de 0");
		scanf("%d",d)
	}while(*d==0)
}
	
	
	
void salidafraccion(int numerador, int denominador){
	if(numerador==0 || denominador==1)
		printf("%d\n", numerador);
	else 
		printf("\n%d/%d\n",numerador,denominador);
}
	
entregar el ejercicio 9 
		ejercicio 10 usar long int 
