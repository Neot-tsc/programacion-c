#include <stdio.h>
#include <string.h>

#define max 50

typedef char Tcad [max];
typedef Tcad Lista_cad [max];
typedef long int Tlista [max];

void leecad(Tcad);
void intercambio(Tcad, Tcad, Tcad, Tcad);

int main(int argc, char *argv[]) {
	Tcad nombre1, apellido1, nombre2, apellido2;
	int i;
	printf("\ningrese el nombre: ");
	fflush(stdin);
	leecad(nombre1);
	printf("\ningrese el apellido: ");
	fflush(stdin);
	leecad(apellido1);
	printf("\ningrese el nombre: ");
	fflush(stdin);
	leecad(nombre2);
	printf("\ningrese el apellido: ");
	fflush(stdin);
	leecad(apellido2);
	if(i=strcmp(nombre1,nombre2)<0){
		printf("\n%s %s", nombre1,apellido1);
		printf("\n%s %s", nombre2,apellido2);
	}
	else {
		printf("\n%s %s", nombre2,apellido2);
		printf("\n%s %s", nombre1,apellido1);
	}
	intercambio(nombre1, apellido1, nombre2, apellido2);
	printf("\nnombre y apellido 1 : %s %s", nombre1,apellido1);
	printf("\nnombre y apellido 2 : %s %s", nombre2,apellido2);
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
	
void intercambio(Tcad nom1, Tcad ape1, Tcad nom2, Tcad ape2){
	Tcad aux1, aux2;
	strcpy(aux1, nom1);
	strcpy(aux2,ape1);
	strcpy(nom1, nom2);
	strcpy(ape1,ape2);
	strcpy(nom2, aux1);
	strcpy(ape2, aux2);
	
}
