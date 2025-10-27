#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define max 50

typedef char tcad[max];
typedef struct 
{
    int nro_linea;
    tcad l_parrafo;
    tcad l_parrafo_M;
    int cant_palabras;
}tdd;

typedef tdd doc[max];

void leecad(tcad);
tdd genera_uno();
void ingresa_texto(doc, int *);
void muestra_texto(doc, int);


int main(void){
    doc texto;
    int n;
	ingresa_texto(texto,&n);
    muestra_texto(texto,n);
    return 0;   
}

tdd genera_uno(){
    tdd aux;
    leecad(aux.l_parrafo);
    return aux;
}

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
    while (c!=EOF && c!='\n')
        c=getchar();
}

void ingresa_texto(doc texto, int *n){
    printf("\nIngrese la cantidad de lineas del texto: ");
    scanf("%d", n);
    fflush(stdin);
    for(int i=1; i<=*n; i++){
        texto[i]=genera_uno();
        texto[i].nro_linea=i+1;
    }
}

void muestra_texto(doc texto, int n){
    for(int i=1; i<=n; i++){
        printf("\nLinea %d: %s", texto[i].nro_linea, texto[i].l_parrafo);
    }
}