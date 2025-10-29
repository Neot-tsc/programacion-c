#include "tad_lista.h"


int menu(void);


int main(void){
    tlista productos;
    productos=cargar_lista();

    return 0;
}

int menu(void){
    int op;
    printf("\n1) agregar un articulo nuevo.");
    printf("\n2) eliminar un articulo de la lista dado un codigo.");
    printf("\n3) mostrar los articulos.");
    printf("\n4) mostrar los articulos de una mismo proveedor.");
    printf("\n5) dado un nivel de stok, mostrar los productos con menor stok al ingresado.");
    printf("\nseleccione una opcion:");
    scanf("%d", &op);
    return op;
}