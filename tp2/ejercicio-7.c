#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int cantDivisores(int);
int determina_primo(int);
float comparacion(float, float);
int invertir(int);


void menu(int, float, float);


int main(void){
    int x;
    float a,b;
    menu(x,a,b);
    return 0;
}

int cantDivisores(int num){
    int i, cant;
    cant=1;
    for ( i = 1; i<num/2; i++)
    {
        if(num%i==0)
        cant++;
    }
    return cant;
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

float comparacion(float a, float b){
    int r;
    if(a>b)
    r=1;
    else
    {
        if(a<b)
        r=-1;
        else
        r=0;
    }
    return r;
}

int invertir(int num){
    int invertido, aux;
    aux=num;
    invertido=0;
    while(aux!=0){
        invertido=invertido*10+aux%10;
        aux=aux/10;
    }
    return invertido;
}

void menu(int x, float a, float b){
	int op;
	do
	{
		printf("\n\n**main menu**\n\n");
		printf("\n1) calcular la cantidad de divisores naturales de un numero natural x");
		printf("\n2) determinar si un numero es primo");
		printf("\n3) comparar dos numeros reales");
        printf("\n4) invertir un numero entero");
		printf("\n0) salir.");
		printf("\ningrese una opcion: ");
		scanf("%d",&op);
				
		switch (op){
			case 1:
                printf("\ningrese un numero natural: ");
                scanf("%d", &x);
				printf("\nla cantidad de divisores de %d es: %d",x, cantDivisores(x));
				break;
			case 2:
                printf("\ningrese un numero natural: ");
                scanf("%d", &x);
				if(determina_primo(x))
                    printf("\n %d es primo", x);
                else
                    printf("\n %d no es primo", x);
				break;
			case 3:
                printf("\ningrese un numero real: ");
                scanf("%f", &a);
                printf("\ningrese otro numero real: ");
                scanf("%f", &b);
				printf("\nel resultado de la comparacion es: %f", comparacion(a,b));
				break;
            case 4:
                printf("\ningrese un numero entero: ");
                scanf("%d", &x);
                printf("\n el numero invertido es: %d", invertir(x));
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
