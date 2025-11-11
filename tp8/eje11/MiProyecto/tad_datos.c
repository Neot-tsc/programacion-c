#include "tad_datos.h"

datos cargar_uno(void){
    datos aux;
    printf("\ningrese el apellio del cliente:");
    fflush(stdin);
    leecad(aux.apellido);
    printf("\ningrese el nombre del cliente:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el DNI:");
    scanf("%ld",&aux.dni);
    printf("\ningrese el saldo de la cuenta:");
    scanf("%f", &aux.saldo);
    return aux;
}


void mostrar_uno(datos a){
    printf("\napellido y nombre: %s %s", a.apellido,a.nombre);
    printf("\nDNI:%ld", a.dni);
    printf("\nsaldo: %f", a.saldo);
}

long int get_dni(datos a){
    return a.dni;
}
float get_saldo(datos a){
    return a.saldo;
}

void sett_saldo_mas(datos *a, float nuevo){
    a->saldo=a->saldo+nuevo;
}

void sett_saldo_menos(datos *a,float nuevo){
    a->saldo=a->saldo-nuevo;
}