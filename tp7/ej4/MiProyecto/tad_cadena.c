#include "tad_cadena.h"


void leecad(tcad cad){
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

int compara_cadenas(tcad a, tcad b){
	int r;
	if(strcmp(a,b)>0)
		r=1;
	else if (strcmp(a,b)<0)
		r=-1;
	else
		r=0;
	return r;
}
int tam_cad(tcad a){
	int cant;
	cant=strlen(a);
	return cant;	
}