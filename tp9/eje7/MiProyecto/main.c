#include "tad_puntero.h"


int menu(void);


int main(void){
    tptr lista;
    int op;
    lista=NULL;
    do
    {
        op=menu();
        switch (op){
        case 1:
            lista=carga_lista();
            break;
        case 2:
            elimina_nodo(&lista);
            break;
        case 3:
            mostrar_un_alumno(lista);
            break;
        case 4:
            mostrar_reg_lib(lista);
            break;
        case 5:
            mostrar_lista(lista);
            break;
        case 0:
            printf("\nsaliendo del programa.");
            break;
        default:
            printf("\ningrese una opcion valida.");
        }
    } while (op!=0);
    liberar_lista(&lista);

    return 0;
}


int menu(void){
    int op;
    printf("\n-----MENU-----\n");
    printf("\n1) agregar una alumno.");
    printf("\n2) eliminar alumnos regulares.");
    printf("\n3) mostrar un alumno.");
    printf("\n4) mostrar cantidad de libres y regulares.");
    printf("\n5) mostrar lista completa.");
    printf("\n0) salir del menu.");
    printf("\nseleccione una opcion:");
    scanf("%d", &op);
    return op;
}
