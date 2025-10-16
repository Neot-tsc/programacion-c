/*Ejercicio 5: Se necesita crear un programa que maneje una Agenda telef�nica de 
amigos, que almacena los siguientes datos de cada persona: �Apellidos, Nombres, 
Direcci�n, Celular, Fecha de nacimiento�.  Realizar un programa que permita cargar 
la lista de amigos y que la misma se ordene alfab�ticamente por Apellidos y Nombres 
a medida que cargan los registros. Utilizando un men� permita realizar las siguientes
 operaciones:   */
/*	a)A�adir un nuevo contacto, considerando que cada contacto es �nico. (Mantener ordenada la lista por apellido y nombres).*/
/*	b)Borrar un contacto. (Mantener ordenada la lista por apellido y nombres).   */
/*	c)Dado el apellido y el nombre, modificar su direcci�n o su tel�fono.   */
/*	e)Dado un apellido y el nombre, mostrar sus datos.   */
/*	f)Mostrar la agenda telef�nica completa.   */
/*	g)Dado un apellido, mostrar todos los datos de las personas con ese apellido.   */
/*	h)Dado un mes, mostrar todas las personas que cumplen a�os en ese mes. */


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



tad retorna_uno(long int);
void ingreso(datos ,int*);
void baraja(datos, int*, long int);
void mostrar_uno(tad);
void mostrar_todo(datos, int);
void leecad(tcad);
void aniadir_uno(datos, int*);
int busqueda_bin(datos, int, long int); 
void elimina_uno(datos, int*, int);
void eliminar(datos, int*);
//inicio del main
int main(void) {
	datos persona;	
	int n;
	ingreso(persona,&n);
	mostrar_todo(persona, n);
	return 0;
}




tad retorna_uno(long int num){
	tad aux;
	aux.celular=num;
	printf("\ningrese el nombre del usuario:");
	fflush(stdin);
	leecad(aux.nombre);
	printf("\ningrese el apellido del usuario:");
	fflush(stdin);
	leecad(aux.apellido);
	printf("\ningrese la direccion del usuario:");
	fflush(stdin);
	leecad(aux.direccion);
	printf("\nfecha de nacimiento:\n");
	printf("\ndia:");
	scanf("%d",&aux.fecha.dia);
	printf("mes:");
	scanf("%d",&aux.fecha.mes);
	printf("anio:");
	scanf("%d",&aux.fecha.anio);
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
	int op;
	long int num;
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
				printf("\ningree el numero de celular:");
				scanf("%ld",&num);
				baraja(persona,n,num);
			break;
			case 0:
				printf("ingreso terminado.");
			break;
			default:
				printf("\ningrese un opccion valida.");
		}
	} while (op!=0);
}

void baraja(datos persona, int*n, long int num){
	int j;
	(*n)++;
	persona[*n]=retorna_uno(num);
	persona[0]=persona[*n];
	j=(*n)-1;
	while (strcmp(persona[0].apellido,persona[j].apellido)<0)
	{
		persona[j+1]=persona[j];
		j--;
	}
	persona[j+1]=persona[0];
}

int busqueda_bin(datos persona, int n, long int buscado){
	int pos=0;
	int ini,fin,med;
	ini=1; fin=n; med=(ini+fin)/2;
	while(ini<=fin && persona[med].celular != buscado){
		if(persona[med].celular < buscado)
			ini=med++;
		else 
			fin=med--;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		pos=med;
	return pos;
}
	
	
void aniadir_uno(datos persona, int*n){
	long int num;
	printf("\ningrese un numero de celular:");
	scanf("%ld",&num);
	if(busqueda_bin(persona,*n,num)==0)
		baraja(persona, n, num);
	else 
	   printf("\nusuario ya pertenece a la lista.");
}
	
void elimina_uno(datos persona, int *n, int pos){
	int i;
	for(i=pos; i<=*n; i++)
		persona[i]=persona[i+1];
	(*n)--;
}
	
void eliminar(datos persona, int *n){
	int pos;
	tcad buscado;
	printf("\ningrese el nombre y apellido a eliminar:");
	fflush(stdin);
	leecad(buscado);
	//busqueda_bin();
hg