#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50


typedef char tcad[max];

void leecad(tcad);
void leecad_rec(tcad,int);

typedef tcad tlista[max];

void carga_lista(tlista, int*);
void carga_lista_rec(tlista,int);
void ordena_q(tlista,int);
void qsort(tlista,int,int);
void marge(tlista,int,int,int);
void msort(tlista,int,int);
void muestra_lista(tlista,int);
void muestra_lista_rec(tlista,int);


int main(void){
    tlista lista;
    int n;
    carga_lista(lista,&n);
    qsort(lista,0,n-1);
    muestra_lista(lista,n);
    /*carga_lista(lista,&n);
    msort(lista,1,n);
    muestra_lista(lista,n);
    */
    return 0;
}

void leecad(tcad cad){
    leecad_rec(cad,0);
}

void leecad_rec(tcad cad,int j){
    char c;
    c=getchar();
    if(c!=EOF && c!='\n' && j<max-1){
        cad[j]=c;
        leecad_rec(cad,j+1);
    }
    else{
        cad[j]='\0';
        while(c!=EOF && c!='\n')
            c=getchar();
    }
}


void carga_lista(tlista a, int *n){
    printf("\ningrese el tamanio de la lista:");
    scanf("%d",n);
    carga_lista_rec(a,*n);
    printf("\nlista cargada con exito.");
}

void carga_lista_rec(tlista a,int n){
    if(n>0){
        carga_lista_rec(a,n-1);
        printf("\ningrese el nombre:");
        fflush(stdin);
        leecad(a[n]);
    }
}

void qsort(tlista a,int ini,int fin){
    tcad piv;
    int izq,der;
    if(ini<fin){
        izq=ini;
        der=fin;
        strcpy(piv,a[ini]);
        while(izq<der){
            while(izq<der && strcmp(a[der],piv)>=0)
                der--;
            if(izq<der)
                strcpy(a[izq],a[der]);
            while (izq<der && strcmp(a[izq],piv)<=0)
                izq++;
            if(izq<der)
                strcpy(a[der],a[izq]); 
        }
        strcpy(a[izq],piv);
        qsort(a,ini,izq-1);
        qsort(a,izq+1,fin);
    }
}

void marge(tlista,int,int,int);
void msort(tlista,int,int);
void muestra_lista(tlista a,int n){
    if(n>0){
        printf("\nlos elementos de la lista son:\n");
        muestra_lista_rec(a,n);
    }
    else    
        printf("\nlista vacia.");   
} 

void muestra_lista_rec(tlista a,int n){
    if(n>0){
        muestra_lista_rec(a,n-1);
        printf("%s\n",a[n]);
    }
}


