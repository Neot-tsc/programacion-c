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
/*definiciones globales*/
typedef char tcad[max];

typedef struct{
	int dia,mes,anio;
}calendario;

typedef struct{
	tcad ape,nom,direccion;
	long int celular;
	calendario fecha;
}tad;

typedef tad datos[max];


/*declaraciones de funciones y prototipos de strct tad*/
tad retorna_uno(tcad, tcad);

/*declaraciondes de funciones y procedimientos del arreglo datos*/
void ingreso(datos ,int*);
void baraja(datos, int*, tcad, tcad);
void mostrar_uno(tad);
void mostrar_todo(datos, int);
void leecad(tcad);
void aniadir_uno(datos, int*);
int busqueda_bin(datos, int, tcad,tcad); 
void elimina_uno(datos, int*, int);
void eliminar(datos, int*);
void modifica_telefono(datos, int);
void modifica_direccion(datos, int);
void mostrar_por_apellido_uno(datos,int);
void mostrar_por_apellido_todos(datos,int);
void mostrar_por_mes(datos, int);
int busqueda_bin_ape(datos, int, tcad);
int menu();



//inicio del main
int main(void) {
	datos persona;	
	tcad buscadoape, buscadonom;
	int n, op,pos;
	ingreso(persona,&n);
	do
	{
		op=menu();
		switch (op)
		{
		case 1:
			aniadir_uno(persona, &n);
			printf("\ncontacto aniadido correctamente.");
			break;
		case 2:
			eliminar(persona,&n);
			break;
		case 3:
			printf("\ningrese los datos del usuario a modificar su direccion:");
			printf("\ningrese el apellido:");
			fflush(stdin);
			leecad(buscadoape);
			printf("\ningrese el nombre:");
			fflush(stdin);
			leecad(buscadonom);
			pos=busqueda_bin(persona,n,buscadoape,buscadonom);
			if(pos!=0)
				modifica_direccion(persona,pos);
			else
				printf("\nusuario no existe en la lista");
			break;
		case 4:
			printf("\ningrese los datos del usuario a modificar su telefono:");
			printf("\ningrese el apellido:");
			fflush(stdin);
			leecad(buscadoape);
			printf("\ningrese el nombre:");
			fflush(stdin);
			leecad(buscadonom);
			pos=busqueda_bin(persona,n,buscadoape,buscadonom);
			if(pos!=0)
				modifica_telefono(persona,pos);
			else
				printf("\nusuario no existe en la lista");
			break;
			modifica_telefono(persona, n);
			break;
		case 5:
			mostrar_por_apellido_uno(persona,n);
			break;
		case 6:
			mostrar_por_apellido_todos(persona,n);

			break;
		case 7:
			mostrar_por_mes(persona,n);
			break;
		case 8:
			mostrar_todo(persona,n);
			break;
		case 0:
			printf("\nsaliendo del programa");
			break;
		default:
			printf("\ningrese un opcion valida.");
		}
	} while (op!=0);
	
	return 0;
}




tad retorna_uno(tcad nuevoape, tcad nuevonom){
	tad aux;
	strcpy(aux.ape,nuevoape);
	strcpy(aux.nom,nuevonom);
	printf("\ningrese el celular del usuario:");
	scanf("%ld",&aux.celular);
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
	printf("\napellido y nombre: %s %s",datos.ape, datos.nom);
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
	tcad nuevoape, nuevonom;
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
				printf("\ningree el apellido:");
				fflush(stdin);
				leecad(nuevoape);
				printf("\ningree el nombre:");
				fflush(stdin);
				leecad(nuevonom);
				baraja(persona,n,nuevoape,nuevonom);
			break;
			case 0:
				printf("ingreso terminado.");
			break;
			default:
				printf("\ningrese un opccion valida.");
		}
	} while (op!=0);
}

void baraja(datos persona, int*n, tcad nuevoape, tcad nuevonom){
	int j;
	(*n)++;
	persona[*n]=retorna_uno(nuevoape,nuevonom);
	persona[0]=persona[*n];
	j=(*n)-1;
	while (strcmp(persona[0].ape,persona[j].ape)<0)
	{
		persona[j+1]=persona[j];
		j--;
	}
	persona[j+1]=persona[0];
}

int busqueda_bin(datos persona, int n, tcad buscadoape, tcad buscadonom){
	int ini,fin,med,pos;
	ini=1; 
	fin=n; 
	med=(ini+fin)/2;
	pos=0;
	while(ini<=fin && strcmp(persona[med].ape,buscadoape)!=0 && strcmp(persona[med].ape,buscadonom)!=0){
		if(strcmp(persona[med].ape,buscadoape)<0 && strcmp(persona[med].nom,buscadonom)<0)
			ini=med+1;
		else 
			fin=med-1;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		pos=med;
	return pos;
}
	
	
void aniadir_uno(datos persona, int*n){
	tcad nuevoape, nuevonom;
	printf("\ningrese el apellido:");
	fflush(stdin);
	leecad(nuevoape);
	printf("\ningrese el nuembre:");
	fflush(stdin);
	leecad(nuevonom);
	baraja(persona, n, nuevoape, nuevonom);
}
	
void elimina_uno(datos persona, int *n, int pos){
	int i;
	for(i=pos; i<=*n; i++)
		persona[i]=persona[i+1];
	(*n)--;
}
	
void eliminar(datos persona, int *n){
	int pos;
	tcad nuevoape, nuevonom;
	printf("\ningrese el apellido:");
	fflush(stdin);
	leecad(nuevoape);
	printf("\ningrese el nuembre:");
	fflush(stdin);
	leecad(nuevonom);
	pos=busqueda_bin(persona,*n,nuevoape, nuevonom);
	if(pos!=0){
		elimina_uno(persona,n,pos);
		printf("\nusuario eliminado correctamente");
	}
	else
	   printf("\nno eexiste un usuario con ese nombre y apellido");
}

void modifica_telefono(datos persona, int pos){
	long int nuevo;
	printf("\ningrese el nuevo telefono: ");
	scanf("%ld", &nuevo);
	persona[pos].celular=nuevo;
	printf("\nmodificacion exitosa");
}

void modifica_direccion(datos persona, int pos){
	tcad nuevo;
	printf("\ningrese la nueva direccion: ");
	fflush(stdin);
	leecad(nuevo);
	strcpy(persona[pos].direccion,nuevo);
	printf("\nmodificacion exitosa");
}

void mostrar_por_apellido_uno(datos persona, int n){
	int pos;
	tcad nuevoape, nuevonom;
	printf("\ningrese los datos a buscar");
	printf("\ningrese el apellido:");
	fflush(stdin);
	leecad(nuevoape);
	printf("\ningrese el nombre:");
	fflush(stdin);
	leecad(nuevonom);
	pos=busqueda_bin(persona,n,nuevoape, nuevonom);
	if(pos!=0)
		mostrar_uno(persona[pos]);
	else 
		printf("\napellido y nombre no encontrados.");
}

void mostrar_por_mes(datos persona, int n){
	int buscado,ban,i;
	ban=0;
	printf("\ningrese el mes a buscar (1-12):");
	scanf("%d",&buscado);
	for(i=1; i<=n; i++){
		if(persona[i].fecha.mes==buscado){
			mostrar_uno(persona[i]);
			ban=1;
		}
	}
	if(ban==0)
		printf("\nno se encontro un usuario con el mes ingresado.");
}


int menu(){
	int op;
	printf("\n##  MENU  ##\n");
	printf("\n1) aniadir un nuevo contacto.");
	printf("\n2) eliminar un contacto.");
	printf("\n3) modificar direccion.");
	printf("\n4) modificar telefono.");
	printf("\n5) mostrar datos de un contacto.");
	printf("\n6) mostrar contactos con mismo apellido.");
	printf("\n7) mostrar personas que cumplen anio el mismo mes.");
	printf("\n8) mostrar toda la lista de contactos.");
	printf("\n0) salir del programa.");
	printf("\nseleccione una opcion: ");
	scanf("%d",&op);
	return op;
}

void mostrar_por_apellido_todos(datos persona,int n){
	int i,ban;
	ban=0;
	tcad buscado;
	printf("\ningreselos datos a buscar");
	printf("\ningrese el apellido:");
	fflush(stdin);
	leecad(buscado);
	for ( i=1; i <=n; i++)
	{
		if(strcmp(persona[i].ape,buscado)==0){
			mostrar_uno(persona[i]);
			ban=1;
		}
	}
	if(ban==0)
		printf("\nno se a encontrado un usuario con el nombre y apellido ingresado.");
}	


int busqueda_bin_ape(datos persona, int n, tcad buscadoape){
	int ini,fin,med,pos;
	ini=1; 
	fin=n; 
	med=(ini+fin)/2;
	pos=0;
	while(ini<=fin && strcmp(persona[med].ape,buscadoape)!=0){
		if(strcmp(persona[med].ape,buscadoape)<0)
			ini=med+1;
		else 
			fin=med-1;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		pos=med;
	return pos;
}