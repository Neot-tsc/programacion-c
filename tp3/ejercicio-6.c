/*Ejercicio 6: Dados N números reales, con 4 dígitos decimales de precisión, cree un programa que, para 
cada número real, cambie cada uno de sus dígitos impares por el dígito par anterior. Ejemplo A= 741,3478 
entonces modificado A= 640,2468 
Nota: reutilizar el modulo generado en el inciso 5*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define base 10


int cuenta_digitos(int);
void separa_entero_decimal(float, int*, int*);
void transforma_num(int*);
int invertir(int); 

int main (void){
    int n,i,cant, entera, decimal;
    float numero;
    printf("\ningrese lacantidad de numero a modificar: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("\ningrese un  numero real: ");
        scanf("%f", &numero);
        separa_entero_decimal(numero, &entera, &decimal);
        transforma_num(&entera);
        transforma_num(&decimal);
        cant=cuenta_digitos(decimal);
        numero=entera+decimal*pow(base,-cant);
        printf("\nnumero modificado: %.4f", numero);
    }

    return 0;
}

int cuenta_digitos(int num){
    int cant;
    cant=0;
    while (num!=0)
    {
        num=num/10;
        cant++;
    }
    return cant;
}
void separa_entero_decimal(float x, int *entero, int *decimal){
    int cant;
    float aux;
    aux=x;
    *entero=(int)x;
    aux=aux-(int)x;
    cant=cuenta_digitos(aux); 
    *decimal=aux*pow(base,cant);
}

void transforma_num(int *x){
    int aux,dig,nvnum;
    aux=*x;
    nvnum=0;
    while (aux!=0)
    {
        dig=aux%10;
        if(dig%2!=0){
            dig--;
            if(dig<0)
                dig=0;
            nvnum=nvnum*10+dig;
        }
        aux=aux/10;
    }
    *x=invertir(nvnum);
}



int invertir(int num){
    int invertido, aux;
    invertido=0;
    while(num!=0){
        aux=num%10;
        invertido=invertido*10+aux;
        num=num/10;
    }
    return invertido;
}
