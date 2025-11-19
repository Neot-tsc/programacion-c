#ifndef TAD_LIBRO_H
#define TAD_LIBRO_H
#include "tad_cadena.h"
typedef struct{
    long int isbn;
    tcad nombre,tipo,referencia;
} tlibro;

//funciones y procedimientos de tipo libro

tlibro retorna_libro(long int);
void muestra_libro(tlibro);
void modifica_tipo_libro(tlibro*);
long int get_isbn(tlibro);

//fin
#endif
