/*ejercicio 4: Cree un programa que ingrese una fracción de la forma A/B y que a continuación devuelva 
la fracción irreductible equivalente. ejemplo se A= 6 y B= 8; ( 6 / 8 )entonces Ar= 3 y Br= 4 ( 3 / 4 ) Nota: 
Generar un procedimiento que reciba A y B, que devuelva Ar y Br*/

#include <stdio.h>

void entradafraccion(int*, int*);
void salidafraccion(int, int);
int simplificar(int, int);


int main (void){
    int A, B, Ar, Br, mcd;
    entradafraccion(&A, &B);
    mcd=simplificar(A, B);
    Ar=A/mcd;
    Br=B/mcd;
    salidafraccion(Ar, Br);
    return 0;
}


void entradafraccion(int*numerador, int*denominador){
    printf("\ningrese el numerador: ");
    scanf("%d",numerador);
    do
    {
        printf("ingrese un denominador distinto de 0:");
		scanf("%d",denominador);
    } while (denominador==0);
}

void salidafraccion(int numerador, int denominador){
	if(numerador==0 || denominador==1)
		printf("%d\n", numerador);
	else 
		printf("\n%d/%d\n",numerador,denominador);
}

int simplificar(int a, int b){
    int i, mcd=1;
    for(i=1; i<=a; i++){
        if(a%i==0 && b%i==0)
            mcd=i;
    }
    return mcd;
}