#include <stdio.h>
#define pi 3.14
#define SxH 1500

/*jercicio  3 a y b: perimetro y area de un rectangulo y circulo
int main (void){
    int ladA, ladB, perimetroRec, areaRec;
    float radio, perimetroCir, areaCir;
    printf("\ningrese el lado menor del rectangulo:");
    scanf("%d", &ladA);
    printf("\ningrese el lado mator del rectangulo:");
    scanf("%d", &ladB);
    printf("\ningrese el radio del circulo:");
    scanf("%f", &radio);
    perimetroRec=2*(ladB+ladA);
    areaRec=ladB*ladA;
    perimetroCir=2*pi*radio;
    areaCir=pi*radio*radio;
    printf("\nel perimetro del rectangulo es:%d, y su area es:%d", perimetroRec, areaRec);
    printf("\nel area del circuo es :%f, y su perimetro es:%f", areaCir, perimetroCir);
    return 0;
}

/*Dada la cantidad de horas que trabaja un obrero por día y el valor de la hora trabajada
    indicar el importe que debe cobrar en el mes. Considerar que el mes tiene 30 días y que los días
    feriados y fines de semana se pagan como días laborales
    
    datos a tener en cuenta 
    trbajo por hora=1500  DEFINIDA COMO VARIABLE GLOVAL*/



int main (void){

    float Hxdias, sueldo;
    printf("\ningrese la cantidad de horas de trabajo al dia (formato 24.00hrs):");
    scanf("%f", &Hxdias);
    sueldo=Hxdias*30*SxH;
    printf("\nsu sueldo a cobrar es de :%f", sueldo);


    return 0;
}