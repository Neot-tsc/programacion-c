/*Ejercicio 9: 
Dado un número natural X, determinar la cantidad de divisores naturales que posee. Si la 
cantidad de divisores es un número primo, mostrar el número equivalente de X en base 2, caso 
contrario, mostrar su equivalente a base 9.*/

#include <stdio.h>


int cantddiv(int);
int determina_primo(int);
double conversor_base2(int);
double invertir(double);

int main(void){
    int x;
    printf("ingrese un numero natural: ");
    scanf("%d",&x);





    return 0;
}

int cantddiv(int x){
    int i, cant;
    cant=1;
    for(i=1; i<=x/2; i++){
        if(x%i==0)
            cant++;
    }
    return cant;
}

int determina_primo(int num){
    int r,pd;
    r=0;
    pd=2;
    if(num>0){
        while ((pd<=num/2) && (num%pd!=0))
            pd++;
        if((pd>num/2) && (num!=1))
            r=1;
        else
            r=0;   
    }

    return r;
}

double conversor_base2(int num){
    double r;
    r=0;
    while(num/2>=1){
        r=r*10+num%2;
    }
}