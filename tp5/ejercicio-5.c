/*Ejercicio 5: Se tiene una lista de N ciudades de la argentina que se desea ingresar, a continuación, se 
solicita ordenar alfabéticamente la lista. A través de un menú, realizar las siguientes operaciones:    
a) Mostrar  cuántos  nombres  de  ciudades  están  formadas  con  una  misma  vocal,  como  en  el  caso  de  la 
ciudad “Salta”;     
b) Dada una ciudad, determinar la posición en la que se encuentra dentro de la lista   
c) Mostrar toda la lista.*/

#include <stdio.h>
#include <string.h>
#define max 50

typedef char Tcad[max];
typedef Tcad cadena[max];

void leecad(Tcad);
void cargar_lista(cadena,int*);
void agregar_uno(cadena, int);
void mostrar_lista(cadena, int);
void ordenar_lista(cadena,int);


int main (void){
    cadena ciudades;
    int n;
    cargar_lista(ciudades, &n);
    ordenar_lista(ciudades,n);
    mostrar_lista(ciudades, n);

    return 0;
}

void leecad(Tcad cadena){
    char c;
    int j;
    j=0;
    c=getchar();
    while(c!=EOF && c!='\n'&& j<max-1){
        cadena[j]=c;
        j++;
        c=getchar();
    }
    cadena[j]='\0';
    while (c!=EOF && c!='\n')
        c=getchar();
}

void cargar_lista(cadena nuevo,int*n){
    Tcad aux;
    int i;
    printf("\ningres el tamanio de la lista: ");
    scanf("%d", n);
    for ( i=1; i<=*n; i++)
    {
        printf("\ningrese eel nombre de la ciudad de argentina: ");
        fflush(stdin);
        leecad(aux);
        strcpy(nuevo[i],aux);
    }
}

void mostrar_lista(cadena ciudades, int n){
    int i;
    printf("\ncontenido del vector:\n");
    for (i=1; i<=n; i++)
       printf("\n%s",ciudades[i]);
}

void ordenar_lista(cadena nombres,int n){
    Tcad aux;
    int i,j,r;
    for (i=1; i<n; i++)
    {
        for (j=i+1; j<=n; j++)
        {
            if ((r=strcmp(nombres[j],nombres[i]))==-1)
            {
                strcpy(aux,nombres[j]);
                strcpy(nombres[j],nombres[i]);
                strcpy(nombres[i],aux);
            }  
        }   
    } 
}