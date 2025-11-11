#include "tad_lista.h"


int main (void){
    tdatos a;
    a=cargar_datos();
    mostrar(a);
    ordenar(&a);
    mostrar(a);
    return 0;
}
