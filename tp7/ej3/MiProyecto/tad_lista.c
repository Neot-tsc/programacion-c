#include "tad_lista.h"

void ordena_ape(tvector, int);
int compara_ape(tcad, tcad);


tlista cargar_lista(){
    tlista aux;
    printf("\ningrese el tamanio de la lista:");
    scanf("%d", &aux.tam);
    cargar_vector(aux.a,aux.tam);
    return aux;
}


void cargar_vector(tvector a, int n){
    int i;
    for(i=1; i<=n; i++){
        a[i]=retorna_uno();
    }
    printf("\nCarga finalizada.");
}

void mostrar_lista(tlista a){
    int i;
    for(i=1; i<=a.tam; i++){
        muestra_uno(a.a[i]);
    }
}
void ordena_lista(tlista *a){
    ordena_ape(a->a, a->tam);
}

void ordena_ape(tvector a, int n){
    int i,j;
    tpersona aux;
    for(i=1; i<n; i++){
        for (j=i+1; j<=n; j++)
        {
            if (compara_ape(a[i].apellido, a[j].apellido) > 0)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        } 
    }
}
int compara_ape(tcad a, tcad b){
    int r;
    r=strcmp(a,b);
    return r;   
}
void agregar_uno(tlista *a){
    if(a->tam<max){
        (a->tam)++;
        a->a[a->tam]=retorna_uno();
    }
} /*al final de la lista*/
