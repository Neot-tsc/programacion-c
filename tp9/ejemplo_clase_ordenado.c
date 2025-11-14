#include <stdio.h>
#include <stdlib.h>

/*typedef struct{*/
/*	long int dni;*/
/*	tcar nombre;*/
/*	int edad;*/
/*}td;*/


typedef struct nodo{
	/*td dato1;*/
	int dato;
	struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

tptr retorna_nodo(int);
void cargar_lista_nodos(tptr*);
void agrega_pila(tptr*, tptr);
void agrega_cola(tptr*,tptr);
void cola_segura(tptr*, tptr);
void cola(tptr *,tptr);/* nueva: inserta al final de forma segura sin modificar cola() */
tptr desencolar(tptr *cabeza);
void mostrar_lista_nodos(tptr);
void inserta_ordenado(tptr*,tptr);
void inserta(tptr*);


int main(int argc, char *argv[]) {
	tptr lista;
	lista=NULL;
	cargar_lista_nodos(&lista);
	mostrar_lista_nodos(lista);
	inserta(&lista);
	mostrar_lista_nodos(lista);
	return 0;
}



tptr retorna_nodo(int n){
	tptr aux;
	aux=(tptr)malloc(sizeof(tnodo));
	aux->dato=n;
	aux->sig=NULL;
	return aux;
}
	
void cargar_lista_nodos(tptr *cabeza){
	tptr nuevo;
	int op,x;
	do{
		printf("\n agregar un nuevo nodo (1=si/0=no)");
		scanf("%d", &op);
		if(op!=0){
			printf("\ningrese el dato:");
			scanf("%d",&x);
			nuevo=retorna_nodo(x);
			cola(cabeza, nuevo);
		}
		else 
			printf("\ncarga finalizada.");
	}while(op!=0);
}

void agrega_pila(tptr *cabeza, tptr nuevo){
	nuevo->sig=*cabeza;
	*cabeza=nuevo;
}
/* Agregar al final (cola). Asegura nuevo->sig = NULL y defiende contra nuevo == NULL */
void cola(tptr *cabeza,tptr nuevo){
	tptr aux;
	aux=*cabeza;
	if(*cabeza!=NULL){
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig = nuevo;
	}
	else 
		*cabeza=nuevo;
}

/* Nueva función: cola_segura - igual firma que cola, pero implementada sin modificar cola() */
void agrega_cola(tptr *cabeza, tptr nuevo){
	tptr aux;
	aux=*cabeza;
	if(*cabeza!=NULL){
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig = nuevo;
	}
	else 
		*cabeza=nuevo;
}

/* Extrae y devuelve el primer nodo de la lista (cola). Retorna NULL si lista vacía. */
tptr desencolar(tptr *cabeza){
	if (cabeza == NULL || *cabeza == NULL)
		return NULL;

	tptr ret = *cabeza;
	*cabeza = (*cabeza)->sig;
	ret->sig = NULL; /* desconectar antes de devolver */
	return ret;
}
void mostrar_lista_nodos(tptr cabeza){
	if(cabeza != NULL){
		printf("\nlista ingresada\n");
		while(cabeza!=NULL){
			printf("%d,",cabeza->dato);
			cabeza=cabeza->sig;
		}
		printf("\nlista finalizada");
	}
	else
	   printf("\nlista vacia");
}

void inserta_ordenado(tptr *cabeza,tptr nuevo){
	tptr aux,ant;
	aux=NULL;
	ant=NULL;
	if(*cabeza==NULL)
		*cabeza=nuevo;
	else{
		aux=*cabeza;
		ant=NULL;
		while((aux!=NULL) && (nuevo->dato > aux->dato)){
			ant=aux;
			aux=aux->sig;
		}
		if(ant==NULL)
			agrega_pila(cabeza,nuevo);
		else{
				ant->sig=nuevo;
				nuevo->sig=aux;
			}
		}
		
	}

void inserta(tptr *cabeza){
	tptr nuevo;
	int x;
	printf("\ningrese un nuevo elemento:");
	scanf("%d", &x);
	nuevo=retorna_nodo(x);
	inserta_ordenado(cabeza,nuevo);
}




































