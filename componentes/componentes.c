#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define max 50

typedef char Tcad[max];


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

typedef int Tlista [max]; /*resuerda que camvia con respecto al tipo de dato ya sea int, float, char, etc*/
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
void eliminar_un_elemento(Tlista,int*,int);

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

void ordenamiento_seleccion_directa(Tlista lista, int n){
	int i,j;
	int aux;
	for (i=1; i<n; i++)
	{
		for(j=i+1; j<=n; j++){
			if(lista[j]<lista[i]){
				aux=lista[j];
				lista[j]=lista[i];
				lista[i]=aux;
			}
		}
	}
	
};

void ordena_secuencial(Tlista a, int n){
	int i,j,aux;
	for(i=1; i<n; i++){
		for(j=i+1; j<=n; j++){
			if(a[j]<a[i]){
				aux=a[j];
				a[j]=a[i];
				a[i]=aux;
			}
		}
	}
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
	/*inserta un numero en el vector manteniendo el orden*/
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
	ini=1;fin=n;med=(ini+fin)/2;r=0;
	while(ini<=fin && a[med]!=buscado){
		if(a[med]<buscado)
			ini=med++;
		else 
			fin=med--;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		r=med;
	return r;
}
	
int busqueda_secuencial(Tlista a, int n, int buscado){
	int i,pos;
	pos=0;
	i=1;
	while(i<=n && a[i]!= buscado)
		i++;
	if(i<n)
		pos=i;
	return pos;
}

void leecad(Tcad cadena){/*no ingreso tamaio maximo or que es una variable global max
	*/
	int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<max-1){
		cadena[j]=c;
		j++;
		c=getchar();
	}
	cadena[j]='\0';
	while (c!=EOF && c!='\n')
		c=getchar();
}




void agrega_uno_rec(Tlista a, int pos, int nuevo) {

    if (pos <= 0 || a[pos] <= nuevo) {
        a[pos + 1] = nuevo;
        return;
    }
    a[pos+1] = a[pos];
    agrega_uno_rec(a, pos-1, nuevo);
}

/* Wrapper que verifica límites y llama a la función recursiva */
void agrega_uno(Tlista a, int *n, int nuevo) {
    if (*n >= max) {
        printf("\nLista llena");
        return;
    }
    a[0] = nuevo;
    agrega_uno_rec(a, *n, nuevo);
    (*n)++;
}




// tamanio de cadena contando el espacio 0
 int t;
 int tam_cad(Tcad);
 int tam_cad(Tcad cadena){
	int i;
	i=0;
	while(cadena[i]!='\0')
		i++;
	return i;
 }


/*#######################################################################################################
##########################################################################################################*/

// tipo de dato STRUCT
// estructuras anidadas
typedef struct 
{
    int dia,mes,anio;
}calendario;

typedef struct
{
    Tcad cuidad,barrio,calle,departamento;
    int numero;
}ubicacion;

typedef struct 
{
    Tcad apeynom;
    long int DNI;
    calendario fecha;
    ubicacion domicilio;
}Dpersonales;

typedef Dpersonales datos[max];

 //dentro del main

int main(void){
	datos alumno;

	return 0;
}
 //funciones y procedientos de struct


//cargar uno 

Dpersonales retorna_uno(){
	Dpersonales aux;
    printf("ingrese nombre:");
	fflush(stdin);
	leecad(aux.apeynom);
	printf("ingrese el dni:");
	scanf("%ld", &aux.DNI);
	printf("ingrese el barrio donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.barrio);
    printf("ingrese la ciudad donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.cuidad);
    printf("ingrese la calle donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.calle);
    printf("ingrese el departamento donde vive: ");
    fflush(stdin);
    leecad(aux.domicilio.departamento);
    printf("ingrese el numero de casa: ");
	scanf("%d", &aux.domicilio.numero);
	printf("ingrese el dia de nacimiento: ");
	scanf("%d", &aux.fecha.dia);
	printf("ingrese el mes de nacimiento: ");
	scanf("%d", &aux.fecha.mes);
	printf("ingrese el anio de nacimiento: ");
	scanf("%d", &aux.fecha.anio);
	return aux;
};

void genera_vector(datos personales, int*n){
    int i;
    printf("\ningres el tamanio del vector:");
    scanf("%d",n);
    for (i=1; i<=*n; i++){
        printf("\ningrese los datos de la persona %d\n",i);
        personales[i]=agrega_uno();
    }
}

void mostrar_uno(Dpersonales datos){
    printf("\napellido y nombre: %s",datos.apeynom);
    printf("\nDNI: %ld", datos.DNI);
    printf("\nfecha de nacimiento: %d/%d/%d",datos.fecha.dia,datos.fecha.mes,datos.fecha.anio);
    printf("\nciudad donde vive: %s",datos.domicilio.cuidad);
    printf("\ndepartamento donde vive: %s",datos.domicilio.departamento);
    printf("\nbarrio donde vive: %s",datos.domicilio.barrio);
    printf("\ncalle donde vive: %s",datos.domicilio.calle);
    printf("\nnum de cada: %d",datos.domicilio.numero);
}

void mostrar_vector(datos datos, int n){
    int i;
    printf("\nelementos del vector");
    for (i=1; i<=n; i++){
        printf("\n\ndatos de la persona %d\n",i);
        mostrar_uno(datos[i]);
    }
}

//cargar lista ordenada en vectores de tad sin repetidos



	void baraja(Tlista a, int *n){
	int i,j,ban=1;
	i=0;
	do{
		i++;
		a[i]=nuevo();
		if(a[i]!=0){/*distinto a la salida para finalizar la entrada*/
			if(esta(a,i,a[i])){//verifica si existe o no para ingresar
				a[0]=a[i];
				j=i-1;
				while(a[0]<a[j]){
					a[j+1]=a[j];
					j--;
				}
				a[j+1]=a[0];
			}
			else
				i--;//si el valor es repetido disminuye el 
			//tamanio para semtener la depuracion
		}
		else 
		   ban=0;
	}while(ban==1);
	*n=i-1;
}	
//esta funcion solo funciona con la baraja de arriba,
//evalua que no aya repetido en el vector
int esta(Tlista a, int n, int nuevo){
	int r=1;
	int i=1, ban=1;
	while(i<n && ban==1){
		if(a[i]== nuevo){
			ban=0;
			r=0;
		}
		i++;
	}
	return r;
}

void eliminar_un_elemento(Tlista a,int* n, int pos){
	int i;
	for(i=pos; i<*n; i++)
		a[i]=a[i+1];
	(*n)--;
}
void insertar_un_elemento(Tlista a, int* n, int pos, int nuevo){
	int i;
	for(i=*n; i>=pos; i--)
		a[i+1]=a[i];
	a[pos]=nuevo;
	(*n)++;
}




/*TAD (TIPO ABSTRACTO DE DATO)*/







/*############################################################################*/

//recursividad


int factorial(int n){
    if(n==0)
        return 1;
    else 
        return n*factorial(n-1);
}

//mostrar los digitos de derecha a izquierda


void mostrar_der_iz(int n){ // recursivo
	int dig;
	if(n>0){
		dig=n%10;
		printf("%d", dig);
		mostrar_der_iz(n/10);
	}
}

void mostrar_iz_der(int n){
	int dig;
	if(n>0){
		mostrar_iz_der(n/10);
		dig=n%10;
		printf("%d", dig);
	}
}
	

int contar_dig(int n){
	if(n>0){
		return 1+contar_dig(n/10);
	}
	return 0;
}

int suma(int n){
	int d;
	if(n>0){
		d=n%10;
		return d+suma(n/10);
	}
	return 0;
}

void divisores(int n, int i){
	if(i<n){
		if(n/i==0){
			i++;
			divisores(n,i);
			printf("%d", i);
		}
	}
}

int fibonacci(int n){
	if(n==1 || n==2)
		return 1;
	else 
		return fibonacci(n-1)+fibonacci(n-2);
}


//busqueda binaria recursiva
//ya se pasan los parametros ini y fin antes de llamar a la funcion

int busqueda_binaria_recursiva(Tlista a, int ini, int fin, int buscado){
	int med;
	med=(ini+fin)/2;
	if(ini>fin)
		return 0;
	else{
		if(a[med]==buscado)
			return med;
		else {
			if(a[med]<buscado)
				return busqueda_binaria_recursiva(a, med+1, fin, buscado);
			else 
				return busqueda_binaria_recursiva(a, ini, med-1, buscado);
		}
	}
}

//busqueda secuancual recursiva
int busqueda_secuencial_recursiva (Tlista a, int n, int buscado){
	if(n==0)
		return 0;
	else{
		if(a[n]==buscado)
			return n;
		else 
			return busqueda_secuencial_recursiva(a, n-1, buscado);
	}
}

//quick sort
//metdo de ordenamiento en base a sub listas generadas por un pivote

void quick_sort(Tlista a, int ini, int fin){
	int izq,der,piv;
    if(ini < fin){
        izq = ini;
        der = fin;
        piv = a[ini];
        
        while(izq < der){
            while(izq < der && a[der] >= piv)
                der--;
            if(izq < der)
                a[izq] = a[der];
            while(izq < der && a[izq] <= piv)
                izq++;
            if(izq < der)
                a[der] = a[izq];
        }
        a[izq] = piv;  
        quick_sort(a, ini, izq-1);
        quick_sort(a, izq+1, fin);
    }
}


//M-sort recursivo
//marge sort
//consta de dos partes este metodo de ordenamiento

void marge(Tlista a, int ini, int med, int fin){
	Tlista aux;
	int i,j,k,t;
	k=0;
	i=ini;
	j=med+1;
	while(i<=med && j<=fin){
		k++;
		if(a[i]<a[j]){
			aux[k]=a[i];
			i++;
		}
		else{
			aux[k]=a[j];
			j++;
		}
	}
	for(t=i; t<=med; t++){
		k++;
		aux[k]=a[t];
	}
	for(t=j; t<=fin; t++){
		k++;
		aux[k]=a[t];
	}
	for(t=1; t<=k; t++)
		a[ini+t-1]=aux[t];
}

void m_sort(Tlista a, int ini, int fin){
	int med;
	if(ini<fin){
		med=(ini+fin)/2;
		m_sort(a, ini, med);
		m_sort(a, med+1, fin);
		marge(a, ini, med, fin);
	}
}


void cargar_listaRec(Tlista B,int tam)
{  					 /*Caso base tam=0*/ 
     if(tam>0){
         cargar_listaRec(B,tam-1);
         printf("/ningrese el elemento:");
         scanf("%d",&B[tam]);
     }
}

void cargar_lista(Tlista vector,int *t){
	printf("\n Ingrese cdad elementos: ");
	scanf("%d",t);	
	cargar_listaRec(vector,*t);
}


void mostrar_listaRec(Tlista vector,int tam)
{	
	/*Caso base tam=0 */
    if(tam>0){
        mostrar_listaRec(vector,tam-1);
        printf("vector[tam]");
    }
		
}
void mostrar_lista(Tlista vector,int tam)
{	
	if(tam==0) printf("\n\nEl vector NO tiene elementos");
	else{
		printf("\n\nLista de elementos");
		mostrar_listaRec(vector,tam);		
	}
	
}


void elimina_recursivo(Tlista B, int *Tam,int pos){
	
	if(pos<=*Tam){
         B[pos]=B[pos+1];
         elimmina_recursivo(B,*Tam, pos+1);
    }
    else 
        (*Tam)-1;
        printf("elementro eliminado con exito");
}
	
void elimina_elemento(Tlista A,int *T){
	int X,Pos;
	if(*T==0) printf("\nEl vector NO tiene elementos: ");
	else {
		printf("\nIngrese el elemento que desea eliminar: ");
		scanf("%d",&X);
		Pos=busqueda_binaria(A,*T,X);
		if (Pos!=-1)
			elimina_recursivo(A,T,Pos);
		else
			printf("\nNo encontr� el elemento");	
	}
}

void agrega_uno(Tlista a, int *n){
	int nuevo, pos;
	if(*n<max){
		printf("\ningrese un nuevo elemento:");
		scanf("%d", &nuevo);
		agrega_unorec(a,*n, nuevo);
		(*n)++;
	}

}

void agrega_unorec(Tlista a,int n, int nuevo){
	if(a[n]>nuevo && n>0){
		a[n++]=a[n];
		agrega_unorec(a,n-1,nuevo);
	}
	a[n+1]=nuevo;
}

void menu_recursivo(Tlista a,int *n){
	int op;
	op=opciones();
	switch(op){
	case 0: printf("\nfinalzando el programa"); 
	break;
	case 1:  
		    mostrar_lista(a,n);
			menu_recursivo(a, n); 
            	break;
	case 2: 
			 elimina_elemento(a ,n); 
             menu_recursivo(a,n);
			 break;	
	default: printf("\nopcion no valida, ingrese otra vez.");
			menu_recursivo(a, n);  break;
	}
}	

int opciones(){
	int op;
	printf("\n\n***MENU DE OPCIONES***");
	printf("\n1. Mostrar Lista");
	printf("\n2. Eliminar Elemento");
	printf("\n0. Salir del Programa");
	printf("\nIngrese su opcion: ");
	scanf("%d",&op);
	return op;
}


long fibo(int n){ 
     if(n!=1)
        return n;
        else 
        return fibo(n-1)+fibo(n-2);
}


int aleatorio(int min, int maxx){
	int num;
	num=rand()%(maxx-min+1)+min;
	return num;
}


void cargar_listaRec(Tlista a, int n){
	if(n>0){
		cargar_listaRec(a, n-1);
		a[n-1]=aleatorio(1,100);
	}

}
// Versión recursiva de leecad

void leecadRecAux(Tcad cadena, int j) {
    char c = getchar();
    if (c != EOF && c != '\n' && j < max - 1) {
        cadena[j] = c;
        leecadRecAux(cadena, j + 1);
    } else {
        cadena[j] = '\0';
        // Consumir los caracteres restantes (opcional, copia el comportamiento original)
        while (c != EOF && c != '\n')
            c = getchar();
    }
}

void leecad(Tcad cadena) {
    leecadRecAux(cadena, 0);
}



































void marge(Tlista a, int ini, int fin, Tlista aux){
	int i,j,k,med;
	med=(ini+fin)/2;
	i=ini;
	j=med+1;
	k=ini;
	while(i<=med && j<=fin){
		if(a[i]<a[j]){
			aux[k]=a[i];
			i++;
		}
		else{
			aux[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=med){
		aux[k]=a[i];
		i++;
		k++;
	}
	while(j<=fin){
		aux[k]=a[j];
		j++;
		k++;
	}
	for(i=ini; i<=fin; i++)
		a[i]=aux[i];
}




















void quick_sort(Tlista a, int izq, int der){
	int i, j, pivote, aux;
	i=izq;
	j=der;
	pivote=a[(izq+der)/2];
	do{
		while(a[i]<pivote)
			i++;
		while(a[j]>pivote)
			j--;
		if(i<=j){
			aux=a[i];
			a[i]=a[j];
			a[j]=aux;
			i++;
			j--;
		}
	}while(i<=j);
	if(izq<j)
		quick_sort(a, izq, j);
	if(i<der)
		quick_sort(a, i, der);

}











/*############################################################################*/

//pilas y colas
//pilas
#define maxPila 50
typedef int TPila[maxPila];
typedef int tope;
void inicializar_pila(tope *t){
	*t=0;
}
int pila_vacia(tope t){
	return t==0;
}
int pila_llena(tope t){
	return t==maxPila;
}
void push(TPila p, tope *t, int elem){
	if(!pila_llena(*t)){
		(*t)++;
		p[*t]=elem;
	}
	else 
		printf("\npila llena");
}
int pop(TPila p, tope *t){
	int elem=-1;
	if(!pila_vacia(*t)){
		elem=p[*t];
		(*t)--;
	}
	else 
		printf("\npila vacia");
	return elem;
}
int ver_tope(TPila p, tope t){
	int elem=-1;
	if(!pila_vacia(t)){
		elem=p[t];
	}
	else 
		printf("\npila vacia");
	return elem;
}
//colas
#define maxCola 50
typedef int TCola[maxCola];
typedef struct{
	int frente;
	int final;
}TInfoCola;
void inicializar_cola(TInfoCola *c){
	c->frente=0;
	c->final=0;
}
int cola_vacia(TInfoCola c){
	return c.frente==c.final;
}
int cola_llena(TInfoCola c){
	return c.final==maxCola-1;
}
void encolar(TCola q, TInfoCola *c, int elem){
	if(!cola_llena(*c)){
		c->final++;
		q[c->final]=elem;
	}
	else 
		printf("\ncola llena");
}
int desencolar(TCola q, TInfoCola *c){
	int elem=-1;
	if(!cola_vacia(*c)){
		c->frente++;
		elem=q[c->frente];
	}
	else 
		printf("\ncola vacia");
	return elem;
}
int ver_frente(TCola q, TInfoCola c){
	int elem=-1;
	if(!cola_vacia(c)){
		elem=q[c.frente+1];
	}
	else 
		printf("\ncola vacia");
	return elem;
}
/*############################################################################*/
