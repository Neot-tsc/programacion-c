#include <stdio.h>
#include <stdlib.h>


int es_par(int);


int main(int argc, char *argv[]) {
	float n;
	int r,aux;
	while(n>0){
		printf("\ningrese un numero natural:");
		scanf("%f",&n);
		aux=(int)n;
		if(r=es_par(aux))
			printf("\nes par");
		else
			printf("\nno es par");
	}
	return 0;
}

int es_par(int a){
	int r;
	if(a%2==0)
		r=1;
	else 
		r=0;
	return r;
}
