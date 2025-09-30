/*Ejercicio 3: Se tiene una lista de caracteres que representa una frase conformada con consonantes, 
vocales en minúsculas y dígitos, el ingreso de la lista se finalizará al ingresar el carácter “/”. Se solicita 
ingresar un carácter y buscarlo en la lista ingresada informando la primera posición donde se encuentra, 
borrar de la lista los dígitos presentes y para finalizar ordenar la lista ascendentemente y mostrar la lista 
resultante. */


#include <stdio.h>
#include <ctype.h>
#define max 50

typedef char Tlista[max];
void ingreso_vector_caracter(Tlista, int*);
void mostrar_vector(Tlista , int );
void buscar_caracter(Tlista , int , char );
void eliminar_digitos(Tlista , int* );
void ordenar_vector(Tlista , int );

int main(void){
    Tlista C;
    int n;
    char buscado;
    ingreso_vector_caracter(C,&n);
	fflush(stdin);
    printf("\ningrese un caracter a buscar:");
    scanf("%c", &buscado);
    buscar_caracter(C,n,buscado);
    eliminar_digitos(C,&n);
    ordenar_vector(C,n);
	printf("\nvector depurado sin digitos");
    mostrar_vector(C,n);
    return 0;
}

void ingreso_vector_caracter(Tlista c, int*n){
    char caracter;
    int i=0;
    do
    {
		fflush(stdin);
        printf("ingrese un caracter (para finalizar ingrese '/'):");
        scanf("%c", &caracter);
        if(caracter!='/'){
            i++;
            c[i]=caracter;
        }
        
    } while (caracter!='/');
	*n=i;
}

void mostrar_vector(Tlista A, int n){
	int i;
	printf("\nelementos del vector:");
	for(i=1; i<=n; i++)
		printf("%c,",A[i]);
}

void buscar_caracter(Tlista c, int n, char buscado){
    int i;
    i=1;
    while(i<=n && c[i]!=buscado)
        i++;
    if(i<=n)
        printf("el caracter %c se encuentra en la posicion %d\n",buscado,i);
    else
        printf("el caracter %c no se encuentra en la lista\n",buscado);
}

void eliminar_digitos(Tlista c, int*n ){
    int i,pos;
    for(i=1; i<=*n; i++){
        if(c[i]>='0' && c[i]<='9'){
            for(pos=i; pos<=(*n)-1; pos++){
                c[pos]=c[pos+1];
            }
            (*n)--;
        }
    }
}

void ordenar_vector(Tlista c, int n){
    int i,j;
    char aux;
    for(i=1;i<n;i++){
        for(j=i+1; j<=n; j++){
            if(c[i]>c[j]){
                aux=c[i];
                c[i]=c[j];
                c[j]=aux;
            }
        }
    }
}

	

