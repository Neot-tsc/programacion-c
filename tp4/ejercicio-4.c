/*Ejercicio 4: Se tiene una lista de las edades de N alumnos de una escuela, se solicita ingresar la lista y 
a continuación, mediante un menú:    
a) Determinar la edad con mayor cantidad de repeticiones, sabiendo que existe y es única.    
b) Mostrar  la  primera  sublista  creciente,  de  al  menos  dos  números,  conformada  sólo  por  elementos 
pares*/

#include <stdio.h>

#define max 50

typedef int Tlista[max];

void carga_vector(Tlista,int*);
int menu();
void mayor_repeticiones(Tlista, int, int*, int*);
int formado_por_pares(int);
void sublista_creciente(Tlista, int, Tlista*, int*);




int main (void){
    Tlista edades, sublista;
    int n, subn, cantidad, posicion, op;
    cantidad=0;
    posicion=0;
    carga_vector(edades,&n);
    do
    {
        op=menu();
        switch (op)
        {
            case 'a':
                mayor_repeticiones(edades,n,&cantidad,&posicion);
                printf("La edad con mayor cantidad de repeticiones es: %d, y se repite %d veces\n",edades[posicion],cantidad);
                break;
            case 'b':
                sublista_creciente(edades,n,&sublista,&subn);
                break;
            default:
                if(op!=0)
                    printf("Opcion incorrecta\n");
                break;
    } }while (op!=0);
    return 0;
}
void carga_vector(Tlista a,int*n){
    int i;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d",n);  
    for(i=1; i<=*n; i++){
        printf("Ingrese la edad del alumno: ");
        scanf("%d",&a[i]);
    }
}

int menu(){
    int op;
    printf("\na) Determinar la edad con mayor cantidad de repeticiones");
    printf("\nb) mosttar una sublista creciente");
    printf("\n0) salir del programa");
    printf("\ningrese una opcion: ");
    scanf("%d",&op);
    return op;
}
void mayor_repeticiones(Tlista a, int n, int*cantidad, int* posicion){
    int i,j,cant;
    for(i=1; i<n; i++){
        cant=0;
        for(j=1; j<=n; j++){
            if(a[i]==a[j]){
                cant++;
            }
            if(cant>*cantidad){
                *cantidad=cant;
                *posicion=i;
            }
        }
    }
}

int formado_por_pares(int num){
        int r,dig, ban;
        ban=1;
    while(num!=0 && ban==1){
        dig=num%10;
        if(dig%2!=0){
            ban=0;
        }
        num=num/10;
    }
    if(ban==1)
        r=1;
    else
        r=0;
    return r;
}

void sublista_creciente(Tlista a, int n, Tlista* nv, int* m){
    *m=0;
    int i;
    for(i=1; i<=n; i++){
        if(formado_por_pares(a[i])){
            *m=*m+1;
            (*nv)[*m]=a[i];
        }
    }
}
