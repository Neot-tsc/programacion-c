#include <stdio.h>
/*Ejercicio 16:  
Dado un número natural K de dos cifras, se pide mostrar los números naturales 
primos que le anteceden. Por ejemplo, si K= 12 la salida será {2, 3, 5, 7, 11).*/
int main(int argc, char *argv[]) {
	int k,i,pd, tm;
	printf("\ningrese un numero natural de dos cifras:");
	scanf("%d",&k);
	if(k>0 && k<100){
		printf("\nnumeros primos que le anteceden:");
		tm=k;
		for(i=1; i<tm; i++){
			pd=2;
			while(pd<=i/2 && i%pd!=0)
				pd++;
			if(pd>i/2 && i!=1)
				printf("%d, ", i);
		}
		
	}
	else {
	   if(k<0)
	   printf("\nno es un numero natural.");
	   else
		   printf("\nel numero ingresado tiene mas de 2 cifras.");
	}
	
	return 0;
}

