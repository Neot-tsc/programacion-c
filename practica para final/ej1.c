/*Ejercicio 2: Una biblioteca cuenta con libros sobre los cuales se registra: el código, título, primer autor, editorial,
año de edición, ubicación (pasillo y estante)
Se desea un programa que permita ingresar N libros, ordenarlos por código y posteriormente presente un menú
con las siguientes opciones:
1) Agregar un libro, manteniendo el orden. Controlar que el código que se ingrese no esté ya asignado.
2) Dado el código de un libro, mostrar sus datos.
3) Dado el código de un libro, eliminar sus datos.
Para ello se solicita 
a) crear una unidad con la definición del TAD que administre la lista de libros.  La lista será implementada 
como un array de registros. En este punto se solicita solamente la definición de tipos de datos y 
cabeceras de los módulos necesarios, definidos correctamente en una unidad.
b) Implementar el módulo del TAD necesario para ordenar los libros según código. Utilizar el método de 
Sort by Merging (M-Sort) recursivo.
c) Implementar el o los módulos del TAD necesarios para cumplir con el inciso 3) del menú. 
d) Escribir el programa con el menú.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100




