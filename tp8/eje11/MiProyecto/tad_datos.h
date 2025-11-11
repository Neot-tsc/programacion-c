#ifndef TAD_DATOS_H
#define TAD_DATOS_H
#include "tad_cadena.h"



typedef struct 
{
    long int dni;
    tcad nombre,apellido;
    float saldo;
}datos;

datos cargar_uno(void);
void mostrar_uno(datos);
long int get_dni(datos);
float get_saldo(datos);
void sett_saldo_mas(datos*,float);
void sett_saldo_menos(datos*,float);


#endif