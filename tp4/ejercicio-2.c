#include <stdio.h>

typedef int Tlista[50];

void ingreso_vector(Tlista,int*);
void mostrar_vector(Tlista, int);



int main(int argc, char *argv[]) {
	Tlista A;
	int n;
	ingreso_vector(A,&n);
	mostrar_vector(A,n);
	
	
	return 0;
}

void ingreso_vector(Tlista A,int *n){
	int i;
	printf("\ningrese el tamaño del vector: ");
	scanf("%d",n);
	for(i=1; i<=*n; i++){
		printf("ingrese un elemento del vector: ");
		scanf("%d",&A[i]);
	}
}

	
void mostrar_vector(Tlista A, int n){
	int i;
	printf("elementos del vector:");
	for(i=1; i<=n; i++)
		printf("%d",A[i]);
	} 	
