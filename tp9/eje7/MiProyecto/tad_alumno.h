#ifndef TAD_ALUMNO_H
#define TAD_ALUMNO_H
#include <stdio.h>
#include "tad_cadena.h"

typedef struct{
    long int dni;
    tcad nombre,apellido;
    int condicion;  //1=regular 2=libre
} talumno;  

//funciones y procedimientos de talumno
talumno retorna_alumno(long int);
void mostrar_alumno(talumno);
long  int get_dni(talumno);
int compara_dni_alumno(long int, long int);
int get_condicion(talumno);


//fin

#endif