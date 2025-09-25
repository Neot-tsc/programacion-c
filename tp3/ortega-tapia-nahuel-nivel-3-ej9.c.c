/*Ejercicio 9: Dada una cantidad no determinada de números naturales, para cada número natural primo, 
calcular su número invertido y para cada número natural no primo (compuesto) modificarlo eliminando 
todos sus dígitos primos.*/

#include <stdio.h>

int invertir(int);
int determina_primo(int);

int main (void){
    int n,aux,nuevo,dig;
    do
    {
        printf("\ningrese un numero natural (0 para terminar): ");
        scanf("%d",&n);
        if(n<0)
            printf("\nel numero debe ser natural, ingrese otro numero");
            else{
                if(n!=0){
                    if(determina_primo(n))
                        printf("\nel numero %d es primo y su invertido es %d",n,invertir(n));
                    else{
                        nuevo=0;
                        aux=n;
                        while(aux!=0){
                            dig=aux%10;
                            if(!determina_primo(dig)){
                                nuevo=nuevo*10+dig;
                            }
                            aux=aux/10;
                        }
                        printf("\nel numero %d es compuesto y su modificacion es %d",n,invertir(nuevo));
                    }
                }
            }
    } while (n!=0);
    



    return 0;
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

int determina_primo(int num){
	int r;
    if(num>0){
        int pd=2;
        while((pd<=num/2) && (num%pd!=0))
        pd++;
        if((pd>num/2) && num!=1)
			r=1;
		else
			r=0;
    }
	
	return r;
}
