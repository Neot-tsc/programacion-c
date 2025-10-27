/*Ejercicio: Se tiene que administrar una lista de N alumnos de Postgrado, 
de cada alumno se lleva la siguiente informaci�n: DNI; Apellido y Nombre; T�tulo
de grado; Curso de Postgrado; Fecha Inicio del curso de postgrado, Fecha 
Finalizaci�n del curso de postgrado; Estado (En curso, Finalizado, Pendiente,Baja).
Se solicita un programa convenientemente modularizado que implementando TADs, 
permita ingresar una lista de N alumnos de postgrado y que a trav�s de un men� 
permita realizar las siguientes actividades:
a) Agregar un nuevo elemento a la lista de alumnos.
b) Modificar los datos de un alumno dado su DNI y el Curso de Postgrado.
c) Generar y mostrar una lista de alumnos que est�n cursando un Curso de Postgrado
ingresado por teclado, la lista se debe ordenar alfab�ticamente por Apellido y 
Nombre.
d) Dada una fecha ingresada desde teclado, modificar el estado del registro a Baja, 
si desde la Fecha de Inicio a la fecha ingresada pasaron m�s de 365 d�as.
e) Mostrar la informaci�n de todos los alumnos de la lista
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
	printf("\n4: Modificar el estado Baja, si paso mas de un a�o");
	printf("\n5: Mostrar lista de alumnos");
	printf("\nIngrese una opci�n: ");
	scanf("%d",&r);
	return r;
}
void generar_mostrar_otra_ordenada(Tlista aux){
	Tlista nueva;
	nueva=generarOtra_estado(aux);
	ordenar_lista(&nueva);
	mostrar_lista(nueva);	
}
