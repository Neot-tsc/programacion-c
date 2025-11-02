#ifndef TAD_CALENDARIO_H
#define TAD_CALENDARIO_H    

typedef struct 
{
    int dia;
    int mes;
    int anio;
} tfecha;

tfecha carga_fecha();
void muestra_fecha(tfecha);
int get_dia(tfecha);
int get_mes(tfecha);
int get_anio(tfecha);
void set_dia(tfecha*, int);
void set_mes(tfecha*, int); 
void set_anio(tfecha*,int);

#endif