#include "TAD_CUENTAS_H"



tcuenta cargar(){
	tcuenta aux;
	printf("\ningrese el numero de cuenta:");
	scanf("%d", &aux.numero);
	printf("\ningrese el dni:");
	scanf("%ld", aux.dni);
	aux.saldo=0;
}
	
void mostrar_cuenta(tcuent a){
	printf("\nnumero de cuenta: %d",a.numero);
	printf("\nDNI: %ld", a.dni);
	printf("\nsaldo disponible: %f", a.saldo);
}
	

