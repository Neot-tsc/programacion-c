#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef int lista[max];

void carga(lista, int*);
void carga_rec(lista, int);
void muestra(lista, int);
void muestra_rec(lista, int);
int bb_rec(lista, int, int,int);
void elimina_rec(lista, int*, int);

int main(void){
    lista a;
    int n, buscado,pos;
    carga(a,&n);
    muestra(a,n);
    printf("\ningrese el numero a buscar:");
    scanf("%d", &buscado);
    pos=bb_rec(a,1,n,buscado);
    if(pos!=0){
        printf("\nel elemento se encuentra en :%d", pos);
        elimina_rec(a, &n, pos);
        muestra(a,n);
    }
    else
        printf("\nno encontrado");
    return 0;
}


void carga(lista a, int*n){
    printf("\ningrese la cantidad de elementos:");
    scanf("%d", n);
    carga_rec(a,*n);

}
void carga_rec(lista a, int n){
    if(n>0){
        carga_rec(a,n-1);
        printf("\ningrese un elemento:");
        scanf("%d", &a[n]);
    }
}

void muestra(lista a, int n){
    if(n>0){
        printf("\nlos elemetos de la lista\n");
        muestra_rec(a,n);
    }
    else    
        printf("\nlista vacia");
}
void muestra_rec(lista a, int n){
    if(n>0){
        muestra_rec(a,n-1);
        printf("%d,",a[n]);
    }
}

int bb_rec(lista a, int ini, int fin, int bus){
    int med;
    med=(ini+fin)/2;
    if(ini>fin)
        return 0;
    else {
        if(a[med]==bus)
            return med;
        else{
            if(a[med]<bus)
                return bb_rec(a,med+1,fin,bus);
            else 
                return bb_rec(a,ini, med-1, bus);
        }
    }
}


void elimina_rec(lista a, int *n , int pos){
    if(pos<=(*n)){
        a[pos]=a[pos+1];
        elimina_rec(a,n,pos+1);
    }
    else{
        (*n)--;
		printf("\nelemento eliminado con exito");
	}
}
