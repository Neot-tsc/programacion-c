/*Dados los siguientes programas,
- Identificar las partes del programa (estructura), utilizando comentarios
- indicar cada objeto de programa (sentencia simple, sentencia compuesta o sentencia estructura; si es un identificador de variable
- de cte, de tipo de datos, de módulo, etc)
- Indicar datos de entrada, de salida y funcionalidad del programa (qué hace)*/

/*a) introcude una fecha correcta  */ 
#include <stdio.h>
	
	
	int main (void){
	int d,m,a;    /*declaracion de variables locales*/
	printf("ingrese los datos: "); /*cartel de ingreso de datos*/
	scanf("%d", &d); 
	scanf("%d", &m);   /*asignacion de datos a una variable por teclado*/
	scanf("%d", &a);
	if (m<1||m>12)   /*disyuncion*/
		printf("\ndatos no validos");
	else
		if (a<1900 || a>2024)
			printf("\ndatos no validos");
		else
			if(d<1 || d>31)
			printf("\ndatos no validos");
			else 
				printf("\ndatos validos");
		return 0;
}
	
