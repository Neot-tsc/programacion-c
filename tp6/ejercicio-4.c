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

//funciones y procedimientos


typedef tdd datos[max];
tdd carga_uno();
void cargar_lista(datos, int*);
void leecad(Tcad);
void ordenamiento_burbuja(datos, int);
int menu();
//main 


int main(void){
    datos alumno;
    int n,folk,esp,cont,op;
    folk=0; esp=0; cont=0;
    cargar_lista(alumno, &n);
    ordenamiento_burbuja(alumno, n);
    do
    {
        op=menu();
        switch (op){
            case 1:
                if(n<max){
                    n++;
                    alumno[n]=carga_uno();
                    ordenamiento_burbuja(alumno, n);
                }
                else
                    printf("\nlista llena.");
                break;
        }
    } while (op!=0);
    
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
    int op;
    do
    {
        printf("\nDesea cargar un alumno? (1=si/0=no):");
        scanf("%d", &op);
        if(op==1 && *n<max){
            (*n)++;
            persona[*n]=carga_uno();
        }
        else
            if(*n>=max)
                printf("\nlista llena.");
            else
                
            printf("\ningrese una opcion valida.");
    } while (op!=0);
    printf("\ncarga finalizada.");
}

void ordenamiento_burbuja(datos a, int n){
    int i,j;
    tdd aux;
    for (i=1; i < n; i++)
    {
        for(j=n; j>i; j--){
            if(a[j].dni < a[j-1].dni){
                aux=a[j];
                a[j]=a[j-1];
                a[j-1]=aux;
            }
        }
    }
}
int menu(){
    int op;
    printf("\n------Menu------\n");
    printf("\n1) Agregar un alumno a la lista.");   
    printf("\n2) suscribir un alumno.");
    printf("\n3) dar de baja de un curso.");  
    printf("\n4) seliminar los alumnos no inscripctos.");
    printf("\n0) salir."); 
    printf("\ningrese una opcion: ");
    scanf("%d",&op);
    return op;
}