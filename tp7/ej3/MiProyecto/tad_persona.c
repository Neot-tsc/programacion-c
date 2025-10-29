#include "tad_persona.h"
#include "tad_cadena.h"
#include <stdio.h>

tpersona retorna_uno(void){
    tpersona aux;
    printf("\ningrese el DNI:");
    scanf("%ld",&aux.dni);
    printf("\ningrese el apellido:");
    fflush(stdin);
    leecad(aux.apellido);
    printf("\ningrese el nombre:");
    fflush(stdin);
    leecad(aux.apellido);
    printf("\ningrese el titulo de grado:");
    fflush(stdin);  
    leecad(aux.titulo_grado);
    printf("\ningrese el curso de postgrado:"); 
    fflush(stdin);
    leecad(aux.curso_post);
    printf("\ningrese la fecha de inicio (dd mm aaaa):");
    scanf("%d %d %d",&aux.fecha_ini.dia,&aux.fecha_ini.mes,&aux.fecha_ini.anio);
    printf("\ningrese la fecha de fin (dd mm aaaa):");
    scanf("%d %d %d",&aux.fecha_fin.dia,&aux.fecha_fin.mes,&aux.fecha_fin.anio);
    printf("\ningrese el estado (1:cursando, 2:finalizado, 3:pendiente, 4:de baja):");
    scanf("%d", &aux.estado);
    return aux;
}
void muestra_uno(tpersona a){
    printf("\nDNI: %ld", a.dni);
    printf("\nApellido: %s", a.apellido);
    printf("\nNombre: %s", a.nombre);
    printf("\nTitulo de grado: %s", a.titulo_grado);
    printf("\nCurso de postgrado: %s", a.curso_post);
    printf("\nFecha de inicio: %d/%d/%d", a.fecha_ini.dia, a.fecha_ini.mes, a.fecha_ini.anio);
    printf("\nFecha de fin: %d/%d/%d", a.fecha_fin.dia, a.fecha_fin.mes, a.fecha_fin.anio);
    printf("\nEstado: %d", a.estado);
}
void modifica_datos(tpersona *a){
    printf("\ningrese el nuevo apellido:");
    fflush(stdin);
    leecad(a->apellido);
    printf("\ningrese el nuevo apelludo:");
    fflush(stdin);
    leecad(a->nombre);
    printf("\ningrese el nuevo DNI:");
    scanf("%ld",&a->dni);
    printf("\ningrese el nuevo titulo de grado:");
    fflush(stdin);  
    leecad(a->titulo_grado);
    printf("\ningrese el nuevo curso de postgrado:");
    fflush(stdin);
    leecad(a->curso_post);

}
void modifica_estado(tpersona *a){
    a->estado=4;
}

