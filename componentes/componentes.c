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
void entradafraccion(int*, int*);
void salidafraccion(int, int);
/*#############################################################*/
int maximo_comun_divisor(int, int);

/*obtiene el maximo comun divisor*/
/*#############################################################*/
#define base 10

void separa_entero_decimal(float, int*, int*);
/*separa la parte entera de la parte decimal y 
conbierte la parte decimal en etera (solo 4 digitos de precicion)*/
/*#############################################################*/

int cuenta_digitos(int);

/*#############################################################*/
/*PROCEDIMIENTOS Y FUNCIONES DE VECTORES*/

typedef int Tlista [10]; /*resuerda que camvia con respecto al tipo de dato ya sea int, float, char, etc*/
/*entrada condicionada*/
void ingreso_condicionado_vector(Tlista,int*); /*ingresa la lista y conoce el tama�o dentro del procedimiento*/
void mostrar_vector(Tlista, int); 
/*entrada incondicionada*/

void ingreso_incondicionado_vector(Tlista,int*);

/*#############################################################*/

void ordenamiento_seleccion_directa(Tlista, int);

/*#############################################################*/
void insertar_un_elemento_al_final(Tlista, int* );

/*#############################################################*/
void insertar_un_elemento(Tlista, int*, int, int);

/*#############################################################*/
void eliminar_un_elemento(Tlista,int*);

/*#############################################################*/
/*de un vector*/
void mostrar_primos(Tlista, int);

/*#############################################################*/

	/*encuentra la posicion de manera ordenada*/

int determinar_pos(Tlista , int , int );
	
	/*inserta un numero en el vector manteniendo el orden, recibiendo el nuevo y la pos*/
	
void insertar_un_elemento(Tlista , int*, int, int);
	
	/*inserccion de baraja (inserta manteniendo el orden)*/
	
void insertar_baraja_tamaño_conocido(Tlista , int );
void insertar_baraja_tamaño_desconocido(Tlista a, int *n);
int busqueda_binaria(Tlista , int , int);
int busqueda_secuencial(Tlista, int, int);	

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
		printf("\n**main menu**\n\n");
		printf("\n1) ver la raiz cuadrada de a.");
		printf("\n2) ver la potencia de a^b.");
		printf("\n3) ver el logaritmo en base 10 de b.");
		printf("\n0) salir.");
		printf("\ningrese una opcion: ");
		scanf("%d",&op);
	
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
	int r,pd;
    pd=2;
    if(num>0){
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

/*#############################################################*/

int maximo_comun_divisor(int a, int b){
    int i, mcd=1;
    for(i=1; i<=a; i++){
        if(a%i==0 && b%i==0)
            mcd=i;
    }
    return mcd;
}

/*#############################################################*/
/*trabaja en conunto con cuentadigito
y definiendo constante en 10 asi evalua sin inportar
los digitos de precicion mas libreria math.h*/
void separa_entero_decima(float x, int *entero, int *decimal){
	int cant;
    float aux;
    aux=x;
    *entero=(int)x;
    aux=x-(int)x;
    cant=cuenta_digitos(aux); 
    *decimal=aux*pow(base,cant);
}

/*#############################################################*/

int cuenta_digitos(int num){
    int cant;
    cant=0;
    while (num!=0)
    {
        num=num/10;
        cant++;
    }
    return cant;
}


/*#############################################################*/
/*#############################################################*/
/*#############################################################*/
/*#############################################################*/

	
	
void ingreso_condicionado_vector(Tlista A,int *n){
	int i;
	printf("\ningrese el tama�o del vector: ");
	scanf("%d",n);
	for(i=1; i<=*n; i++){
		printf("ingrese un elemento del vector: ");
		scanf("%d",&A[i]);
	}
}

void mostrar_vector(Tlista A, int n){
	int i;
	printf("elementos del vector:");
	for(i=1; i<=n; i++)
		printf("%d,",A[i]);
} 
	
void ingreso_incondicionado_vector(Tlista A, int *n)
{
    int i;
    i=1;
    do
    {
        printf("ingrese un elemento: ");
        scanf("%d", A[i]);
        i++;
    } while (A[i]!=0);
    i--;
    *n=i;
}


void agregar_uno(Tlista a, int*n, int nuevo){
    int i;
    i=*n;
    a[0]=nuevo;
    while(a[i]>nuevo){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=nuevo;
    *n=*n+1;
}


	/*encuentra la posicion de manera ordenada*/
int determinar_pos(Tlista a, int n, int x){
	int i,ban,pos; 
	i=1;
	ban=1;
	while(ban==1){
		if(a[i]<x && a[i+1]>x){
			pos=1;
			ban=0;
		}
	}
	return pos;
}

void insertar_un_elemento(Tlista a, int* n, int nuevo, int pos){
	int i;
	for(i=1; i<=pos; i++)
		a[i+1]=a[i];
	a[pos]=nuevo;
	*n=*n+1;
}

	/*inserccion de baraja (inserta manteniendo el orden)*/

void insertar_baraja_tamanio_conocido(Tlista a, int n){
	int i, j;
	i=1;
	printf("\ningrese un elemento:");
	scanf("%d", &a[i]);
	for(i=2; i<=n; i++){
		printf("\ningrese un elemento:");
		scanf("%d", &a[i]);
		a[0]=a[i];
		j=i-1;
		while(a[0]<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
}

	/*inserccion de baraja (inserta manteniendo el orden)*/

void insertar_baraja_tama�o_desconocido(Tlista a, int *n){
	int i,j;
	*n=1;
	do{
		printf("\ningrese un elemento (igrese 0 para terminar)");
		scanf("%d",&a[i]);
		a[0]=a[i];
		j=i-1;
		while(a[0]<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
		*n=*n+1;
	}while (a[i]!= 0);/*la condicion tiene que ser distinta*/
	*n=*n-1;
}	

int busqueda_binaria(Tlista a, int n, int buscado){
	int ini, fin, med, r;
	ini=1;fin=n;med=(ini+fin)/2;
	while(ini<=fin && a[med]!=buscado){
		if(a[med]<buscado)
			ini=med++;
		else 
			fin=med--;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		r=med;
	else
		r=0;
	return r;
}
	
int busqueda_secuencial(Tlista a, int n, int buscado){
	int i,pos;
	i=1;
	while(i<=n && a[i]!= buscado)
		i++;
	if(i<n)
		pos=i;
	else pos=0;
	return pos;
}
	
	



