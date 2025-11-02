#include "tad_calendario.h"

tfecha carga_fecha(){
    tfecha aux;
    printf("Ingrese dia: ");
    scanf("%d", &aux.dia);
    printf("Ingrese mes: ");
    scanf("%d", &aux.mes);
    printf("Ingrese anio: ");   
    scanf("%d", &aux.anio);
    return aux;
}


void muestra_fecha(tfecha a){
    printf("\ndia: %d", a.dia);
    printf("\nmes: %d", a.mes);
    printf("\nanio: %d\n", a.anio);
}

int get_dia(tfecha a){
    return a.dia;
}

int get_mes(tfecha a){
    return a.mes;
}

int get_anio(tfecha a){
    return a.anio;
}

void set_dia(tfecha* a, int nuevo){
    a->dia=nuevo;
}

void set_mes(tfecha* a, int nuevo){
    a->mes=nuevo;
} 

void set_anio(tfecha* a,int nuevo){
    a->anio=nuevo;
}