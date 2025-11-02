#ifndef TAD_DATOS_H
#define TAD_DATOS_H
#include "tad_cadena.h"
#include "tad_calendario.h"
#include <stdio.h>



typedef struct 
{
    tcad apellido, nombre;
    long int dni;
    float saldo;
    tfecha fecha_operacion;
}tdatos;

tdatos carga_datos();
void muestra_datos(tdatos);
void actualiza_saldo_acreditado(tdatos*, float);
void actualiza_saldo_debitado(tdatos*, float);
long int get_dni(tdatos);
void get_apellido(tcad, tdatos);





#endif
