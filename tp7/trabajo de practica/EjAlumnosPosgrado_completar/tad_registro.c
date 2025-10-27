#include "tad_registro.h"
void mostrar_estado(Talumno aux);

Talumno cargar_alumno(){
	Talumno aux;
	printf("Ingrese dni: ");
	scanf("%ld",&aux.dni);
	printf("Ingrese nombre y apellido: ");
	fflush(stdin);
	CargaCadena(aux.apenom);
	printf("Ingrese titulo: ");
	fflush(stdin);
	CargaCadena(aux.titulo);
	printf("Ingrese curso: ");
	fflush(stdin);
	CargaCadena(aux.curso);	
	printf("Ingrese Estado: ");
	scanf("%d",&aux.estado);
	printf("Ingrese fecha de inicio AAAAMMDD: ");
	scanf("%ld",&aux.fIni);/**/
	printf("Ingrese fecha de fin AAAAMMDD: ");
	scanf("%ld",&aux.fFin);/**/
	return aux;	
}
	
void mostrar_alumno(Talumno aux){
	printf("\n-------------------");
	printf("\nDNI: %ld",aux.dni);
	printf("\nTITULO: %s",aux.titulo);
	printf("\nAPELLIDO Y NOMBRE: %s",aux.apenom);
	printf("\nTITULO: %s",aux.titulo);
	printf("\nCURSO: %s",aux.curso);	
	printf("\nESTADO:");
	mostrar_estado(aux);
	printf("\nINICIO: %ld",aux.fIni);	
	printf("\nFIN: %ld",aux.fFin);
	printf("\n-------------------");
}
void mostrar_estado(Talumno aux){
	switch (aux.estado){
	case 1:	printf("\n POSGRADO EN CURSO");
			break;
	case 2:	printf("\n POSGRADO FINALIZADO");
			break;
	case 3:	printf("\n POSGRADO PENDIENTE");
			break;
	case 4:	printf("\n POSGRADO DADO DE BAJA");
			break;
	}
}
	
long retornar_fechaFin(Talumno aux){
	return aux.fFin;
}
	
int retorna_estado(Talumno aux){
		return aux.estado;
}
int compara_x_dni(Talumno aux, long doc){
    int r;
	if(aux.dni>doc) r=1;
	 else if(aux.dni==doc) r=0;
		  else r=-1;
	return r;
}
int compara_postgrado(Talumno aux, Tcad c){
	int r;
	r=compara_cad(aux.curso,c);
	return r;
}

int compara_apenom(Talumno r1,Talumno r2){
	int rdo;
	rdo=compara_cad(r1.apenom,r2.apenom);
	return rdo;
}

	
void modifica_registro(Talumno *aux){ /* modifica todos los campos menos dni y curso*/	
	printf("Ingrese nuevo nombre y apellido: ");
	fflush(stdin);
	CargaCadena(aux->apenom);	
	printf("Ingrese nuevo titulo: ");
	fflush(stdin);
	CargaCadena(aux->titulo);
	printf("Ingrese nuevo Estado: ");
	scanf("%d",&aux->estado);
	printf("Ingrese nueva fecha de inicio AAAAMMDD: ");
	scanf("%ld",&aux->fIni);
	printf("Ingrese nueva fecha de fin AAAAMMDD: ");
	scanf("%ld",&aux->fFin);
}
	
void modificar_estado_a_baja(Talumno* aux){
	aux->estado=4;
}
	
int retornar_dni(Talumno aux){
	return (aux.dni);
}

