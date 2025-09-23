#include <stdio.h>
/*precentar el ejercicio 16 e jueves*/

int main(int argc, char *argv[]) {
	int dig;
	printf("\ningrese un digito: ");
	scanf("%d",&dig);
	switch(dig){
		case 1:printf("%d=uno", dig); break;
		case 2:printf("%d=dos", dig); break;
		case 3:printf("%d=tres", dig); break;
		case 4:printf("%d=cuatro", dig); break;
		case 5:printf("%d=cinco", dig); break;
		case 6:printf("%d=seis", dig); break;
		case 7:printf("%d=ciete", dig); break;
		case 8:printf("%d=ocho", dig); break;
		case 9:printf("%d=nueve", dig); break;
		case 0:printf("%d=cero", dig); break;
		default:
			printf("\nno se introdujo un digito.");
	}
	
	return 0;
}

