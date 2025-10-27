/*Ejercicio: Se tiene que administrar una lista de N alumnos de Postgrado, 
de cada alumno se lleva la siguiente información: DNI; Apellido y Nombre; Título
de grado; Curso de Postgrado; Fecha Inicio del curso de postgrado, Fecha 
Finalización del curso de postgrado; Estado (En curso, Finalizado, Pendiente,Baja).
Se solicita un programa convenientemente modularizado que implementando TADs, 
permita ingresar una lista de N alumnos de postgrado y que a través de un menú 
permita realizar las siguientes actividades:
a) Agregar un nuevo elemento a la lista de alumnos.
b) Modificar los datos de un alumno dado su DNI y el Curso de Postgrado.
c) Generar y mostrar una lista de alumnos que están cursando un Curso de Postgrado
ingresado por teclado, la lista se debe ordenar alfabéticamente por Apellido y 
Nombre.
d) Dada una fecha ingresada desde teclado, modificar el estado del registro a Baja, 
si desde la Fecha de Inicio a la fecha ingresada pasaron más de 365 días.
e) Mostrar la información de todos los alumnos de la lista
*/
#include "tad_lista.h"
void generar_mostrar_otra_ordenada(Tlista);
int menu();
int main(){
	int op; 
	Tlista ListaAlumnos;
	
	ListaAlumnos=carga_lista();
	do{
		op=menu();
		switch (op){
		case 1:
			if(retorna_tam(ListaAlumnos) < TAMV)
			  agregar(&ListaAlumnos);
			else
				printf("\nLista completa");
		    break;
		case 2:
			if(retorna_tam (ListaAlumnos)>0)
			  modificar_alumno(&ListaAlumnos);
			else
			  printf("\nLista vacia");
		    break;
		case 3:
			if(retorna_tam (ListaAlumnos)>0)
				generar_mostrar_otra_ordenada(ListaAlumnos);
			else 
			  printf("\nLista vacia");			
			break;
		case 4: 
			if(retorna_tam (ListaAlumnos)>0)
			   dar_bajas(&ListaAlumnos);
			else 
				printf("\nLista vacia");	
			break;
		case 5:
			mostrar_lista(ListaAlumnos);
			break;
		case 0: printf("\nSaliendo...");break;
		default: printf("\nOpcion incorrecta");
		 break;
		}
	} while(op !=0);	
	return 0;
}
int menu(){
	int r;
	printf("\n0: Salir");
	printf("\n1: Agregar un alumno");
	printf("\n2: Modificar datos de un alumno");
	printf("\n3: Generar y mostrar una lista de un Postgrado");
	printf("\n4: Modificar el estado Baja, si paso mas de un año");
	printf("\n5: Mostrar lista de alumnos");
	printf("\nIngrese una opción: ");
	scanf("%d",&r);
	return r;
}
void generar_mostrar_otra_ordenada(Tlista aux){
	Tlista nueva;
	nueva=generarOtra_estado(aux);
	ordenar_lista(&nueva);
	mostrar_lista(nueva);	
}
