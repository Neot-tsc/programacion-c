#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

tptr retorna_nodo(int);
tptr carga_lista_nodo();
void actualizar_lis_nodo(tptr*);
void mostrar_lis_nodos(tptr);
void liberar_lista(tptr*);
void pila(tptr*,tptr);
void cola(tptr*,tptr);

int main(int argc, char *argv[]) {
	tptr lista;
	lista=NULL;
	lista=carga_lista_nodo();
	mostrar_lis_nodos(lista);
	actualizar_lis_nodo(&lista);
	mostrar_lis_nodos(lista);
	actualizar_lis_nodo(&lista);
	mostrar_lis_nodos(lista);
	liberar_lista(&lista);
	
	return 0;
}

tptr retorna_nodo(int n){
	tptr aux;
	aux=(tptr)malloc(sizeof(tnodo));
	aux->dato=n;
	aux->sig=NULL;
	return aux;
}
tptr carga_lista_nodo(void){
	tptr cab,nuevo;
	int n;
	do{
		printf("\ningrese un numero natural(ingrese 0 para finalizar)");
		scanf("%d", &n);
		if(n>0){
			nuevo=retorna_nodo(n);
			pila(&cab,nuevo);
		}
		else 
		   printf("\ncarga finalizada.");
		
	}while(n>0);
	
	return cab;
}
void actualizar_lis_nodo(tptr *cab){
	tptr nuevo;
	int op,r;
	printf("\ningrese (1=agregar al inicio/2=agregar al final)");
	scanf("%d", &op);
	if(op==1){
		printf("\ningrese el nuevo dato:");
		scanf("%d",&r);
		nuevo=retorna_nodo(r);
		pila(cab,nuevo);
	}
	else{
		printf("\ningrese el nuevo dato:");
		scanf("%d",&r);
		nuevo=retorna_nodo(r);
		cola(cab,nuevo);
	}
	printf("\nelemento aniadido con exito.");
}

void mostrar_lis_nodos(tptr cab){
	if(cab!=NULL){
		while(cab!=NULL){
			printf("%d,",cab->dato);
			cab=cab->sig;
		}
	}
}
	
void liberar_lista(tptr *cab){
	tptr aux;
	while(*cab != NULL){
		aux=*cab;
		*cab=(*cab)->sig;
		free(aux);
		aux=NULL;
	}
}
void pila(tptr *cab,tptr nuevo){
	nuevo->sig=*cab;
	*cab=nuevo;
}
void cola(tptr *cab,tptr nuevo){
	tptr aux;
	aux=*cab;
	while(aux->sig != NULL)
		aux=aux->sig;
	aux->sig=nuevo;
}
