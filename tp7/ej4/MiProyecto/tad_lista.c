#include "tad_lista.h"

void genera_lista(articulos, int);
int busqueda_binaria(articulos, int, int);
void eliminar_un_elemento(articulos, int*, int);
int busqueda_stok(articulos, int, int);
int busqueda_proveedor(articulos, int, tcad);
//############################################################
//funciones y procedimientos de la lista dentro del .h


tlista cargar_lista(){
    tlista aux;
    printf("\ningrese la cantidad de articulos a ingresar:");
    scanf("%d", &aux.tam);
    genera_lista(aux.vect, aux.tam);
    return aux;
}
void mostrar_lista(tlista a){
    int i;
    printf("\nelementos de la lista:\n");
    for(i=1; i<=a.tam; i++){
        printf("\narticulo nro %d:", i);
        muestra_uno(a.vect[i]);
    }
}
void agregar(tlista *a){
    Tarticulo nuevo;
    int j;
    if(a->tam<max){
        printf("\ningrese el datos del nuevo articulo:");
        nuevo=retorna_uno();
        a->vect[0]=nuevo;
        j=a->tam;
        while(compara_articulos(a->vect[0], a->vect[j])==-1){
            a->vect[j+1]=a->vect[j];
            j--;
        }
        a->vect[j+1]=a->vect[0];
        a->tam++;
        printf("\narticulo agregado con exito");
    }
    else
        printf("\nla lista ya alcanzo el maximo de articulos permitidos.");
}


void eliminar(tlista *a){
    int buscado, pos;
    printf("\ningrese el codigo del articulo a eliminar:");
    scanf("%d", &buscado);
    pos=busqueda_binaria(a->vect, a->tam, buscado);
    if(pos!=0){
        eliminar_un_elemento(a->vect, &a->tam, pos);
		printf("\narticulo eliminado con exito.");
	}
    else
        printf("\nel articulo con codigo: %d no se encuentra en la lista.", buscado);
}

void mostrar_por_proveedor(tlista a){
    int i;
    tcad buscar;
    printf("\ningrese el nombre del proveedor a buscar:");
    fflush(stdin);
    leecad(buscar);
    if(busqueda_proveedor(a.vect, a.tam, buscar)==0)
        printf("\nno hay articulos de ese proveedor.");
    else {   
        printf("\narticulos del proveedor %s:", buscar);
        for(i=1; i<=a.tam; i++){
            if(compara_cadenas(a.vect[i].proveedor, buscar)==0){
                muestra_uno(a.vect[i]);
            }
        }
    }
}

void mostrar_por_stok_minimo(tlista a){
    int i,maximo;
    printf("\ningrese el stok maximo a buscar (se mostraran los menores e iguales al maximo):");
    scanf("%d", &maximo);
    if(busqueda_stok(a.vect, a.tam, maximo)==0)
        printf("\nno hay articulos con stok menor o igual a %d.", maximo);
    else
    {
        printf("\narticulos con stok menor a %d:", maximo);
        for(i=1; i<=a.tam; i++){
            if(a.vect[i].stok<=maximo)
                muestra_uno(a.vect[i]);
        }
    }
}

//#############################################################

//funciones y procedimientos auxiliares fuera del .h


void genera_lista(articulos a, int n){
    int i,j;
    i=1;
	printf("\narticulo nro %d", i);
    a[i]=retorna_uno();
    for(i=2; i<=n; i++){
		printf("\narticulo nro %d", i);
        a[i]=retorna_uno();
        a[0]=a[i];
        j=i-1;
        while(compara_articulos(a[0], a[j])==-1){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=a[0];
    }
}

int busqueda_binaria(articulos a, int n, int bus){
    int ini, fin, med, r;
    ini=1, fin=n, med=(ini+fin)/2, r=0;
    while(ini<=fin && a[med].codigo!=bus){
        if(a[med].codigo<bus)
            ini=med++;
        else 
            fin=med--;
        med=(ini+fin)/2;
    }
    if(ini<=fin)
        r=med;
    return r;
}

void eliminar_un_elemento(articulos a, int*n, int pos){
    int i;
    for(i=pos; i<=*n; i++)
        a[i]=a[i+1];
    (*n)--;
}

int busqueda_stok(articulos a, int n, int bus){
    int i, pos;
    pos=0;
    i=1;
    while(i<=n && a[i].stok!= bus)
        i++;
    if(i<n)
        pos=i;  
    return pos;
}
int busqueda_proveedor(articulos a, int n, tcad bus){
    int i, pos;
    pos=0;
    i=1;
    while(i<=n && compara_cadenas(a[i].proveedor, bus)!=0)
        i++;
    if(i<n)
        pos=i;  
    return pos;
}
