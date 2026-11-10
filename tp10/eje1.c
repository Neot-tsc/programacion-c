#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef char tcad[max];


typedef struct 
{
    tcad nombre,apellido;
    int edad;
    long int DNI;
    long int fecha_nac;
}tpersona;

typedef struct nodo{
    tpersona dato;
    struct nodo *sig, *ant;
}tnodo;

typedef tnodo *tptr;

tpersona carga_persona(long int);
