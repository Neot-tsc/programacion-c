#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define max 50

typedef char tcad [max];

typedef struct{
    long int codigo;
    tcad nombre;
    int stok;
    float precio;
}tarticulo;

typedef struct nodo
{
   tarticulo dato;
   struct nodo *sig; 
}tnodo;

typedef tnodo *tptr;


//procedimiento y funciones del tarticulo
void leecad(tcad);
tarticulo retornar_articulo(long int);
void muestra_articulo(tarticulo);
void modifica_tarticulo_precio(tarticulo*);
int evalua_cod(tarticulo,tarticulo);
int compara_tcadenas(tcad, tcad);

//proceddimiento y funciones de tptr

tptr retorna_nodo(long int);
tptr carga_lista_nodos();
int buscar(tptr,long int);
void pila(tptr*,tptr);
void cola(tptr*,tptr);
void mostrar_lista_nodos(tptr);
void modifica_articulo_precio(tptr);
void liberar_lista(tptr*);
void agregar_uno(tptr *,long int);
void agrega_manteniendo_orden(tptr *);
void mostrar_por_nombre(tptr);
void elimina_nodo(tptr *);
void elimina_uno(tptr *, long int );
tptr crea_lis_por_stok(tptr);
int prom_stok(tptr);
int nrorandom(int, int);
int evalua_nodo_cod(tptr,tptr);

int menu(void);


int main (void){
    tptr cab,lis;
    cab=NULL;
    lis=NULL;
    cab=carga_lista_nodos();
    int op;
    do
    {
        op=menu();
        switch (op)
        {
            case 1:
                agrega_manteniendo_orden(&cab);
                break;
            case 2:
                modifica_articulo_precio(cab);
                break;
            case 3:
                mostrar_por_nombre(cab);
                break;
            case 4:
                elimina_nodo(&cab);
                break;
            case 5:
                lis=crea_lis_por_stok(cab);
                mostrar_lista_nodos(lis);
                break;
            case 0:
                printf("\nsaliendo del programa.");
                break;
        default:
            printf("\nseleccione una opcion valida.");
        }
    } while (op!=0);
    
    liberar_lista(&cab);
    liberar_lista(&lis);


    return 0;
}



int menu(void){
    int op;
    printf("\n-----MENU-----\n");
    printf("\n1) agregar un nuevo articulo.");
    printf("\n2) modificar un precio.");
    printf("\n3) mostrar por nombre.");
    printf("\n4) elimina un articulo.");
    printf("\n5) crear lista con stok menor que k.");
    printf("\n0) salir del menu.");
    printf("\nseleccione una opcion: ");
    scanf("%d",&op);
    return op;
}








//procedimiento y funciones del tarticulo
void leecad(tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while(c!=EOF && c!='\n' && j<=max-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while (c!=EOF && c!='\n')
        c=getchar();
}

tarticulo retornar_articulo(long int n){
    tarticulo aux;
    aux.codigo=n;
    printf("\ningrese el nombre del articulo:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el stok del producto: ");
    scanf("%d", &aux.stok);
    printf("\ningrese el precio:");
    scanf("%f", &aux.precio);
    return aux;
}

void muestra_articulo(tarticulo a){
    printf("\ncodigo del articulo: %ld", a.codigo);
    printf("\nnombre del articulo: %s", a.nombre);
    printf("\ncantidad de stok del articulo: %d", a.stok);
    printf("\nprecio del articulo: %.2f", a.precio);
}

void modifica_tarticulo_precio(tarticulo *a){
    printf("\ningrese el nuevo precio:");
    scanf("%f", &a->precio);
    printf("\nprecio modificado exitosamente.");
}

int evalua_cod(tarticulo a,tarticulo b){
    int r;
    if(a.codigo > b.codigo)
        r=-1;
    else    
        if(a.codigo==b.codigo)
            r=0;
        else
            r=1;
    return r;
}

int compara_tcadenas(tcad a, tcad b){
	int r;
	if(strcmp(a,b)>0)
		r=1;
	else if (strcmp(a,b)<0)
		r=-1;
	else
		r=0;
	return r;
}



//proceddimiento y funciones de tptr

tptr retorna_nodo(long int n){
	tptr aux;
	aux=(tptr)malloc(sizeof(tnodo));
	aux->dato=retornar_articulo(n);
	aux->sig=NULL;
	return aux;
}
tptr carga_lista_nodos(){
	/* inicializar cabeza antes de usarla */
	tptr cab;
    cab=NULL;
    long int cod;
	int i,n,r;
	printf("\ningrese la cantidad de productos a ingresar en la lista:");
	scanf("%d", &n);
    i=1;
	while(i<=n){
        printf("\nelemnto nro %d\n", i);
        printf("\ningrese el codigo: ");
        scanf("%ld",&cod);
        r=buscar(cab,cod);
        if(r==0){
           agregar_uno(&cab,cod);
            i++;
        }
        else
            printf("\nel codigo ya esta ingresado en la lista, ingrese un codigo nuevo.");
	}
	printf("\nlista cargada con exito");
    return cab;
}

int buscar(tptr cab, long int bus){
    int r;
    r=0;
    if(cab!=NULL){
        while(cab!=NULL && r==0){
            if(cab->dato.codigo==bus)
                r=1;
            cab=cab->sig;
        }
    }
    return r;
}

void inserta_orenado(tptr *cab,tptr nuevo){
    tptr aux,ant;
    int r;
    aux=NULL;
    ant=NULL;
    if(*cab==NULL)
        *cab=nuevo;
    
    else{
        aux=*cab;
        ant=NULL;
        r=evalua_nodo_cod(*cab,nuevo);
        while ((aux!=NULL) && (r=-1)){
            ant=aux;
            aux=aux->sig;
            r=evalua_nodo_cod(*cab,nuevo);
        }
        if(ant==NULL)
            pila(cab,nuevo);
        else
            cola(cab,nuevo);
        
    }
}

int evalua_nodo_cod(tptr a,tptr b){
    int r;
    r=evalua_cod(a->dato,b->dato);
    return r;
}

void pila(tptr *cab,tptr nuevo){
    nuevo->sig=*cab;
    *cab=nuevo;
}

void cola(tptr *cab,tptr nuevo){
    tptr aux;
    if(*cab!=NULL){
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
    else
        *cab=nuevo;
}


void mostrar_lista_nodos(tptr cab){
    if(cab!=NULL){
        while(cab!=NULL){
            muestra_articulo(cab->dato);
            cab=cab->sig;
        }
    }
    else
        printf("\nlista vacia.");
}
//b
void modifica_articulo_precio(tptr cab){
    long int cod;
    int b;
    b=0;
    printf("\ningrese el codigo del articulo a buscar:");
    scanf("%ld", &cod);
    if(cab != NULL){
        while(cab != NULL && b==0){
            if(cab->dato.codigo == cod){
                b=1;
                modifica_tarticulo_precio(&cab->dato);
            }
            cab=cab->sig;
        }
        if(b==0)
            printf("\narticulo no encontrado.");
    }
    else
        printf("\nlista vacia.");
}

void liberar_lista(tptr *cab){
    tptr aux;
    while(*cab!=NULL){
        aux=*cab;
        *cab=(*cab)->sig;
        free(aux);
        aux=NULL;
    }
}

void agregar_uno(tptr *cab,long int n){
    tptr nuevo;
    nuevo=NULL;
    nuevo=retorna_nodo(n);
    inserta_orenado(cab,nuevo);
}

//a
void agrega_manteniendo_orden(tptr *cab){
    long int cod;
    int r;
    printf("\ningrese el codigo: ");
    scanf("%ld",&cod);
    r=buscar(*cab,cod);
    if(r==0)
        agregar_uno(cab,cod);
    else
        printf("\nel codigo ya esta ingresado en la lista.");
}

//c
void mostrar_por_nombre(tptr cab){
    tcad n;
    int r,op;
    r=0;
    printf("\ningrese el nombre del articulo a buscar:");
    fflush(stdin);
    leecad(n);
    if(cab != NULL){
        while(cab != NULL){
            op=compara_tcadenas(cab->dato.nombre,n);
            if(op == 0){
                muestra_articulo(cab->dato);
                r=1;
            }
            cab=cab->sig;
        }
        if(r==0)
            printf("\nnombre del articulo no encontrado.");
    }
    else
        printf("\nlista vacia.");
}


//d
void elimina_nodo(tptr *cab){
    long int n;
    if(*cab != NULL){
        printf("\ningrese el codigo del articulo a eliminar:");
        scanf("%ld",&n);
        elimina_uno(cab,n);
    }
    else
        printf("\nlista vacia.");
}

void elimina_uno(tptr *cab, long int n){
    tptr aux, ant;
    aux=*cab;
    ant=NULL;
    while (aux!=NULL && aux->dato.codigo != n){
        ant=aux;
        aux=aux->sig;
    }
    if(aux==NULL)
        printf("\nno se encontro el codigo buscado.");
    else
        {
            if(ant==NULL){
                *cab=aux->sig;
                free(aux);
                aux=NULL;
                printf("\narticulo eliminado");
            }
            else{
                ant->sig = aux->sig;
				free(aux);aux=NULL;
				printf("\narticulo eliminado");
            }
        }
}
//e
tptr crea_lis_por_stok(tptr cab){
    tptr lis;
    lis=NULL;
    int k,prom;
    prom=prom_stok(cab);
    k=nrorandom(prom,2*prom);
    if(cab!=NULL){
        while(cab!=NULL){
            if(cab->dato.stok<k)
                inserta_orenado(&lis,cab);
        }
    }
    return lis;
}


int prom_stok(tptr cab){
    int prom,acu,cant;
    acu=0;
    cant=0;
    if(cab!=NULL){
        while(cab!=NULL){
            acu=acu+cab->dato.stok;
            cant++;
        }
    }
    prom=acu/cant;
    return prom;
}




int nrorandom(int x, int y){
    srand(time(NULL));
	int n;
	n=x+rand()%(y-x+1);
	return n;
}
