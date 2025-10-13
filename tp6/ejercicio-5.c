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
	int dia,mes,a�o;
}calendario;

typedef struct{
	tcad apellido, nombre,direccion;
	long int celular;
	calendario fecha;
}Persona;

void carga_listaOR();
void mostrar_menu();

int main(int argc, char *argv[]) {
	
	return 0;
}

;
