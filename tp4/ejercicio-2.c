#include <stdio.h>

typedef int Tlista[50];

void ingreso_vector(Tlista,int*);
void mostrar_vector(Tlista, int);
int menu();
int menor_de_un_vector(Tlista, int);
void ordenamiento_seleccion_directa(Tlista, int);
void insertar_un_elemento_al_final(Tlista, int* );
void insertar_un_elemento(Tlista, int*, int, int);
void eliminar_un_elemento(Tlista,int*);
int es_primo(int);
void mostrar_primos(Tlista, int);
	/*encuentra la posicion de manera ordenada*/

int determinar_pos(Tlista , int , int );
	
	/*inserta un numero en el vector manteniendo el orden, recibiendo el nuevo y la pos*/
	
void insertar_un_elemento(Tlista , int*, int, int);
	
	/*inserccion de baraja (inserta manteniendo el orden)*/
	
void insertar_baraja_tamanioo_conocido(Tlista , int );
int busqueda_binaria(Tlista , int , int);
int busqueda_secuencial(Tlista, int, int);	
	
	
int main(int argc, char *argv[]) {
	Tlista A;
	int n, op;
	do
	{
		op=menu();
		switch (op)
		{
		case 1:
			ingreso_vector(A,&n);
			break;
		case 2:
			printf("\nel menor elemento de la lista es %d",menor_de_un_vector(A,n));
			break;
		case 3:
			ordenamiento_seleccion_directa(A,n);
			mostrar_vector(A,n);
			break;
		case 4:
			insertar_un_elemento(A,&n);
			ordenamiento_seleccion_directa(A,n);
			mostrar_vector(A,n);
			break;
		case 5:
			eliminar_un_elemento(A,&n);
			mostrar_vector(A,n);
			break;
		case 6:
			mostrar_primos(A,n);
			break;
		
		default:
			if(op!=0)
			printf("\ningrese una opcion valida.");
			break;
		}
	} while (op!=0);
	printf("\nprograma finalizado.");
	
	return 0;
}

void ingreso_vector(Tlista A,int *n){
	int i;
	printf("\ningrese el tamanio del vector: ");
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

int menu(){
	int op;
		printf("\n**** MENU ****\n\n");
		printf("\n1. Ingresar vector");
		printf("\n2. mostrar el menor de la lista.");
		printf("\n3. ordenart la lista de menor a mayor.");
		printf("\n4. insertar un nuevo elemento a la lista.");
		printf("\n5. eliminar un elemnto de la lista.");
		printf("\n6. mostrar los elementos primos de la lista.");
		printf("\n0. salir del programa.");
		printf("\n\ningrese una opcion: ");
		scanf("%d",&op);
	return op;
}

int menor_de_un_vector(Tlista a, int n){
	int menor,i;
	menor=a[1];
	for(i=2; i<=n; i++){
		if(a[i]<menor)
			menor=a[i];
	}
	return menor;
}

void ordenamiento_seleccion_directa(Tlista a, int n){
	int i,j,aux;
	for(i=1; i<n; i++){
		for(j=i+1; j<=n; j++){
			if(a[j]<a[i]){
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
	}
}

void insertar_un_elemento_al_final(Tlista a, int*n){
	int x;
	printf("\ningrese un elemento a insertar: ");
	scanf("%d",&x);
	*n=*n+1;
	a[*n]=x;
}

void eliminar_un_elemento(Tlista a,int*n){
	int i,pos;
	printf("\ningrese la posicion el elemento a eliminar:");
	scanf("%d", &pos);
	for(i=pos; i<*n; i++)
		a[i]=a[i+1];
	*n=*n-1;
}

int es_primo(int x){
	int pd,r;
	r=0;
	pd=2;
	while(pd<=x/2 && x%pd!=0)
		pd++;
	if(pd>x/2 && x!=1)
		r=1;
	return r;
}

void mostrar_primos(Tlista a, int n){
	int i;
	printf("\nlos elementos primos de la lisra son :");
	for(i=1; i<=n; i++){
		if(es_primo(a[i]))
			printf("%d,",a[i]);
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
			j=j--;
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
	}while (a[i]!= 0)/*la condicion tiene que ser distinta*/
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
	return pos
}




