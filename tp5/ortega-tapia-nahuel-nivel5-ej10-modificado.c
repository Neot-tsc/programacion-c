/*ejercicio 10 (modificado): se tiene los datos de un circulo. cullos datos son :
nombre, el punto central(coordenadas x,y)) y el radio. 
se solicita ingresar N puntos del plano y para cada punto ingresado, indicar si punto es interior
o exterior.
nota: usar TD registro para representar cada circuo y cada punto*/



#include <stdio.h>
#include <math.h>

//definicion de variable global
#define max 50

//definicion del tipo de dato cadena
typedef char Tcad[max];

//definicion del TDstruct de punto del circulo
typedef struct{
	float x,y;
}punto;

//definicion del TDstruct del circulo
typedef struct{
	Tcad nombre;
	punto coordenada;
	float radio;
}Tdatos;

//definicion del vector de puntos a evaluar
typedef punto puntos[max];

//###funcion y procedimientos### 

//procedimiento de ingreso de cadena
void leecad(Tcad);

//funciones y procedimientos de strct Tdato
Tdatos ingresa_uno();

//funciones y procedimientos del vector puntos
punto ingresa_un_punto();
void cargar_puntos(puntos, int*);
void mostrar_puntos(puntos, int);
float distancia(punto, punto);

//procedimiento que evalua el Tdatos y el vector de puntos
void evaluar(Tdatos, puntos, int);


//inicio de la funcion main
int main(int argc, char *argv[]) {
	Tdatos circulo;
	puntos p;
	int n;
	circulo=ingresa_uno();
	cargar_puntos(p,&n);
	mostrar_puntos(p,n);
	evaluar(circulo,p,n);
	return 0;
}

//cuerpo de las funciones y rocedimientos en orden
void leecad(Tcad cad){
	int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<max-1){
		cad[j]=c;
		j++;
		c=getchar();
	}
	cad[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}

Tdatos ingresa_uno(){
	Tdatos aux;
	printf("\ningrese el nombre del circulo: ");
	leecad(aux.nombre);
	printf("\ningrese el punto (x,y):");
	scanf("%f",&aux.coordenada.x);
	scanf("%f",&aux.coordenada.y);
	printf("\ningrese el radio del circulo:");
	scanf("%f", &aux.radio);
	return aux;
}

punto ingresa_un_punto(){
	punto aux;
	printf("\ningrese el punto (x,y):");
	scanf("%f", &aux.x);
	scanf("%f", &aux.y);
	return aux;
}

void cargar_puntos(puntos p, int *n){
	int i;
	printf("\ningrese el tamanio de la lista:");
	scanf("%d", n);
	for(i=1; i<=*n; i++)
		p[i]=ingresa_un_punto();
}

void mostrar_puntos(puntos p, int n){
	int i;
	printf("\nlista de puntos a evaluar\n");
	for (i=1; i<=n; i++)
	{
		
		printf("\npunto %d:(x,y)= (%.2f,%.2f)", i,p[i].x, p[i].y);
	}
	
}
float distancia(punto centro, punto evaluar){
	float d, primero, segundo, ambos;
	primero=pow(evaluar.x-centro.x,2);
	segundo=pow(evaluar.y-centro.y,2);
	ambos=primero+segundo;
	d=sqrt(ambos);
	return d;
}
	
void evaluar(Tdatos c, puntos p, int n){
	float dis;
	int i;
	for(i=1; i<=n; i++){
		dis=distancia(c.coordenada,p[i]);
		if(dis<c.radio)
			printf("\nel punto (%.2f,%.2f) es punto interior del circulo", p[i].x,p[i].y);
		else if(dis==c.radio)
				printf("\nel punto (%.2f,%.2f), es un punto sobre el circulo", p[i].x,p[i].y);
				else 
					printf("\nel punto (%.2f,%.2f), es un punto exterior", p[i].x,p[i].y);
	}
}
