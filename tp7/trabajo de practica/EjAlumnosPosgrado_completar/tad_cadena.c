#include "tad_cadena.h"
#include<string.h>

void leeCad(Tcad, int);

void CargaCadena(Tcad aux){
	leeCad(aux, TAM);
}
void leeCad(Tcad Texto, int tam){
	int j, m;
	j=0;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		Texto[j]=m;
		j++;
	}
	Texto[j]='\0';
	if(m != EOF && m != '\n') 
		while((m=getchar())!=EOF && m!='\n');
}
int compara_cad(Tcad c1,Tcad c2){
	int r;
	r=strcmp(c1,c2);
	return r;
}

