#include <stdio.h>
#include <stdlib.h>
#define max 50

typedef char tcad [max];
typedef struct{
    long int isbn;
    tcad nombre,tipo,referencia;
}tlibro;

typedef struct nodo
{
    tlibro dato;
    struct nodo *sig;
}tnodo;

typedef tnodo *tptr;


//funciones y procedimientos de tptr
tptr retorna_nodo(long int);
void carga_lista_nodos(tptr*);
void pila(tptr*, tptr);
void cola(tptr*,tptr);
void mostrar_lista_nodos(tptr);
int buscar(tptr, long int);
void muestra_un_libro(tptr);
void modifica_tpo_libro(tptr);
void liberar_lista(tptr*);


//funciones y procedimientos para la estructura tlibro

void leecad(tcad);
tlibro retorna_libro(long int);
void muestra_libro(tlibro);
void modifica_tipo_libro(tlibro*);

//funvion menu del main

int menu(void);



//########## inicio del main ##############

int main (void){
    tptr lista;
    int op;
    lista=NULL;
    do
    {
        op=menu();
        switch (op){
        case 1:
            carga_lista_nodos(&lista);
            break;
        case 2:
            muestra_un_libro(lista);
            break;
        case 3:
            mostrar_lista_nodos(lista);
            break;
        case 4:
            modifica_tpo_libro(lista);
            break;
        case 0:
            printf("\nsaliendo del programa");
            break;
        default:
            printf("\ningrese una opcion valida");
        }
    } while (op!=0);
    liberar_lista(&lista);
    
    return 0;
}

//########## fin del main ##############




//funciones y procedimientos de tptr

tptr retorna_nodo(long int n){
    tptr aux;
    aux=(tptr)malloc(sizeof(tnodo));
    aux->dato=retorna_libro(n);
    aux->sig=NULL;
    return aux;
}
//a
void carga_lista_nodos(tptr *lista){
    tptr nuevo;
    long int n;
    int r;
    printf("\ningrese el ISBN del nuevo libro:");
    scanf("%ld", &n);
    r=buscar(*lista,n);
    if(r==0){
        nuevo=retorna_nodo(n);
        pila(lista,nuevo);
        printf("\nlibro aniadido exitosamente");
    }
    else
        printf("\nel libro ya se encuentra el la lista");
}

void pila(tptr *cabeza, tptr nuevo){
    nuevo->sig=*cabeza;
    *cabeza=nuevo;
}

void cola(tptr *cabeza,tptr nuevo){
    tptr aux;
    aux=*cabeza;
    while(aux->sig != NULL)
        aux=aux->sig;
    aux->sig=nuevo;
}
//c
void mostrar_lista_nodos(tptr cabeza){
    int i;
    i=1;
    if(cabeza != NULL){
        printf("\nlista de libros\n");
        while(cabeza != NULL){
            printf("\nlibro nro %d", i);
            muestra_libro(cabeza->dato);
            i++;
            cabeza=cabeza->sig;
        }
    }
    else
        printf("\nla lista esta vacia.");
}

int buscar(tptr cab, long int bus){
    int r;
    r=0;
    if(cab != NULL){
        while(cab != NULL && r == 0){
            if(cab->dato.isbn == bus)
                r=1;   
            cab=cab->sig;  
        }
    }
    return r;
}
//b
void muestra_un_libro(tptr cab){
    long int n;
    int r;
    r=0;
    printf("\ningrese el ISBN del libro a buscar:");
    scanf("%ld", &n);
    if(cab != NULL){
        while(cab != NULL && r==0){
            if(cab->dato.isbn == n){
                r=1;
                muestra_libro(cab->dato);
            }
            cab=cab->sig;
        }
        if(r==0)
            printf("\nlibro no encontrado.");
    }
    else
        printf("\nlista vacia.");
}

//d
void modifica_tpo_libro(tptr cab){
        long int n;
    int r;
    r=0;
    printf("\ningrese el ISBN del libro a buscar:");
    scanf("%ld", &n);
    if(cab != NULL){
        while(cab != NULL && r==0){
            if(cab->dato.isbn == n){
                r=1;
                modifica_tipo_libro(&cab->dato);
            }
            cab=cab->sig;
        }
        if(r==0)
            printf("\nlibro no encontrado.");
    }
    else
        printf("\nlista vacia.");
}

void liberar_lista(tptr *lista)
{
    tptr aux;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
        aux = NULL;
    }
}



//funciones y procedimientos para la estructura tlibro


void leecad(tcad cad){
    int j;
    char c;
    j=0;
    c=getchar();
    while(c!=EOF && c!='\n' && j<max-1){
        cad[j]=c;
        j++;
        c=getchar();
    }
    cad[j]='\0';
    while(c!=EOF && c!='\n')
        c=getchar();
}


tlibro retorna_libro(long int n){
    tlibro aux;
    aux.isbn=n;
    printf("\ningrese el nombr del libro: ");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el tipo de libro (literatura/consulta): ");
    fflush(stdin);
    leecad(aux.tipo);
    printf("\ningrese la referencia (Artisticos/Divulgativos/Descripcion): ");
    fflush(stdin);
    leecad(aux.referencia);
    return aux;
}

void muestra_libro(tlibro a){
    printf("\nISBN del libro: %ld", a.isbn);
    printf("\nnombre: %s", a.nombre);
    printf("\nreferencia: %s", a.referencia);
    printf("\ntipo: %s", a.tipo);
}

void modifica_tipo_libro(tlibro *a){
    printf("\ningrese el nuevo tipo del libro (literatura/consulta):");
    fflush(stdin);
    leecad(a->tipo);
    printf("\nlibro modificado con exito.");
}

//menu del main

int menu(void){
    int op;
    printf("\n-----MENU-----\n");
    printf("\n1) agregar un nuevo libro.");
    printf("\n2) mostrar un libro.");
    printf("\n3) mostrar la lista de libros.");
    printf("\n4) modiicar el tipo de un libro.");
    printf("\n0) salir de la lista.");
    printf("\nseleccione una opcion: ");
    scanf("%d",&op);
    return op;
}