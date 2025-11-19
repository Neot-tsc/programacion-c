#ifndef TAD_ARTICULO_H
#define TAD_ARTICULO_H
#include "tad_cadena.h"
#include <stdio.h>

typedef struct{
    long int codigo;
    tcad nombre;
    int stok;
    float precio;
}tarticulo;

//funciones de tarticulo
tarticulo retorna_articulo(long int);
void mostrar_articulo(tarticulo);
void modifica_cod_art(tarticulo*);
int compara_nom_art(tarticulo, tarticulo);
int compara_cod_art(tarticulo,tarticulo);
long int get_codigo(tarticulo);
int get_stok(tarticulo);
float get_precio(tarticulo);

//fin

#endif