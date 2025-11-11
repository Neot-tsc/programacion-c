#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
}tnodo;


typedef tnodo *tptr;

tptr retorna_nodo(int);
void enqueue(tptr*,tptr*, tptr);
void carga_cola(tptr*,tptr*);
void mostrar_lista_nodos(tptr);
void liberar(tptr*);




int main(void){
    tptr ini,fin;
    ini=NULL;
    fin=NULL;
    carga_cola(&ini,&fin);
    mostrar_lista_nodos(ini);
    liberar(&ini);


    return 0;
}


tptr retorna_nodo(int n){
    tptr nuevo;
    nuevo=(tptr)malloc(sizeof(tnodo));
    if(nuevo!=NULL){
        nuevo->dato=n;
        nuevo->sig=NULL;
    }
    else
        printf("\nno se puedde asignar memoria");
    return nuevo;
}
void enqueue(tptr *ini,tptr *fin, tptr nuevo){
    if(nuevo!=NULL){
        if(*ini==NULL){
            *ini=nuevo;
            *fin=nuevo;
        }
        else{
            (*fin)->sig=nuevo;
            *fin=nuevo;
        }
    }
}
void carga_cola(tptr *ini,tptr *fin){
    tptr nuevo;
    int dato;
    printf("Cargar elementos en la cola:\n");
    printf("(Ingresa 0 para terminar)\n\n");
    do
    {
        printf("\ningrese un numero:");
        scanf("%d",&dato);
        if(dato!=0){
            nuevo=retorna_nodo(dato);
            enqueue(ini,fin,nuevo);
        }
        else
            printf("\ncarga terminada");

    } while (dato!=0);
}

void mostrar_lista_nodos(tptr lista){
    if(lista!=NULL){
        while(lista!=NULL){
            printf("\n%d,",lista->dato);
            lista=lista->sig;
        }
    }
}
void liberar(tptr *lista){
    tptr aux;
    while(*lista!=NULL){
        aux=*lista;
        *lista=(*lista)->sig;
        free(aux);
        aux=NULL;
    }
}
