#include "tad_puntero.h"

//funciones y procedimientos de tptr
tptr  retorna_nodo(talumno a){
    tptr nuevo;
    nuevo=(tptr)malloc(sizeof(tnodo));
    nuevo->dato=a;
    nuevo->sig=NULL;
    return nuevo;
}
tptr carga_lista(void){
    tptr cab,nuevo;
    long int n;
    cab=NULL;
    printf("\ningrese el dni del alumno a cargar:");
    scanf("%ld", &n);
    nuevo=retorna_nodo(retorna_alumno(n));
    agrega_uno_ordenado(&cab,nuevo);
    printf("\nalumno agregado con exito.");
    return cab;
}

void agrega_uno_ordenado(tptr* cab, tptr nuevo){
    tptr aux,ant;
    if(*cab==NULL)
        *cab=nuevo;
    else{
        aux=*cab;
        ant=NULL;
        while(aux->sig!=NULL && compara_dni_alumno(get_dni(nuevo->dato),get_dni(aux->dato))==1){
            ant=aux;
            aux=aux->sig;
        }
        if(ant==NULL)
            pila(cab,nuevo);
        else{
            ant->sig=nuevo;
            nuevo->sig=aux;
        }
    }
}

void pila(tptr *cab, tptr nuevo){
    nuevo->sig=*cab;
    *cab=nuevo;
}

void mostrar_lista(tptr cab){
    int i;
    i=1;
    if(cab!=NULL){
        printf("\nlista dealumnos\n");
        while(cab!=NULL){
            printf("\nalumno nro %d\n",i);
            mostrar_alumno(cab->dato);
            cab=cab->sig;
            i++;
        }
        printf("\nlista finalizada.");
    }
    else
        printf("\nlista vacia.");
}

void mostrar_un_alumno(tptr cab){
    long int n;
    printf("\ningrese el dni del alumno a buscar:");
    scanf("%ld", &n);
    int r;
    r=0;
    while(cab!=NULL && r==0){
        if(get_dni(cab->dato)==n){
            r=1;
            mostrar_alumno(cab->dato);
        }
        cab=cab->sig;
   }    
}

void elimina_nodo(tptr *cab){
    int bus;
    if(*cab!=NULL){
        printf("\ningrese la condicion de los alumnos a eliminar (1=regular/2=libre):");
        scanf("%d", &bus);
        while (*cab!=NULL)
            elimina_uno(cab,bus);
        printf("\noperacion finalizada.");
    }
    else
        printf("\nlista vacia.");
}

void elimina_uno(tptr *cab,int n){
    tptr aux,ant;
    aux=*cab;
    ant=NULL;
    while(aux->sig!=NULL && (get_condicion(aux->dato)!=n)){
        ant=aux;
        aux=aux->sig;
    }
    if(aux==NULL)
        printf("\nalumno no encontrado.");
    else{
        if(ant==NULL){
            *cab=aux->sig;
            free(aux);
            aux=NULL;
            printf("\nalumno eliminado con exito.");
        }
        else{
            ant->sig=aux->sig;
            free(aux);
            aux=NULL;
            printf("\nalumno eliminado con exito.");
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

void mostrar_reg_lib(tptr cab){
    int libres,regulares;
    libres=0;
    regulares=0;
    if(cab!=NULL){
        while(cab!=NULL){
            if(get_condicion(cab->dato)==1)
                regulares++;
            else
                    libres++;
            cab=cab->sig;
        }
        printf("\ncantidad de alumnos regulares: %d", regulares);
        printf("\ncantidad de alumnos libres: %d", libres);
    }
    else 
        printf("\nlista vacia.");
}

//fin