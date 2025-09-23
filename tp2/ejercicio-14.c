/*Ejercicio 14: 
Dadas N fechas ingresadas por el usuario, para cada una de ellas generar al azar una 
fecha mayor a ésta y luego mostrar la cantidad de días transcurridos entre la fecha ingresada y la fecha 
generada al azar. También mostrar la cantidad promedio de días transcurridos entre el total de los pares 
de fecha.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Manio 10
#define Mmes 12
#define Mdias 31
#define ANIO 360

int Randomdia(int);


int main (void){
    int n, dia,mes,anio, i, dd,mm,aa;
    printf("\nIngrese la cantidad de fechas a procesar: ");
    scanf("%d",&n);
    for ( i=1; i <=n ; i++)
    {
        printf("/ingrese el dia:");
        scanf("%d",&dia);
        printf("/ingrese el mes:");
        scanf("%d",&mes);   
        printf("/ingrese el anio:");
        scanf("%d",&anio);

    }
    

    return 0;
}