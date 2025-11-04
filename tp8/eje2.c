
/*Ejercicio 2: Para las siguientes situaciones, realice un módulo recursivo y la traza con los datos indicados 
para cada una:  
a) Dado un dígito D, determinar si pertenece a un número entero positivo N. Realizar la traza para 
D=1 y X= 45673.  
b) Dado un número natural, indicar si el mismo es perfecto, abundante o deficiente.  
Nota: Un número natural X se dice que es deficiente si la suma de sus divisores (sin contarse a sí mismo) 
es menor a X. Si la suma de sus divisores es mayor a X se dice que el número es abundante y si es igual 
a X se dice que es perfecto. */

#include <stdio.h>


int perteneceRec(int, int);
void perfecto_abundante_deficiente(int,int, int);

int main (void){
    int num, digito, resultado,suma;
    suma=0;
    printf("ingrese un numero entero positivo: ");
    scanf("%d", &num);
    printf("ingrese un digito a buscar: ");
    scanf("%d", &digito);
    resultado=perteneceRec(num, digito);
    if(resultado==1)
        printf("el digito %d pertenece al numero %d\n", digito, num);
    else 
        printf("el digito %d no pertenece al numero %d\n", digito, num);
    printf("analisis de perfecto, abundante o deficiente:");
    perfecto_abundante_deficiente(num,1,suma);

    return 0;
}

int perteneceRec(int num, int bus){
    int dig;
    if(num>0){
        dig=num%10;
        if(dig==bus)
            return 1;
        else 
            return perteneceRec(num/10, bus);
    }
    return 0;
}

void perfecto_abundante_deficiente(int num, int i, int suma){
    if(i<=(num/2)){
        if(num%i==0)
            suma=suma+i;
        perfecto_abundante_deficiente(num, i+1, suma);
    }   
    else {
        if(num==suma)
            printf("\nel numero es perfecto.");
        else 
            if(suma>num)
                printf("\nel numero es abundante.");
            else
                printf("\nel numero es deficiente.");
    }
}   