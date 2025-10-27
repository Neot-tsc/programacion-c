#ifndef TAD_REGISTRO_H
#define TAD_REGISTRO_H
#include "tad_cadena.h"

typedef struct{
	long dni;/**/
	Tcad apenom,titulo,curso;
	int estado;/*1-2-3-4 En curso, Finalizado, Pendiente, Baja)*/
	long fIni,fFin;/**/
}Talumno;

Talumno cargar_alumno();
void mostrar_alumno(Talumno);
/*long retornar_fechaIni(Talumno);no se usa*/
long retornar_fechaFin(Talumno);
int retorna_estado(Talumno);
int compara_postgrado(Talumno, Tcad);/*Para buscar*/
int compara_apenom(Talumno,Talumno);/*Para ordenar*/
int compara_x_dni(Talumno,long);/*Para buscar*/
void modificar_estado_a_baja(Talumno*);
void modifica_registro(Talumno *);
int retornar_dni(Talumno);
#endif
