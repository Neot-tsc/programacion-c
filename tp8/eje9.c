/*Ejercicio  9:  Se  pide  crear  un  programa  recursivo  que  permita  generar  aleatoriamente  una  lista  de  N 
números enteros en el intervalo [A, B], luego presentar un menú de opciones (el cual debe ser recursivo) 
que permita realizar las siguientes tareas: ordenar ascendentemente utilizando el método Q-Sort, buscar 
un elemento en la lista (dicho elemento es ingresado por teclado).*/



#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 50

typedef int lista[max];

void carga(lista,int*);
void carga_rec(lista, int, int, int);
int random(int, int);
void mostrar(lista, int);
void mostrar_rec(lista,int);
void ordenar(lista, int);
void q_sort(lista, int, int);
void buscar(lista, int);
int bb_rec(lista, int, int, int);
int opciones(void);
void menu_rec(lista,int);







int main (void){
    lista a;



    return 0;
}



void carga(lista a,int *n){
    int ini,fin;
    printf("\ningrese el tamanio de la lista:");
    scanf("%d", n);
    printf("\ningrese el inicio del intervalo:");
    scanf("%d", &ini);
    printf("\ningrese el fin del intervalo:");
    scanf("%d", &fin);
    srand(time(NULL));
    carga_rec(a,*n,ini,fin);
}

void carga_rec(lista a, int n, int ini, int fin){
    if(n>0){
        carga_rec(a,n-1,ini,fin);
        a[n]=random(ini,fin);
    }
}

int random(int ini, int fin){
    int n;
    n=ini+rand()%(fin-ini+1);
    return n;
}

void mostrar(lista a, int n){
    if(n>0){
        printf("\nelementos de la lista\n");
        mostrar_rec(a,n);
    }
    else 
        printf("\nla lista no posee elementos");
}

void mostrar_rec(lista a,int n){
    if(n>0){
        mostrar(a,n-1);
        printf("%d,", a[n]);
    }
}

void ordenar(lista a, int n){
    if(n>0){
        q_sort(a,1,n);
        printf("\nlista ordenada con exito.");
    }
    else 
        printf("\nlista vacio, no se puede ordenar.");
}

void q_sort(lista a, int ini, int fin){
    int izq,der,piv;
    if(ini<fin){
        izq=ini;
        der=fin;
        piv=a[ini];
        while(izq<der){
            while(izq<der && a[der]>=piv)
                der--;
            if(izq<der)
                a[izq]=a[der];
            while(izq<der && a[izq]<=piv)
                izq++;
            if(izq<der)
                a[der]=a[izq];
        }
        a[izq]=piv;
        q_sort(a,ini,izq-1);
        q_sort(a,izq-1,fin);
    }
}

void buscar(lista a, int n){
    int pos,buscado;
    printf("\ningres el elemento a buscar:");
    scanf("%d",&buscado);
    pos=bb_rec(a,1,n,buscado);
    if(pos>0)
        printf("\nelemento %d encontrado en la posicion: %d",buscado, pos);
    else 
        printf("\nelemento no encontrado.");
}

int bb_rec(lista a, int ini, int fin, int bus){
    int med;
    med=(ini+fin)/2;
    if(ini>fin)
        return 0;
    else{
        if(a[med]==bus)
            return med;
        else{
            if(a[med]<bus)
                return bb_rec(a, med-1, fin, bus);
            else    
                return bb_rec(a,ini, med+1, bus);
        }     
    }
}

int opciones(void){
    int op;
    printf("\n-----MENU-----\n");
    printf("\n1) buscar un elemento.");
    printf("\n2) mostrar lista.");
    printf("\n0) salir del menu.");
    printf("\nseleccione una opcion");
    scanf("%d", &op);
    return op;
}
void menu_rec(lista a,int n){
    switch (opciones())
    {
    case 1:
        buscar(a,n);
        menu_rec(a,n);
        break;
    case 2:
        mostrar(a,n);
        menu_rec(a,n);
        break;
    case 0:
        printf("\nsaliendo del programa.");
        break;
    default:
        printf("\ningrese una opcion valida.");
        menu_rec(a,n);
    }
}