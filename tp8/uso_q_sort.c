#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef int tlista[max];

void carga(tlista, int*);
void carga_rec(tlista, int);
void mostrar(tlista, int);
void mostrar_rec(tlista, int);
void quick_sort(tlista, int, int);


int main(void){
    tlista a;
    int n;
    carga(a,&n);
    printf("\nlista antes de ordenar:");
    mostrar(a,n);
    qsort(a,1,n);
    printf("\nlista despues de ordenar:");
    mostrar(a,n);
    return 0;
}

void carga(tlista a, int *n){
    printf("\ningrese el tamanio de la lista:");
    scanf("%d",n);
    carga_rec(a,*n);
    printf("\nlista cargada con exito.");
}
void carga_rec(tlista a, int n){
    if(n>0){
        carga_rec(a,n-1);
        printf("\ningrese un numero");
        scanf("%d", &a[n]);
    }
}

void mostrar(tlista a, int n){
    if(n>0){
        printf("\nlos elemetos de la lista\n");
        mostrar_rec(a,n);
    }
    else    
        printf("\nlista vacia");
}

 void mostrar_rec(tlista a, int n){
    if(n>0){
        mostrar_rec(a,n-1);
        printf("%d,",a[n]); 
    }
 }

void quick_sort(tlista a, int ini, int fin){
    int izq,der,piv;
    if(ini<fin){
        izq=ini;
        der=fin;
        piv=a[ini];
        while(izq<der){
            while(izq<der && a[der]<=piv)
                der--;
            if(izq<der)
                a[izq]=a[der];
            while(izq<der && a[izq]>=piv)
                izq++;
            if(izq<der)
                a[der]=a[izq];

        }
        a[izq]=piv;
        quick_sort(a,ini,izq-1);
        quick_sort(a,izq+1,fin);
    }
}