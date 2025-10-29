#include "tad_articulo.h"
Tarticulo retorna_uno(){
	Tarticulo aux;
	printf("\ningrese el nombre del producto:");
	fflush(stdin);
	leecad(aux.nombre);
	printf("\ningrese el codigo del producto:");
	scanf("%d", &aux.codigo);
	printf("\ningrese el stok del producto:");
	scanf("%d", &aux.stok);
	printf("\ningrese el nombre del proveedor del producto:");
	fflush(stdin);
	leecad(aux.proveedor);
	printf("\ningrese el precio del procucto:");
	scanf("%f", &aux.precio);
	return aux;
}

void muestra_uno(Tarticulo a){
	printf("\ncodigo del producto: %d", a.codigo);	
	printf("\nnombre del producto:%s", a.nombre);
	printf("\nstok: %d",a.stok);
	printf("\nnombre del proveedor: %s", a.proveedor);
	printf("\nprecio actual: %f", a.precio); 
}
