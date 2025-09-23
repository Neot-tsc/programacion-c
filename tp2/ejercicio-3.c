#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cantdig(float);
float decimal(float);
float conversorpdecimal(float);

int main (void){
    float num, pdecimal,pentera;
    printf("\ningrese un numero real:");
    scanf("%f", &num);
    printf("\n cantidad de digitos de la parte entera:%d", cantdig(num));
    pdecimal=decimal(num);
    pentera=conversorpdecimal(pdecimal);
    printf("\n cantidad de digitos decimales es:%d",cantdig(pentera));
    return 0;
}

int cantdig(float num){
    int cant;
    cant=log10(num)+1;
    return cant;
}

float decimal(float num){
    float decimal, r;
    r=abs(num);
    decimal=(num-r);
    return decimal;
}

float conversorpdecimal(float num){
    int entero;
    entero=num*10000;
    return entero;
}