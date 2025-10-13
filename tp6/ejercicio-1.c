/*Ejercicio 1: Crear un programa que permita el ingreso de una lista de N países, 
de cada País se guarda la siguiente información: “Código del País, Nombre del país, 
Capital del país y Continente al que pertenece.”    
	Se debe realizar la carga de la lista de países y posteriormente ordenar la lista por 
Código del país, luego utilizando un menú poder realizar las siguientes operaciones:    
	a) Añadir un nuevo País preservando el orden.   
	b)Dado un Código de un país, modificar la Capital que se tiene registrada.   
	c)Dado un Código de un país, eliminar dicho registro.    
	d)Dada una Capital, mostrar el País al que pertenece.   
*/

#include <stdio.h>
#include <string.h>

#define max 50

typedef char Tcad[max];

typedef struct{
	long int codigo;
	Tcad nombre,capital,continente;
}TAD;

typedef TAD datos[max];


TAD agrega_uno();
void leecad(Tcad);
void carga_lista(datos, int*);
void ordenar(datos, int);
void mostrar_uno(TAD);
void mostrar_lista(datos, int);
int menu();
void agregar_uno(datos,TAD, int);
int busqueda_bin(datos, int, int);



//main
int main(int argc, char *argv[]) {
	datos paises;
	int n,op;
	carga_lista(paises, &n);
	ordenar(paises, n);
	do{
		op=menu();
		switch(op){
			case 1: 
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 0: 
				printf("\nsaliendo del programa...");
				break;
			default
				printf("\ningrese una opccion valida.\n");
		}
		
	}while(op!=0);
	return 0;
}



void leecad(Tcad cad){
	int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<max-1){
		cad[j]=c;
		j++;
		c=getchar();
	}
	cad[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}

	
TAD agrega_uno(){
	TAD aux;
	printf("\ningrese el codigo del pais: ");
	scanf("%ld", &aux.codigo);
	printf("\ningrese el nombre del pais:");
	fflush(stdin);
	leecad(aux.nombre);
	printf("\ningrese el nombre de la capital del pais:");
	fflush(stdin);
	leecad(aux.capital);
	printf("\ningrese el continente al que pertenece el pais:");
	fflush(stdin);
	leecad(aux.continente);
	return aux;
}

	
	
	
void carga_lista(datos pais , int*n){
	int i;
	printf("\ningrese la cantidad de paises:");
	scanf("%d", n);
	for(i=1; i<=*n; i++){
		printf("\ningrese los datos del pais %d \n", i);
		pais[i]=agrega_uno();
	}
}
	

void ordenar(datos pais, int n){
	int i,j;
	TAD aux;
	for(i=1; i<n; i++){
		for(j=i+1; j<=n; j++){
			if(pais[j].codigo<pais[i].codigo){
				aux=pais[j];
				pais[j]=pais[i];
				pais[i]=aux;
			}
		}
	}
}
	
void mostrar_uno(TAD a){
	printf("\ncodigo del pais: %ld", a.codigo);
	printf("\nnombre del pais: %s", a.nombre);
	printf("\ncapital del pais: %s", a.capital);
	printf("\ncontinente del pais: %s", a.continente);
}
	
	
void mostrar_lista(datos pais, int n){
	int i;
	printf("\n##datos de los paises ordenados##\n");
	for(i=1; i<=n; i++){
		printf("\ndatos de posision %d\n", i);
		mostrar_uno(pais[i]);
	}
}
	
	
int menu(){
	int op;
	printf("\n###main menu###\n");
	printf("\n1) agregar un nuevo pais.");
	printf("\n2) modificar la capital del pais.");
	printf("\n3) eliminar un pais.");
	printf("\n4) mostrar un pais por su capital.");
	printf("\n0) salir.");
	printf("\ningrese una opccion:");
	scanf("%d", &op);
	return op;
}
	
void agregar_uno(datos a,TAD nuevo, int pos){
	a[pos]=nuevo;
}
	
int busqueda_bin(datos a, int n, int buscado){
	int ini, fin, med, r;
	r=0;
	ini=1; fin=n; med=(ini+fin)/2;
	while(ini<=fin && a[med]!= buscado){
		if(a[med]<buscado)
			ini=med++;
		else 
			fin=med--;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		r=med;

	return r
}
