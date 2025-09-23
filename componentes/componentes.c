#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>


/*#############################################################*/
int menu();
/*el menu simepre es una funcion*/
/*uso del menu*/

/*#############################################################*/
int nrorandom(int, int);
/*da un numero ranom entero en un intervalo*/
/*#############################################################*/
int defproducto(int, int);
/*#############################################################*/
int cantDivisores(int);
/*#############################################################*/
int determina_primo(int);
/*#############################################################*/
float comparacion(float, float);
/*compara y da un reultado de -1 1 0*/
/*#############################################################*/
int invertir(int); 
/*invierte los digitos de un numero*/
/*#############################################################*/




/*77777777777777777777777777777777777777777777777777777777777777777777777777777777777*/
int main(void){}
/*77777777777777777777777777777777777777777777777777777777777777777777777777777777777*/





/*#############################################################*/
int nrorandom(int x, int y){
    srand(time(NULL));
	int n;
	n=x+rand()%(y-x+1);
	/*variable = limite_inferior + rand()%(limite_superior - limite_inferior + 1)*/
	return n;
}

/*#############################################################*/
/*fuera del main*/
	
int menu(){
	int op;
	do
	{
		printf("\n**main menu**\n\n");
		printf("\n1) ver la raiz cuadrada de a.");
		printf("\n2) ver la potencia de a^b.");
		printf("\n3) ver el logaritmo en base 10 de b.");
		printf("\n0) salir.");
		printf("\ningrese una opcion: ");
		scanf("%d",&op);
		} while (op!=0);
	return op;
}
/*dentro del main */
		do{
			op=menu();
			switch (op){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
			}
		} while(op!= /salida del menu/);
/*#############################################################*/

 int defproducto(int a, int b){
    int i,r;
    r=a;
    for ( i = 1; i < b; i++)
        r=r+a;
    return r;
}

/*#############################################################*/

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

/*#############################################################*/

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

/*#############################################################*/

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

/*#############################################################*/

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

/*#############################################################*/
	

