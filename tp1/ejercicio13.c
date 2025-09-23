#include <stdio.h>

int main(int argc, char *argv[]) {
	int cant,A,B,multA,multB,r,i;
	multA=0;
	multB=0;
	printf("\ningrese el valor de A:" );
	scanf("%d", &A);
	printf("\ningrese el valor de B:" );
	scanf("%d", &B);
	printf("\ningrese el tamaño de la lista: ");
	scanf("%d", &cant);
	for(i=1; i<=cant; i++){
		printf("\ningrese un numero entero: ");
		scanf("%d", &r);
		if(r>0){
			if(r%A==0)
				multA++;
			if(r%B==0)
				multB++;
		}
	}
	printf("\ncantidad de multiplos de A:%d", multA);
	printf("\ncantidad de multiplos de B:%d", multB);
	return 0;
}

