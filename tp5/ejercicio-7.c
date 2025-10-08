/*Ejercicio 7: Se tienen las siguientes estructuras de datos:     
Dato Alumno, tiene la siguiente información: “Apellidos, Nombres, DNI, Fecha Nacimiento, Domicilio”   
Dato Domicilio, tiene la siguiente información: “Ciudad, Barrio, calle, Número, Departamento”  Dato 
Fecha, tiene la siguiente información: “Año, mes, día”.   
  
 Se solicita:      
a) Declarar el Tipo dato Registro para cada estructura planteada y definir una variable para cada tipo de 
registro.     
b) Utilizando las declaraciones de registros del inciso anterior, implementar los módulos para ingresar 
los datos asociados con esas estructuras y los módulos para mostrar la información guardada en los 
registros cargados.     
c) Ingresar los datos de dos alumnos utilizando los identificadores Alu1 y Alu2 y luego mostrarlos en 
orden alfabéticos según sus Apellidos */

#include <stdio.h>
#include <string.h>

#define max 50

typedef char Tcad[max];

typedef struct 
{
    int dia,mes,anio;
}calendario;

typedef struct
{
    Tcad cuidad,barrio,calle,departamento;
    int numero;
}ubicacion;

typedef struct 
{
    Tcad apeynom;
    long int DNI;
    calendario fecha;
    ubicacion domicilio;
}Dpersonales;

typedef Dpersonales datos[max];


void leecad(Tcad);
Dpersonales agrega_uno();
void genera_vector(datos, int*);
void mostrar_vector(datos, int);
void mostrar_uno(Dpersonales);


int main(void){
    datos persona;
    int n,r;
    genera_vector(persona, &n);
    mostrar_vector(persona,n);
	if(r=strcmp(persona->apeynom,persona->apeynom)<-1){
		mostrar_uno(persona[1]);
		mostrar_uno(persona[2]);
	}
	else {
		mostrar_uno(persona[2]);
		mostrar_uno(persona[1]);
	}
    return 0;
}



void leecad(Tcad cadena){
    int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<max-1){
		cadena[j]=c;
		j++;
		c=getchar();
	}
	cadena[j]='\0';
	while (c!=EOF && c!='\n')
		c=getchar();
}

Dpersonales agrega_uno(){
    Dpersonales aux;
    printf("ingrese nombre:");
	fflush(stdin);
	leecad(aux.apeynom);
	printf("ingrese el dni:");
	scanf("%ld", &aux.DNI);
	printf("ingrese el barrio donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.barrio);
    printf("ingrese la ciudad donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.cuidad);
    printf("ingrese la calle donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.calle);
    printf("ingrese el departamento donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.departamento);
    printf("ingrese el numero de casa: ");
	scanf("%d", &aux.domicilio.numero);
	printf("ingrese el dia de nacimiento: ");
	scanf("%d", &aux.fecha.dia);
	printf("ingrese el mes de nacimiento: ");
	scanf("%d", &aux.fecha.mes);
	printf("ingrese el anio de nacimiento: ");
	scanf("%d", &aux.fecha.anio);
	return aux;
}

void genera_vector(datos personales, int*n){
    int i;
    printf("\ningres el tamanio del vector:");
    scanf("%d",n);
    for (i=1; i<=*n; i++){
        printf("\ningrese los datos de la persona %d\n",i);
        personales[i]=agrega_uno();
    }
}

void mostrar_uno(Dpersonales datos){
    printf("\napellido y nombre: %s",datos.apeynom);
    printf("\nDNI: %ld", datos.DNI);
    printf("\nfecha de nacimiento: %d/%d/%d",datos.fecha.dia,datos.fecha.mes,datos.fecha.anio);
    printf("\nciudad donde vive: %s",datos.domicilio.cuidad);
    printf("\ndepartamento donde vive: %s",datos.domicilio.departamento);
    printf("\nbarrio donde vive: %s",datos.domicilio.barrio);
    printf("\ncalle donde vive: %s",datos.domicilio.calle);
    printf("\nnum de cada: %d",datos.domicilio.numero);
}

void mostrar_vector(datos datos, int n){
    int i;
    printf("\nelementos del vector");
    for (i=1; i<=n; i++){
        printf("\n\ndatos de la persona %d\n",i);
        mostrar_uno(datos[i]);
    }
}
