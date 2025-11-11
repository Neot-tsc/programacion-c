#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo
{
    int x,y;
    struct nodo* sig;
}tnodo;

typedef tnodo* tpuntero;

tpuntero retorna_nodo(int, int);
void agregar_cabeza(tpuntero*,tpuntero);
void cargar_lista_nodos(tpuntero*);
void mostrar_lista_nodos(tpuntero);
void par_menor(tpuntero);
int expreccion(int,int);




int main(void){
    tpuntero lista;
    lista = NULL; /* inicializar la lista antes de usarla */
    cargar_lista_nodos(&lista);
    mostrar_lista_nodos(lista);
    par_menor(lista);
    mostrar_lista_nodos(lista);

    /* liberar memoria antes de terminar */
    liberar_lista(&lista);

    return 0;
}



tpuntero retorna_nodo(int n, int m){
    tpuntero aux;
    aux=(tpuntero)malloc(sizeof(tnodo));
    aux->x=n;
    aux->y=m;
    aux->sig=NULL;
    return aux;
}
void agregar_cabeza(tpuntero *cabeza,tpuntero nuevo){
    nuevo->sig=*cabeza;
    *cabeza=nuevo;
}
void cargar_lista_nodos(tpuntero *lista){
    tpuntero nuevo;
    int op,x,y;
    do
    {
        printf("\nagregar un nuevo nodo a la lista(1=si/0=no):");
        scanf("%d", &op);
        if(op!=0){
            printf("\ningrese los valores del par ordenado:");
            printf("\nvanor de x:");
            scanf("%d", &x);
            printf("\nvalor de y:");
            scanf("%d", &y);
            nuevo=retorna_nodo(x,y);
            agregar_cabeza(lista,nuevo);
        }
        else 
            printf("\ncarga finalizada.");
    } while (op!=0);
}


void mostrar_lista_nodos(tpuntero lista){
    if(lista!=NULL){
        printf("\nlista de pares ordenados\n");
        while (lista!=NULL){
            printf("\n(%d,%d)",lista->x,lista->y);
            lista=lista->sig;
        }
        printf("\nlista finalizada");
    }
    else    
        printf("\nlista vacia.");
}

void par_menor(tpuntero lista){
    int r,menor,ban, n,m;
    ban=0;
    if(lista!=NULL){
        while(lista!=NULL){
            if(ban==0){
                r=expreccion(lista->x,lista->y);
                menor=r;
                n=lista->x;
                m=lista->y;
                ban=1;
                lista=lista->sig;
            }
            else{
                r=expreccion(lista->x,lista->y);
                if(r<menor){
                    menor=r;
                    n=lista->x;
                    m=lista->y;
                    lista=lista->sig;
                }
            else
                lista=lista->sig;
            }
        }
        printf("\nEl valor minimo de la expresion (x^2 - 10*y) = %d formado por el par (%d,%d)\n", menor, n, m);
    }
    else
        printf("\nlista vacia");
}

int expreccion(int x,int y){
    /* Evitar pow() para enteros y posibles conversiones dobles */
    return (x * x) - 10 * y;
}

/* libera todos los nodos de la lista y deja el puntero en NULL */
void liberar_lista(tpuntero *lista)
{
    tpuntero aux;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
        aux = NULL;
    }
}
