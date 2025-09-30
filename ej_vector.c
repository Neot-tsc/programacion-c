#include <stdio.h>
/*Dada una lista conteniendo una cierta cant de números naturales,
mostrar aquellos cuyos dígitos son todos impares y luego mostrar cuáles 
de los números ingresados son mayores al promedio de los que cumplen.
*/
typedef enum {falso,verdad}logico;
typedef int TLista[20];

void ingresa(TLista, int*);
void muestra_todos(TLista, int );
void muestra_cumple(TLista, int );
logico cumple(int);
int ingresa_entero(void);
float promedio(TLista,int);
void muestra_may_prom(TLista, int );
logico hay_cumple(TLista, int);
	
int main(void) {
	TLista vec;
	int tam;
	ingresa(vec,&tam);
	/*muestra_todos(vec,tam);
	*/
	muestra_cumple(vec,tam);
	if (hay_cumple(vec,tam))
		muestra_may_prom(vec,tam);
	return 0;
}

void ingresa(TLista A, int* N)
{
	int i;
	i=0;
	do
	{
		i++;
		A[i]=ingresa_entero();
	}while(A[i]>0);
	*N=--i;
}
int ingresa_entero(void)
	{int a;
	printf("Ingrese un num ");
	scanf("%i",&a);
	return(a);
}
void muestra_cumple(TLista A, int n)
	{ int i;
 logico band_sal;
	band_sal=falso;
	for(i=1;i<=n;i++)
	{
		if (cumple(A[i])){
			band_sal=verdad;
			printf(" %i",A[i]);
		}
	}
	if (!band_sal)
		printf("\nNo hay elemento que cumpla");
}

void muestra_may_prom(TLista A, int n)
{ int i;
float prom;
 logico band_sal;
band_sal=falso;
prom=promedio(A,n);
printf("\nlos mayores al promedio son: ");
for(i=1;i<=n;i++)
{
	if (A[i]>=prom && cumple(A[i])){
		band_sal=verdad;
		printf("\t %i",A[i]);
	}
}
if (!band_sal)
	printf("\nNo hay elemento que sean mayores al promedio");
}

void muestra_todos(TLista A, int n)
{ int i;
printf("\n");
for(i=1;i<=n;i++)
	printf(" %i",A[i]);
}

 logico cumple(int num)
{
	while(num!=0 && num%10%2==1)
		num/=10;
	return (num==0)? verdad:falso;
}

float promedio(TLista A, int n)
{
	int i,c;
	float p;
	p=0;
	c=0;
	for(i=1;i<=n;i++)
		if(cumple(A[i]))
		{
			p+=A[i];
			c++;
		}
	p/=c;
	return p;
}

logico hay_cumple(TLista A, int n)
{
	int i;
	i=1;
	while (i<=n && !cumple(A[i]))
		i++;
	return(i>n)? falso:verdad;
}
