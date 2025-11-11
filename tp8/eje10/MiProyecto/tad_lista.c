#include "tad_lista.h"

void cargar_lista(lista, int);
void ordenar_lista(lista, int);
void marge(lista, int, int, int);
void m_sort(lista,int,int);
void mostrar_rec(lista, int);


tdatos cargar_datos(void){
    tdatos aux;
    printf("\ningrese el tamanio de la lista:");
    scanf("%d",&aux.tam);
    cargar_lista(aux.nombres,aux.tam);
    return aux;
}


void ordenar(tdatos*a){
    m_sort(a->nombres,1,a->tam);
    printf("\nlista ordenada.");
}
void mostrar(tdatos a){
    printf("\nelementos de la lista\n");
    mostrar_rec(a.nombres,a.tam);
}

//#############################################
void cargar_lista(lista a, int n){
    if(n>0){
        cargar_lista(a,n-1);
        printf("\ningrese el nombre:");
        fflush(stdin);
        leecad(a[n]);
    }
}

void marge(lista a, int ini, int med, int fin){
    lista aux;
    int i,j,k,t,r;
    k=0;
    i=ini;
    j=med+1;
    while (i<=med && j<=fin)
    {
        r=comparar_cad(a[i],a[j]);
        if(r<=0){
            strcpy(aux[k],a[i]);
            i++;
        }
        else{
            strcpy(aux[k],a[j]);
            j++;
        }
		k++;
    }
    for(t=i; t<=med; t++){
		strcpy(aux[k],a[t]);
		k++;
    }
    for(t=j; t<=fin; t++){
		strcpy(aux[k],a[t]);
		k++;
    }
    for(t=0; t<k; t++)
        strcpy(a[ini+t],aux[t]);

}
void m_sort(lista a,int ini,int fin){
    int med;
    if(ini<fin){
        med=(ini+fin)/2;
        m_sort(a,ini,med);
        m_sort(a,med+1,fin);
        marge(a,ini,med,fin);
    }
}

void mostrar_rec(lista a, int n){
    if(n>0){
        mostrar_rec(a,n-1);
        printf("\n%s", a[n]);
    }
}
