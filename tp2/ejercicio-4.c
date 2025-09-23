#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*cabeceras de fun y pro*/
void menu(int, int);
int nrorandom(int, int);/*da un numero ranom entero en un intervalo*/



/*inicio del main*/

int main(void){
	int x,y;
	float a,b;
	printf("Ingrese un numero natural:");
	scanf("%d",&x);
	printf("Ingrese otro numero natural mayor que el anterior:");
	scanf("%d",&y);   
	if ((x>0 && y>0) && (x<y))
	{
		a=nrorandom(x,y);
		b=nrorandom(x,y);
		menu(a,b);
	}
	else
		printf("\n### error el segundo numero debe ser mayor al primero y ambos naturales ###\n");
	return 0;
}
	
	/*desarrollo de fun y pro*/
	
	
	int nrorandom(int x, int y){
        srand(time(NULL));
		int n;
		n=x+rand()%(y-x+1);
		/*variable = limite_inferior + rand()%(limite_superior - limite_inferior + 1)*/
		return n;
	}
		
		
		void menu(int a, int b){
			int op;
			do
			{
				printf("\n\n### el valor de a es: %d y el valor de es b: %d ###\n",a,b);
				printf("\n**main menu**\n\n");
				printf("\n1) ver la raiz cuadrada de a.");
				printf("\n2) ver la potencia de a^b.");
				printf("\n3) ver el logaritmo en base 10 de b.");
				printf("\n0) salir.");
				printf("\ningrese una opcion: ");
				scanf("%d",&op);
				
				switch (op){
				case 1:
					printf("\nla raiz cuadrada de a es: %.2f",sqrt(a));
					break;
				case 2:
					printf("\nla potencia de a^b es: %.2f",pow(a,b));
					break;
				case 3:
					printf("\nel logaritmo decimal de b es: %2.f", log10(b));
					break;
				case 0:
					printf("\n## programa terminado ##\n");
					break;
				default:
					if(op!=0)
						printf("\n## opcion ingresada incorrecta, ingrese una opcion valida ##\n");
				}
			} while (op!=0);
		}
