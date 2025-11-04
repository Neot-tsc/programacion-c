/*Ejercicio 5: Mostrar los dígitos de un número natural X de derecha a izquierda. 
Realizar la traza para X= 
45673. Modificar el módulo para que muestre los dígitos de izquierda a derecha. 
(¿El módulo recursivo lleva return?) */

#include <stdio.h>

void muestra_izq_der(int);
void muestra_der_izq(int);


int main(void){
    int num;
    printf("\ningrese un numero natural:");
    scanf("%d", &num);
    printf("\nlos digitos de derecha a izquierda son:\n");
    muestra_der_izq(num);
    printf("\nlos digitos de izquierda a derecha son:\n");
    muestra_izq_der(num);
    return 0;
}

void muestra_izq_der(int num){
    int dig;
    if(num>0){
        muestra_izq_der(num/10);
        dig=num%10;
        printf("%d", dig);
    }
}
void muestra_der_izq(int num){
    int dig;
    if(num>0){
        dig=num%10;
        printf("%d", dig);
        muestra_der_izq(num/10);
    }
}