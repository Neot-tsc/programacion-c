/*Ejercicio 4: Una academia de danzas tiene una lista de alumnos, registrando de cada alumno los siguientes datos:
 “DNI del alumno, Apellido y Nombre del alumno, Código de curso de verano ([1] folclore, [2] español, [3] contemporáneo)”.    
Crear un programa que permita cargar la lista de alumnos, inicializando el campo Código de curso en 0. 
Luego ordene la lista por DNI del alumno utilizando el método de la Burbuja. Posteriormente, a través de un menú realizar 
las siguientes tareas:   
a) Agregar un alumno a la lista.   
b)Dado el DNI de un alumno inscribirlo a uno de los 3 cursos que se dictan, teniendo en cuenta que el cupo es de 10 personas para cada curso. Un alumno sólo puede estar inscripto en un curso a la vez.   
c)Permitir dar de baja a un alumno de un curso ingresando su DNI. (Cambiar Código a 0)   
d)Eliminar de la lista todos los alumnos que no se encuentren inscriptos en algún curso.   
Dado un Código de curso, mostrar la lista de inscriptos.*/

#include <stdio.h>
#include <string.h>
#define max 50

typedef char Tcad [max];

typedef struct 
{
    long int dni;
    Tcad nombre, apellido;
    int curso;
}tdd;

typedef tdd datos[max];
tdd carga_uno();
void cargar_lista(datos, int*);
void leecad(Tcad);


int main(void){
    datos alumno;
    int n;

    return 0;
}

tdd carga_uno(){
    tdd aux;
    printf("\ningrese el nombre del alumno:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el apellido del alumno:");
    fflush(stdin);
    leecad(aux.apellido);
    printf("\ningrese el dni: ");
    scanf("%ld", &aux.dni);
    aux.curso=0;
    return aux;
}

void leecad(Tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while(c!=EOF && c!='\n' && j>max-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while(c!=EOF && c!='\n')
        c=getchar();
}

void cargar_lista(datos persona, int *n){
    *n=0;
    
}