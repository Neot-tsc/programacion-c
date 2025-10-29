#include "tad_num_complejos.h"
#include <stdio.h>
#include <math.h>

tcomplejo carga_uno(void){
	tcomplejo aux;
	printf("\ningrese el numero complejo(a+b.i):");
	printf("\ningrese a:");
	scanf("%f",&aux.a);
	printf("\ningrese b:");
	scanf("%f",&aux.b);
	return aux;
}
	
tcomplejo suma(tcomplejo A, tcomplejo B){
	tcomplejo aux;
	aux.a=(A.a+B.a);
	aux.b=(A.b+B.b);
	return aux;
}
tcomplejo resta(tcomplejo A , tcomplejo B){
	tcomplejo aux;
	aux.a=(A.a-B.a);
	aux.b=(A.b-B.b);
	return aux;
}
tcomplejo producto(tcomplejo A, tcomplejo B){
	tcomplejo aux;
	aux.a=((A.a*B.a)-(A.b*B.b));
	aux.b=((A.a*B.b)+(A.b*B.a));
	return aux;
}
tcomplejo divicion(tcomplejo A, tcomplejo B){
	tcomplejo aux;
	aux.a=(((A.a*B.a)-(A.b*B.b))/((B.a*B.a)+(B.b*B.b)));
	aux.b=(((B.a*A.b)-(A.a*B.b))/((B.a*B.a)+(B.b*B.b)));
	return aux;
}
void mostrar_uno(tcomplejo A){
	printf("\nnumero resultante: %f+%f .i", A.a, A.b);
}

























