/*Ejercicio 15: 
Dada una lista de números naturales se solicita mostrar los números que están formados 
solo por dígitos pares. Además, mostrar el menor y el mayor de estos números (de los que cumplen la 
condición).*/

#include <stdio.h>

int determinacion_dig_pares(int);
int separar_uno(int*);

int main(void){
    int n,may,men,ban;
    ban=1;
    printf("\ningres un numero natural (ingreser 0 para terminar): ");
    scanf("%d",&n);
    do
    {
        if(n>0){
			if(determinacion_dig_pares(n)==1){
				if(ban!=1){
					printf("\n el numero %d esta formado solo por digitos pares",n);
					if(n>may){
						may=n;
					}
					else {
						if(n<men)
							men=n;
					}
				}
				else {
					printf("\n el numero %d esta formado solo por digitos pares",n);
					may=n;
					men=n;
					ban=0;
				}
			}
		}
        printf("\ningres un numero natural (ingreser 0 para terminar): ");
        scanf("%d",&n);
    }
    while (n!=0);
        printf("\n el mayor numero formado solo por digitos pares es: %d",may);
        printf("\n el menor numero formado solo por digitos pares es : %d",men);
        return 0;
    }

int separar_digitos(int *num){
    int d;
    d=*num%10;
    *num=*num/10;
    return d;
}

int determinacion_dig_pares(int num){
    int r=1, dig;
    while(num>0 && r==1){
        dig=separar_digitos(&num);
        if(dig%2!=0)
            r=0;
    }
    return r;
}
