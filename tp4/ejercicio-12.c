/*Ejercicio  12:  Se  requiere  cargar  la  información  asociada  a  M  miembros  de  una  institución 
deportiva,  la  información  de  cada  miembro  es:  DNI,  Celular,  Estado  (C:  casado,  S:  soltero,  V: 
viudo, W: separado), Edad.    
Se solicita un programa modular que permita cargar la lista de miembros de la institución y que la 
misma se ordene por el campo DNI, a medida que se ingresan los miembros. Luego presente un 
menú de opciones que permita las siguientes operaciones:    
a) Dado un DNI, determinar si este se encuentra en la lista de miembros cargados.    
b) Eliminar un miembro de la lista, ingresando por teclado su DNI.    
c) Agregar un nuevo miembro a la lista.    
d) Dado un estado ingresado por teclado, mostrar la información de los registros que sean iguales al 
estado solicitado.    
e) Mostrar la lista de miembros. */

#include <stdio.h>
/*defino tamanio maximo*/
#define max 50

/*defino los tipos de arreglos que usara el prgrama*/
typedef int Tlista[max];
typedef char Tchar[max];

/*cabecera de funciones y procedimientos*/

void ingreso_baraja(Tlista, Tlista, Tlista, Tchar, int*);


/*inicio del main*/

int main (void){
    Tlista dni, celular, edad;
    Tchar estado;




    return 0;
}

/*cuerpo de funciones y procedimientos*/

void ingreso_baraja(Tlista a, Tlista b, Tlista c, Tchar e, int* n){
    *n=1;
    
}