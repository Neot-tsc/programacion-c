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
void ingreso(datos ,int*);
void mostrar_uno(tad);
void mostrar_todo(datos, int);
void leecad(tcad);
void depurar(datos, int*);

//inicio del main
int main(void) {
	datos persona;	
	int n;
	ingreso(persona,&n);
	depurar(persona,&n);
	mostrar_todo(persona, n);
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
	printf("mes:");
	scanf("%ld",&aux.fecha.mes);
	printf("anio:");
	scanf("%ld",&aux.fecha.anio);
	return aux;
}



void mostrar_uno(tad datos){
	printf("\napellido y nombre: %s %s",datos.apellido,datos.nombre);
	printf("\nnum de celular: %ld", datos.celular);
	printf("\ndireccion: %s", datos.direccion);
	printf("\nfecha de nacimiento: %d/%d/%d",datos.fecha.dia,datos.fecha.mes, datos.fecha.anio);
}

void mostrar_todo(datos persona, int n){
	int i;
	for(i=1; i<=n; i++){
		printf("\n\ndatos de contacto %d\n\n",i);
		mostrar_uno(persona[i]);
	}
}

void leecad(tcad cad){
	int i;
	char c;
	i=0;
	c=getchar();
	while(c!=EOF && c!='\n' && i<max-1){
		cad[i]=c;
		i++;
		c=getchar();

	}
	cad[i]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}

void ingreso(datos persona,int*n){
	int op,j;
	*n=0;
	do
	{
		printf("\n[1] ingresar datos.");
		printf("\n[0] terminar ingreso.");
		printf("\nseleccione una opcion:");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				(*n)++;
				persona[*n]=retorna_uno();
				persona[0]=persona[*n];
				j=(*n)-1;
				while (strcmp(persona[0].apellido,persona[j].apellido)<0)
				{
					persona[j+1]=persona[j];
					j--;
				}
				persona[j+1]=persona[0];	
			break;
			case 0:
				printf("ingreso terminado.");
			break;
			default:
				printf("\ningrese un opccion valida.");
		}
	} while (op!=0);
	
}

void depurar(datos persona, int*n){
	int i,j;
	if(*n>1){
		j=2;
		for (i=1; i <=*n; i++)
		{
			if(persona[i].celular != persona[j].celular)
			j++;
			else 
				if(i!=j)
				persona[j]=persona[i];
		}
	}
	*n=j;
}