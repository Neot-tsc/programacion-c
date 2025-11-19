#include "tad_libro.h"


tlibro retorna_libro(long int n){
    tlibro aux;
    aux.isbn=n;
    printf("\ningrese el nombre del libro:");
    fflush(stdin);
    leecad(aux.nombre);
    printf("\ningrese el tipo del libro (literatura/consulta):");
    fflush(stdin);
    leecad(aux.tipo);
    printf("\ningrese la referencia del libro (artisticos/divulgativos/descripcion):");
    fflush(stdin);
    leecad(aux.referencia);
    return aux;
}

void muestra_libro(tlibro a){
    printf("\nISBN del libro: %ld", a.isbn);
    printf("\nnombre: %s", a.nombre);
    printf("\nreferencia: %s", a.referencia);
    printf("\ntipo: %s", a.tipo);
}

void modifica_tipo_libro(tlibro *a){
    printf("\ningrese el nuevo tipo del libro (literatura/consulta):");
    fflush(stdin);
    leecad(a->tipo);
    printf("\ntipo modificado con exito.");
}
long int get_isbn(tlibro a){
    return a.isbn;
}
