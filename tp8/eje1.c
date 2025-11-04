/*Ejercicio 1: Dado el módulo iterativo que calcula el factorial de un número natural, 
se solicita replantearlo 
recursivamente y realizar la traza con num=6.  
int factorial(int num){ 
int i,fact=1; 
for (i=num; i>=1; i--) 
fact=fact*i;  
return fact; }  */

#include <stdio.h>

int factorial(int);

int main(){
    int num, resultado;
    printf("ingrese un numero natural: ");
    scanf("%d", &num);
    resultado=factorial(num);
    printf("el factorial de %d es: %d\n", num, resultado);
}

int factorial(int n){
    if(n==0)
        return 1;
    else 
        return n*factorial(n-1);
}