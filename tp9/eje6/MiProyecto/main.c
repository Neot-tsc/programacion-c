#include "tad_puntero.h"
#include <stdio.h>


int menu(void);

int main (void){
    int op;
    tptr lista;
    lista=NULL;
    do
    {
        op=menu();
        switch (op){
        case 1:
            carga_lista_nodos(&lista);
            break;
        case 2:
            mostrar_un_nodo_isbn(lista);
            break;
        case 3:
            modifica_tipo_nodo(lista);
            break;
        case 4:
            mostrar_lista_nodos(lista);
            break;
        case 0:
            printf("\nsaliendo del programa.");
            break;
        default:
            printf("\ningrese una opcion valida.");
        }
    } while (op!=0);
    liberar_lista(&lista);
}


int menu(void){
    int op;
    printf("\n\nMENU DE OPCIONES\n");
    printf("\n1.cargar lista de libros");
    printf("\n2.mostrar un libro por su ISBN");
    printf("\n3.modificar el tipo de un libro");
    printf("\n4.mostrar lista completa");
    printf("\n0.salir");
    printf("\ningrese una opcion:");
    scanf("%d", &op);
    return op;
}
