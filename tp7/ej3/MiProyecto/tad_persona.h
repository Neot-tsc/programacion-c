#ifndef TAD_PERSONA_H
#define TAD_PERSONA_H
#include "tad_cadena.h"

typedef struct{
	int dia,mes,anio;
}tcalendario;
	
typedef struct{
	long int dni;
	tcad apellido,nombre,titulo_grado, curso_post;
	tcalendario fecha_ini, fecha_fin;
	int estado;
}tpersona;

tpersona retorna_uno(void);
void muestra_uno(tpersona);
void modifica_datos(tpersona*);
void modifica_estado(tpersona*);

#endif
