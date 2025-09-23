/*Ejercicio 10: 
Dado un monto de dinero correspondiente a una deuda en pesos, la fecha de vencimiento 
de dicha deuda, y una tasa de interés diario, generar al azar una fecha posterior de pago y mostrar el 
monto a pagar en concepto de intereses.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define min 1
#define Dmax 30
#define Mmax 12
#define Amax 2060


#define interes 0.5


int Drandom();
int Mrandom();
int Arandom(int);

int main (void){
    float monto,monto_final;
    int dia,mes,anio, dia_venc, mes_venc, anio_venc, d;
    printf("\ningrese el monto de la deuda en pesos: ");
    scanf("%f",&monto);
    printf("\ningrese la fecha del deposito (dd mm aaaa): ");
    printf("\ningrese el dia:");
    scanf("%d",&dia);
    printf("\ningrese el mes:");
    scanf("%d",&mes); 
    printf("\ningrese el anio:");
    scanf("%d",&anio);
	srand(time(NULL));
    dia_venc=Drandom();
    mes_venc=Mrandom();
    anio_venc=Arandom(anio);
    d=anio_venc-anio;
    monto_final=monto*(1+interes*360*d);
    printf("\nla fecha de vencimiento es: %d/%d/%d",dia_venc,mes_venc,anio_venc);
    printf("\nel monto final a pagar es: %.2f",monto_final);
    return 0;
}

int Drandom(){
    int n;
    n=min+rand()%Dmax-min+1;
    return n;
}

int Mrandom(){
    int n;
    n=min+rand()%Mmax-min+1;
    return n;
}

int Arandom(int anio){
    int n;
    n=anio+rand()%(Amax-anio+1);
    return n;
}
