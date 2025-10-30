#include "tad_lista.h"


int menu(void);


int main(void){
    tlista productos;
    productos=cargar_lista();
    int op;
    do{
        op=menu();
        switch (op){
            case 1:
                    agregar(&productos);
                break;
            case 2:
                    eliminar(&productos);
                break;
            case 3:
                    mostrar_lista(productos);
                break;
            case 4:
                    mostrar_por_proveedor(productos);
                break;
            case 5:
                    mostrar_por_stok_minimo(productos);
                break;
            case 0:
                printf("saliendo del programa...\n");
                break;
            default:
            printf("\ningrese una opcion valida.");
        }
    } while(op!=0);
    return 0;
}

int menu(void){
    int op;
    printf("\n1) agregar un articulo nuevo.");
    printf("\n2) eliminar un articulo de la lista dado un codigo.");
    printf("\n3) mostrar los articulos.");
    printf("\n4) mostrar los articulos de una mismo proveedor.");
    printf("\n5) dado un nivel de stok, mostrar los productos con menor stok al ingresado.");
    printf("\n0) salir.");
    printf("\nseleccione una opcion:");
    scanf("%d", &op);
    return op;
}
