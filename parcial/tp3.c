/*Ejercicio 9: Dada una cantidad no determinada de números naturales, para cada número natural primo, 
calcular su número invertido y para cada número natural no primo (compuesto) modificarlo eliminando 
todos sus dígitos primos.*/
#include <stdio.h>



int invertido(int);
int es_primo(int);
int elimina_dig_primos(int);

int main(){
    int n,aux;
    do
    {
        printf("\ningrese un umero natural para continuar o (0) si quiere terminar el programa:");
        scanf("%d", &n);
        aux=n;
        if(n>0){
            if(es_primo(n))
                printf("\nel numero ingresado es primo:%d, su nvertdio es:%d",n, invertido(n));
            else
                printf("\nel numero ingresado no es primo:%d, el numero resutado de eliminar sus dijitos primos es %d",n,elimina_dig_primos(n));
        }      
        else
            printf("\nel numero ingresado es un numero no natural, por favor ingrese un numero natural.");
    } while (aux!=0);
    printf("\n saliendo del programa.....");
    
    return 0;
}




int invertido(int n){
    int aux, invertido;
    invertido=0;
    while(n>0){
        aux=n%10;
        invertido=invertido*10+aux;
        n=n/10;
    }
    return invertido;
}
//tiene en cuenta si n es negativo por lo que devuelve 1 0 -1
int es_primo(int n){
    int pd,r;
    pd=2;
    if(n>0){
        while((pd<=n/2)&&(n%pd!=0))
            pd++;
        if((pd>n/2)&&(n!=1))
            r=1;
        else 
            r=0;
    }
    else 
        r=-1;

    return r;
}


int elimina_dig_primos(int n){
    int dig, aux;
    aux=n;
    while(aux>0){
        dig=aux%10;
        if(es_primo(dig)==1)
            n=n/10;
        aux=aux/10;
    }
    return n;
}

