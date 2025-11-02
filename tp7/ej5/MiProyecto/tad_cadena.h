#ifndef TAD_CADENA_H
#define TAD_CADENA_H
#include <stdio.h>
#include <string.h>
#define max 50

typedef char tcad [max];

void leecad(tcad);
int compara_cad(tcad, tcad);
void copia_cad(tcad, tcad);
int cant_caracteres(tcad);



#endif