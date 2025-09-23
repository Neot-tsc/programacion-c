#include <stdio.h>
/*dadas n notas tener el promedio de las notas pares e impares*/

int main(int argc, char *argv[]) {
	int n, i, canpar, canimpar,acupar, acuimpar, nota;
	float  promimpar, prompar;
	canimpar=0;
	canpar=0;
	acuimpar=0;
	acupar=0;
	printf("\ningrese la cantidad de notas: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		printf("\ningrese una nota: ");
		scanf("%d", &nota);
		if(nota%2==0){
			canpar++;
			acupar+=nota;
		}
		
		else{
			canimpar++;
			acuimpar+=nota;
		}
	}
	if(canpar!=0 && acupar!=0){
		prompar=(float)acupar/canpar;
		printf("\npromedio de las notas pares: %f", prompar);		
	}
	else
	   printf("\nel promedio par no es posible de calcuar: divicion por 0");
	if(canimpar!=0 && acuimpar!=0){
		promimpar=(float)acuimpar/canimpar;
		printf("\npromedio de las notas impares: %f", promimpar);
	}
	else
	   printf("\nel promedio impar no es posible de calcuar: divicion por 0");
	
	return 0;
}

