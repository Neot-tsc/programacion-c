/*Ejercicio 3: Se necesitan cargar los datos de un alumno, con el siguiente orden: DNI, Apellido, Nombre 
y Fecha de Nacimiento (aaaammdd). Posteriormente mostrar los datos del alumno ingresado.*/


#include <stdio.h>
#include <string.h>

#define max 50

typedef char Tcad[max];
typedef long int Tnum[max];

typedef Tcad TlistaCad[max];
typedef Tnum TlistaNum[max];



void leecad(Tcad);
void agrega_uno(Tnum, int *, long int);                            
void cargar_elemento(TlistaNum, TlistaNum, TlistaCad, int*);
void mostrar(TlistaNum, TlistaNum, TlistaCad, int);

int main(void){
    TlistaCad nomyape;
    TlistaNum dni, fecha;
    int n;
    n=0;
    cargar_elemento(dni,fecha,nomyape,&n);
    mostrar(dni, fecha, nomyape, n);
    return 0;
}

void leecad(Tcad cadena){
    char c;
    int j;
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

void agrega_uno(Tnum a, int *n, long int nuevo){
    int i;
    i=*n;
    a[0]=nuevo;
    while(a[i]>nuevo){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=nuevo;
    (*n)++;
}       
void cargar_elemento(TlistaNum dni, TlistaNum fecha, TlistaCad nomyape, int*n){
    long int nuevo;
    printf("\ningrese el dni: ");
    scanf("%ld", &nuevo);
    agrega_uno(dni, n, nuevo);
    printf("\ningrese el apelido y el nombre: ");
    leecad(nomyape[*n+1]);
    printf("\ningrese la fecha de nacimiento: ");
    scanf("%ld",&nuevo);
    agrega_uno(fecha, n,nuevo);
}


void mostrar(TlistaNum dni, TlistaNum fecha, TlistaCad nomyape, int n){
    int i;
    for ( i = 1; i <=n; i++)
    {
        printf("\npersona %d", i);
        printf("\nnombre y apellido %s", nomyape[i]);
        printf("\ndni: %ld", dni[i]);
        printf("\nfecha: %ld", fecha[i]);
    } 
}