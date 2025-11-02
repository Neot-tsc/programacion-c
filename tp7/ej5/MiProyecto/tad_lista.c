#include "tad_lista.h"

int busqueda_binaria(datos, int, long int);
void elimina_uno(datos, int*, int);




//#############################################################
//funciones y procedimientos de la lista dentro del .h
tlista cargar_lista(){
    tlista aux;
    aux.tam=0;
    int op,j;
    do
    {
        printf("\ningrese 1 para agregar un elemento a la lista o 0 para finalizar: ");
        scanf("%d", &op);
        if(op==1){
            (aux.tam)++;
            aux.lista[aux.tam]=carga_datos();
            aux.lista[0]=aux.lista[aux.tam];
            j=aux.tam-1;
            while(get_dni(aux.lista[0])<get_dni(aux.lista[j])){
                aux.lista[j+1]=aux.lista[j];
                j--;
            }
            aux.lista[j+1]=aux.lista[0];
        }
        else {
            if(op!=0)
                printf("\nopcion no valida, reingrese\n");
        }
    } while (op!=0);
    return aux;
}
void mostrar_lista(tlista a){
    int i;
    for(i=1; i<=a.tam; i++){
        printf("\n\nDatos del cluiente nro %d", i);
        muestra_datos(a.lista[i]);
    }
}

void agregar(tlista* a){
    tdatos nuevo;
    int j;
    if(a->tam<max){
        printf("\ningrese los datos del nuevo cliente: ");
        nuevo=carga_datos();
        a->lista[0]=nuevo;
        j=a->tam;
        while(get_dni(a->lista[0])<get_dni(a->lista[j])){
            a->lista[j+1]=a->lista[j];
            j--;
        }
        a->lista[j+1]=a->lista[0];
        a->tam++;
        printf("\ncliente agregado con exito.");
    }
    else
        printf("\nla lista ya alcanzo el maximo de clientes permitidos.");
}

void eliminar(tlista*a){
    long int bus;
    int pos,i;
    printf("\ningrese el DNI del cliente a eliminar:");
    scanf("%ld", &bus);
    pos=busqueda_binaria(a->lista, a->tam, bus);
    if(pos!=0){
        elimina_uno(a->lista, &a->tam, pos);
        printf("\ncliente eliminado con exito.");
    }
    else
        printf("\nel cliente con DNI: %ld no se encuentra en la lista.", bus);   
}

void acreditar_saldo(tlista*a){
    long int bus;
    int pos;
    float monto;
    printf("\ningrese el DNI del cliente al que desea acreditar saldo:");
    scanf("%ld", &bus);
    pos=busqueda_binaria(a->lista, a->tam, bus);
    if(pos!=0){
        printf("\ncliente encontrado:");
        printf("\ningrese el monto a acreditar:");
        scanf("%f", &monto);
        actualiza_saldo_acreditado(&a->lista[pos], monto);
        printf("\nsaldo acreditado con exito.");
    }
    else
        printf("\nel cliente con DNI: %ld no se encuentra en la lista.", bus);
}
void debitar_saldo(tlista*a){
    long int bus;
    int pos;
    float monto;
    printf("\ningrese el DNI del cliente al que desea devitar saldo:");
    scanf("%dl",&bus);
    pos=busqueda_binaria(a->lista, a->tam, bus);
    if(pos!=0){
        printf("\ncliente encontrado:");
        printf("\ningrese el monto a debitar:");
        scanf("%f", &monto);
        actualiza_saldo_debitado(&a->lista[pos], monto);
        printf("\nsaldo debitado con exito.");
    }
    else
        printf("\nel cliente con DNI: %ld no se encuentra en la lista.", bus);
}

//#############################################################
//funciones y procedimientos auxiliares fuera del .h

int busqueda_binaria(datos a, int n, long int bus){
    int ini,fin,med,r;
    ini=1, fin=n, med=(ini+fin)/2,r=0;
    while(ini<=fin && get_dni(a[med])!=bus){
        if(get_dni(a[med])<bus)
            ini=med++;
        else 
            fin=med--;
        med=(ini+fin)/2;
    }   
    if(ini<=fin)
        r=med;
    return r;
}


void elimina_uno(datos a, int*n, int pos){
    int i;
    for(i=pos; i<=*n; i++)
        a[i]=a[i+1];
    (*n)--; 
}
