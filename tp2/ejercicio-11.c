/*Ejercicio 11: 
Dados una cantidad no determinada de números naturales, mostrar para cada uno de ellos 
si se trata de un número Deficiente, Abundante o Perfecto 
Nota: Un número natural X se dice que es deficiente si la suma de sus divisores naturales (excepto el 
mismo número) es menor a X. Si la suma de sus divisores es mayor a X, se dice que el número es 
abundante y si es igual a X se dice que es perfecto.*/

#include <stdio.h>

int suma_divisores(int);



int main (void){
    int n, sumdiv;
    do{ 
        printf("\ningrese un numero natural (ingrese cero para terminar el ingreso): ");
        scanf("%d",&n);
        sumdiv=suma_divisores(n);
        if(sumdiv==n)
            printf("\nel nuemro es percecto, numero: %d, suma de sus divisores: %d", n,sumdiv);
            else
                if(sumdiv>n)
                    printf("\nel numero es abundante, numero: %d, suma de sus divisores: %d", n,sumdiv);
                    else
                        if(sumdiv<n && n!=0)
                            printf("\nel numero es deficiente, numero: %d, suma de sus divisores: %d", n,sumdiv);
    } while (n>0);
    return 0;
}

int suma_divisores(int num){
    int r,i;
    r=0;
    for(i=1; i<=num/2; i++){
        if(num%i==0)
            r+=i;
    }
    return r;
}

