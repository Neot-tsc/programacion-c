#include <stdio.h>

typedef int Tlista[50];

void ingreso_vector(Tlista,int*);
void mostrar_vector(Tlista, int);
int menu();
int menor_de_un_vector(Tlista, int);
void ordenamiento_seleccion_directa(Tlista, int);
void insertar_un_elemento(Tlista, int* );
void eliminar_un_elemento(Tlista,int*);
int es_primo(int);
void mostrar_primos(Tlista, int);


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

void insertar_un_elemento(Tlista a, int*n){
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
