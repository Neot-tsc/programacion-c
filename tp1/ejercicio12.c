#include <stdio.h>

int main(int argc, char *argv[]) {
	int cant, prom, may, men, i, edad, band, acu;
	band=1;
	acu=0;
	printf("\ningrese la cantidad de deportistas: ");
	scanf("%d",&cant);
	for(i=1; i<=cant; i++){
		printf("\ningrese la edad: ");
		scanf("%d", &edad);
		acu=acu+edad;
		if(band==1){
			may=edad;
			men=edad;
			band=0;
		}
		else{
		   if(may<edad)
			   may=edad;
		   if(men>edad)
			   men=edad;
		}
	}
	prom=acu/cant;
	printf("\nel promedio es:%d", prom);
	printf("\nel mayor es: %d\nel menor es: %d", may, men);
	return 0;
}

