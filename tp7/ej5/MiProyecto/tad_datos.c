#include "tad_datos.h"

tdatos carga_datos(){
    tdatos aux;
    printf("Ingrese apellido: ");
    leecad(aux.apellido);
    printf("Ingrese nombre: ");
    leecad(aux.nombre);
    printf("Ingrese DNI: ");
    scanf("%ld", &aux.dni);
    printf("Ingrese saldo: ");
    scanf("%f", &aux.saldo);
    aux.fecha_operacion=carga_fecha();
    return aux;
}

void muestra_datos(tdatos a){
    printf("\nApellido: %s", a.apellido);
    printf("\nNombre: %s", a.nombre);
    printf("\nDNI: %ld", a.dni);
    printf("\nSaldo: %.2f", a.saldo);
    printf("\nFecha de operacion: ");
    muestra_fecha(a.fecha_operacion);

}

void actualiza_saldo_acreditado(tdatos*a, float nuevo){
    a->saldo=a->saldo+nuevo;
}

void actualiza_saldo_debitado(tdatos*a, float nuevo){
    a->saldo=a->saldo-nuevo;
}

long int get_dni(tdatos a){
    return a.dni;
}
void get_apellido(tcad cad, tdatos a){
    copia_cad(cad, a.apellido);
}
