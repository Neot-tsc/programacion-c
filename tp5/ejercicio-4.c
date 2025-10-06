/*Ejercicio 4: Dada una frase, formada por palabras en minúsculas, que se encuentran separadas 
únicamente por espacios en blanco, se desea mostrar la palabra más larga sabiendo que existe y es 
única. Además, informar cuántas palabras conforman la frase.*/


#include <stdio.h>
#include <string.h>

#define max 100


typedef char Tcad[max];
void leecad(Tcad);
int cant_palabras(Tcad);
void palabra_mas_larga(Tcad);


int main(void){
    Tcad cadena;
    int cant;
	printf("\ningrese el parrafo:");
	fflush(stdin);
    leecad(cadena);
    printf("%s", cadena);
    cant=cant_palabras(cadena);
    printf("\nla cantidad de palabras son: %d", cant);
	fflush(stdin);
	palabra_mas_larga(cadena);
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

int cant_palabras(Tcad cadena){
    int cant, i;
    cant=0;
    for(i=0; i<max; i++){
        if(cadena[i]==' ')
            cant++;
    }
    return cant++;
}

void palabra_mas_larga(Tcad cadena){
	int i,cant,cantmay,posmay;
	cantmay=0;
	posmay=0;
	cant=0;
	for(i=0; i<strlen(cadena); i++){
		if(cadena[i]==' ' && cadena[i]!='\n')
			cant++;
		else
			if(cant>cantmay && cant>1){
				cantmay=i;
				posmay=i-cant;
				cant=0;
			}
		else 
			cant=0;
	}
	printf("\nla palabra mas larga es: ");
	for(i=posmay; i<posmay+cantmay; i++)
		printf("%c", cadena[i]);
}
