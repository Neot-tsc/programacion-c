#ifndef TAD_NUM_COMPLEJOS_H
#define TAD_NUM_COMPLEJOS_H

typedef struct{
	float a,b;
}tcomplejo;

tcomplejo carga_uno(void);
tcomplejo suma(tcomplejo, tcomplejo);
tcomplejo resta(tcomplejo, tcomplejo);
tcomplejo producto(tcomplejo, tcomplejo);
tcomplejo divicion(tcomplejo, tcomplejo);
void mostrar_uno(tcomplejo);

#endif
