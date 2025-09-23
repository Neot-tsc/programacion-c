/*Ejercicio 2: 
	Diseñe módulos (prototipo más implementación) para cada uno de los casos que se enuncian a continuación, con el propósito de utilizarlos en problemas posteriores:
	a) Calcule y retorne la cantidad de horas, minutos y segundos que existen en una cantidad de segundos ingresada por el usuario.
	b) Manipule dos números enteros quitando la última cifra del primero y añadiéndola al final del segundo.
	c) Reciba dos variables enteras e intercambie sus valores.*/

#include <stdio.h>


void HsMinSeg(int*,int*,int*,int);
int cantH(int, int*);
int cantM(int, int*);
int menu();
void manipula(int*, int*);
void intercambio(int*, int*);


int main(int argc, char *argv[]) {
	int nseg, horas, minutos, segundos, a, b, op;
	op=menu();
	do{
		switch(op){
		case 1:
			printf("\n\ningrese una cantidad de segundos a calcular: ");
			scanf("%d", &nseg);
			HsMinSeg(&horas,&minutos,&segundos, nseg);
			printf("\nhoras: %d\nminutos: %d\nsegundos: %d",horas, minutos, segundos);
			break;
		case 2:
			printf("\ningrese un numero entero a: ");
			scanf("%d",&a);
			printf("\ningrese un numero entero b: ");
			scanf("%d",&b);
			manipula(&a,&b);
			printf("\nel ultimo digito de a es eliminado de a y añadido como ultimo digito de b.");
			printf("\na: %d    b:%d",a,b);
			break;
		case 3:
			printf("\ningrese un numero entero a: ");
			scanf("%d",&a);
			printf("\ningrese un numero entero b: ");
			scanf("%d",&b);
			intercambio(&a,&b);
			printf("\nintercambia los valores de a y b.");
			printf("\na: %d    b:%d",a,b);
			break;
		}
		op=menu();
	}while(op!=0);
	return 0;
}

int menu(){
	int op;
	do{
		printf("\n## MAIN MENU ##\n");
		printf("\n1) calcual las horas, munutosy segundos de una cantidad de segundos dada.");
		printf("\n2) manipula 2 numero enteros");
		printf("\n3) intercambia los valores de dos variables.");
		printf("\n0) salir del programa.");
		printf("\nseleccione un opcion: ");
		scanf("%d",&op);
	}while(op>4);
	return op;
}

void HsMinSeg(int*horas,int*minutos,int*segundos,int nseg){
	*horas=cantH(nseg,&nseg);
	*minutos=cantM(nseg,&nseg);
	*segundos=nseg;
}
	
int cantH(int a, int*b){
	int horas;
	horas=a/3600;
	*b=*b%3600;
	return horas;
}

int cantM(int a, int*b){
	int minutos;
	minutos=a/60;
	*b=*b%60;
	return minutos;
}

void manipula(int*a, int*b){
	int dig;
	dig=*a%10;
	*b=*b*10+dig;
}

void intercambio(int*a, int*b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}
