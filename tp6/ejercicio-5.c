/*Ejercicio 5: Se necesita crear un programa que maneje una Agenda telef�nica de 
amigos, que almacena los siguientes datos de cada persona: �Apellidos, Nombres, 
Direcci�n, Celular, Fecha de nacimiento�.  Realizar un programa que permita cargar 
la lista de amigos y que la misma se ordene alfab�ticamente por Apellidos y Nombres 
a medida que cargan los registros. Utilizando un men� permita realizar las siguientes
 operaciones:   */
/*	a)A�adir un nuevo contacto, considerando que cada contacto es �nico. (Mantener ordenada la lista por apellido y nombres).   */
/*	b)Borrar un contacto. (Mantener ordenada la lista por apellido y nombres).   */
/*	c)Dado el apellido y el nombre, modificar su direcci�n o su tel�fono.   */
/*	e)Dado un apellido y el nombre, mostrar sus datos.   */
/*	f)Mostrar la agenda telef�nica completa.   */
/*	g)Dado un apellido, mostrar todos los datos de las personas con ese apellido.   */
/*	h)Dado un mes, mostrar todas las personas que cumplen a�os en ese mes.   */


#include <stdio.h>
#include <string.h>
#define max 50

typedef char tcad[max];

typedef struct{
	int dia,mes,anio;
}calendario;

typedef struct{
	tcad apellido, nombre,direccion;
	long int celular;
	calendario fecha;
}tad;

typedef tad datos[max];
tad retorna_uno();
void cargar_lista(datos, int*);
void ing_baraja_notam(datos, int*);
int confirmar(datos, int, long int );




//inicio del main
int main(void) {
	datos persona;	
	return 0;
}




tad retorna_uno(){
	tad aux;
	printf("\ningrese el nombre del usuario:");
	fflush(stdin);
	leecad(aux.nombre);
	printf("\ningrese el apellido del usuario:");
	fflush(stdin);
	leecad(aux.apellido);
	printf("\ningrese la direccion del usuario:");
	fflush(stdin);
	leecad(aux.direccion);
	printf("\ningrse el numero de celular: ");
	scanf("%ld",&aux.celular);
	printf("\nfecha de nacimiento:\n");
	printf("\ndia:");
	scanf("%ld",&aux.fecha.dia);
	printf("\nmes:");
	scanf("%ld",&aux.fecha.mes);
	printf("\nanio:");
	scanf("%ld",&aux.fecha.anio);
	return aux;
}

void cargar_lista(datos persona, int*n){
	int i,j,op;
	do
	{
		printf("\n1) ingresar nuevo usuario.");
		printf("\n0) terminar ingreso.");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				(*n)++;
				persona[0]=retorna_uno();
				break;
			case 0:
				printf("\ningreso completado");
				break;
			default:
				printf("\ningrese una opcion valida");
				break;
		}
	} while (op!=0);
	
}


void ing_baraja_notam(datos persona, int* n){
	int i,j,ban;
	i=0;
	ban=1;
	do
	{
		i++;
		persona[i]=retorna_uno();
		if(persona[i].celular!=0){
			if()
		}

	} while (ban==1);
	
}

int confirmar(datos persona, int n, long int nuevo ){
	int r,i,ban;
	r=1;
	i=1;
	ban=1;
	while(i<n && ban==1){
		if(persona[i].celular == nuevo){
			ban=0;
			r=0;
		}
		i++;
	}
    return r;
}
