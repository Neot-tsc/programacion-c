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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define max 50
#define cmax 50

typedef char tcad[cmax];

typedef struct 
{
    long long int celular, dni;
    tcad estado;
    int edad;
}tdatos;

typedef tdatos miembros[max];

void leecad(tcad);
tdatos genera_uno();
void cargar_lista(miembros, int*);
void mostrar(miembros, int);
void mostrar_uno(tdatos);
int busqueda_bin(miembros, int);
void eliminar(miembros, int*);
void elimina_uno(miembros, int*, int);
void insertar(miembros, int*);
void insertar_uno(miembros, int*, int, tdatos);
void mostrar(miembros, int);
void mostrar_uno(tdatos);

int main(){



    return 0;
}


void leecad(tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while(c!=EOF && c!='\n' && j>cmax-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while(c!=EOF && c!='\n')
        c=getchar();
}

tdatos genera_uno(){
    //cel dni estado edad 
    tdatos nuevo;
    printf("\ningrese el dni del miembro:");
    scanf("%lld", &nuevo.dni);
    printf("\ningrese el celular del miembro:");
    scanf("&lld", &nuevo.celular);
    printf("\ningrese el estado del usuario (soltero, casado, viudo, separado):");
    fflush(stdin);
    leecad(nuevo.estado);
    printf("\ningrese la edad del miebro:");
    scanf("%d", &nuevo.edad);
    return nuevo;
}

void cargar_lista(miembros, int*);
void mostrar(miembros, int);
void mostrar_uno(tdatos);
int busqueda_bin(miembros, int);
void eliminar(miembros, int*);
void elimina_uno(miembros, int*, int);
void insertar(miembros, int*);
void insertar_uno(miembros, int*, int, tdatos);
void mostrar(miembros, int);
void mostrar_uno(tdatos);
