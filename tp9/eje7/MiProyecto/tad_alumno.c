#include "tad_alumno.h"

//funciones y procedimientos de talumno
talumno retorna_alumno(long int n){
    talumno aux;
    aux.dni=n;
    printf("\ningrese el apellido del alumno:");
    fflush(stdin);
    leecad(aux.apellido);
    printf("\ningrese el nombre del alumno:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese la condicion del alumno (1=regular/2=libre):");
    scanf("%d", &aux.condicion);
    return aux;
}

void mostrar_alumno(talumno a){
    printf("\napellido y nombre del alumno: %s %s", a.apellido,a.nombre);   
    printf("\ndni del alumno: %ld", a.dni);
    printf("\ncondicion del alumno: %d", a.condicion);
}

long  int get_dni(talumno a){
    return a.dni;
}

int compara_dni_alumno(long int a, long int b){
    int r;
    if(a>b)
        r=1;
    else{
        if(a<b)
            r=-1;
        else
            r=0;
    }
    return r;
}

int get_condicion(talumno a){
    return a.condicion;
}


//fin