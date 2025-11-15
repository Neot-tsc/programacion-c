#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 50


typedef char tcad [max];
//funciondes de tcad
void leecad(tcad);
int compara_cad(tcad,tcad);


//cuerpo de las funciones
void leecad(tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while (c!=EOF && c!='\n' && j<max-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while (c!=EOF && c!='\n')
        c=getchar();
}

int compara_cad(tcad a,tcad b){
    int r;
    if(strcmp(a,b)>0)
        r=1;
    else{
        if(strcmp(a,b)<0)
            r=-1;
        else
            r=0;
    }
    return r;
}





typedef struct 
{
    long int codigo;
    tcad nombre;
    int stok;
    float precio;
}tarticulo;
//funciones de tarticulo
tarticulo retorna_articulo(long int);
void mostrar_articulo(tarticulo);
void modifica_Tarticulo(tarticulo*);
int compara_nom_art(tarticulo, tarticulo);


//cuerpo de las funciones
tarticulo retorna_articulo(long int n){
    tarticulo aux;
    aux.codigo=n;
    printf("\ningrese el nombre del articulo:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el stok del articulo:");
    scanf("%d", &aux.stok);
    printf("\ningrese el precio:");
    scanf("%f",&aux.precio);
    return aux;
}

void mostrar_articulo(tarticulo a){
    printf("\ncodigo: %ld", a.codigo);
    printf("\nnombre: %s", a.nombre);
    printf("\nstok: %d", a.stok);
    printf("\nprecio: %f.2\n", a.precio);
}

void modifica_Tarticulo(tarticulo *a){
    float nuevo;
    printf("\ningrese el nuevo precio del articulo:");
    scanf("%f", &nuevo);
    a->precio=nuevo;
    printf("\narticulo modificado con exito.");
}

int compara_nom_art(tarticulo a, tarticulo b){
    return compara_cad(a.nombre,a.nombre);
}















typedef struct nodo
{
    tarticulo dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;

//funfiones de tptr y nodo
tptr retorna_nodo(long int);
tptr retorna_lista(void);
void pila(tptr*,tptr);
void cola(tptr*,tptr);
void inserta_nodo_ordenado(tptr*,tptr);
void mostrar_lista(tptr);
void liberar_lista(tptr*);




//cuerpo de las funciones

tptr retorna_nodo(long int n){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=retorna_articulo(n);
    aux->sig=NULL;
    return aux;
}
tptr retorna_lista(void){
    tptr cab,nuevo;
    cab=NULL;
    int n,i,b;
    b=0;
    long int cod;
    i=1;
    printf("\ningrese la cantidad de articulos a ingresar:");
    scanf("%d", &n);
    while(i<=n){
        printf("\ningrese el codigo del nuevo articulo:");
        scanf("%ld", &cod);
        nuevo=retorna_nodo(cod);
        if(b==0){
            pila(&cab,nuevo);
            b=1;
        }
        else
            cola(&cab,nuevo);
        i++;
    }
    printf("\ncarga finalizada");
	
	return cab;
}




void pila(tptr *cab,tptr nuevo){
    nuevo->sig=*cab;
    *cab=nuevo;
}
void cola(tptr *cab,tptr nuevo){
    tptr aux;
    aux=*cab;
    if(*cab!=NULL){
        while (aux->sig != NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
    else    
        *cab=nuevo;
}

void inserta_nodo_ordenado(tptr*,tptr);
void mostrar_lista(tptr cab){
    int i;
    i=1;
    if(cab==NULL)
        printf("\nlista vacia.");
    else{
        while(cab!=NULL){
            printf("\narticulo nro %d\n",i);
            mostrar_articulo(cab->dato);
            cab=cab->sig;
        }
    }
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









int main(void){
    tptr cab;
    cab=NULL;
    cab=retorna_lista();
    mostrar_lista(cab);
    liberar_lista(&cab);

    return 0;
}
