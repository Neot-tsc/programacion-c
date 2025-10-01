/*Ejercicio  12:  Se  requiere  cargar  la  información  asociada  a  M  miembros  de  una  institución 
deportiva,  la  información  de  cada  miembro  es:  DNI,  Celular,  Estado  (C:  casado,  S:  soltero,  V: 
viudo, W: separado), Edad.    
Se solicita un programa modular que permita cargar la lista de miembros de la institución y que la 
misma se ordene por el campo DNI, a medida que se ingresan los miembros. Luego presente un 
menú de opciones que permita las siguientes operaciones:    
a) Dado un DNI, determinar si este se encuentra en la lista de miembros cargados.    
b) Eliminar un miembro de la lista, ingresando por teclado su DNI.    
c) Agregar un nuevo miembro a la lista.    
d) Dado un estado ingresado por teclado, mostrar la información de los registros que sean iguales al 
estado solicitado.    
e) Mostrar la lista de miembros. */

#include <stdio.h>
/*defino tamanio maximo*/
#define max 50

/*defino los tipos de arreglos que usara el prgrama*/
typedef long int Tlista[max];
typedef char Tchar[max];

/*cabecera de funciones y procedimientos*/

void ingreso_baraja(Tlista, Tlista, Tlista, Tchar, int*);
void mostrar_vector(Tlista, Tlista,Tlista, Tchar,int);
int menu(void);
int busqueda_binaria_numero(Tlista, int, long int);

int busqueda_binaria_caracter(Tlista, int, long int);

void eliminar_uno(Tlista, Tlista, Tlista, Tchar, int*, int);
void agregar_uno(Tlista, Tlista, Tlista, Tchar, int*,int, long int);
void mostrar_uno(Tlista, Tlista, Tlista, Tchar, int);

/*inicio del main*/

int main (void){
    Tlista dni, celular, edad;
    Tchar estado;
    int n, op, pos;
    long int buscado, nuevo;
	char caracter_buscado;
    ingreso_baraja(dni, celular, edad, estado, &n);
    do{
        op=menu();
        switch(op){
            case 1:
                printf("Ingrese el DNI a buscar: ");
                scanf("%ld",&buscado);
                pos=busqueda_binaria(dni,n,buscado);
                if(pos!=0)
                    printf("El miembro con DNI %ld se encuentra en la posicion %d de la lista\n",buscado,pos);
                else
                    printf("El miembro con DNI %ld no se encuentra en la lista\n",buscado);
                break;
            case 2: 
                printf("Ingrese el DNI a eliminar: ");
                scanf("%ld",&buscado);
                pos=busqueda_binaria(dni,n,buscado);
                if(pos!=0){
                    eliminar_uno(dni, celular, edad, estado, &n, pos);
                    printf("El miembro con DNI %ld fue eliminado de la lista\n",buscado);
                }
                else
                    printf("El miembro con DNI %ld no se encuentra en la lista\n",buscado);
                break;
            case 3:
				if(n<max){
					printf("\ningres el dni del mimebro (ingrese -1 para terminar):");
					scanf("%ld",&nuevo);
					if((pos=busqueda_binaria(dni,n, nuevo))==0){
						agregar_uno(dni, celular, edad, estado, &n, pos, nuevo);
						printf("\nMiembro agregado correctamente\n");
					}
					else
					   printf("\nel miembro ya existe en la lista.");
				}
				else 
				   printf("lista al maximo de su capacidad");
                break;
            case 4:
                printf("Ingrese el estado a buscar (C, S, V, W): ");
                fflush(stdin);
                scanf("%c",&caracter_buscado);
                mostrar_por_estado(dni, celular, edad, estado, n, buscado);
                break;  
            case 5:
                mostrar_vector(dni, celular, edad, estado, n);
				break;
            case 0:
                printf("saliendo del programa");
                break;
            default:
                if(op!=0){
                    printf("\nOpcion incorrecta\ningrese una opcion valida");
                }
                break;
        }
    }while(op!=0);

    return 0;
}

/*cuerpo de funciones y procedimientos*/
/*ordena mientra ingresan los elementos por el dni de menor  amayor*/
void ingreso_baraja(Tlista a, Tlista b, Tlista c, Tchar e, int* n){
    int i,j,ban;
	ban=1;
    i=1;
    do
    {
        if(i<max){
            printf("\ningres el dni del mimebro (ingrese -1 para terminar):");
			scanf("%ld",&a[i]);
			if(a[i]>0){
				printf("\ningres el celular:");
				scanf("%ld",&b[i]);
				printf("\ningres el estado:");
				fflush(stdin);
				scanf("%c",&e[i]);
				printf("\ningres la edad del miembro:");
				scanf("%ld",&c[i]);
				a[0]=a[i];
				b[0]=b[i];
				c[0]=c[i];
				e[0]=e[i];
				j=i-1;
				while(a[0]<a[j]){
					a[j+1]=a[j];
					b[j+1]=b[j];
					c[j+1]=c[j];
					e[j+1]=e[j];
					j--;
				}
				a[j+1]=a[0];
				b[j+1]=b[0];
				c[j+1]=c[0];
				e[j+1]=e[0];
				i++;
			}
			else ban=0;
        }
        else
            printf("Se alcanzo el maximo de miembros");
    } while (ban==1 && i<max);/*la condicion tiene que ser distinta*/
    *n=i-1;

}
/*muestra los elementos del vector*/
void mostrar_vector(Tlista a, Tlista b, Tlista c, Tchar e,int n){
	int i;
	printf("elementos del vector:");
	for(i=1; i<=n; i++){
        printf("\n\nempleado nro %d:",i);
		printf("\ndni: %ld,",a[i]);
        printf("\ncelular: %ld,",b[i]);
        printf("\nestado: %c,",e[i]);
        printf("\nedad: %ld,",c[i]);
    }
} 

int menu(void){
    int op;
        printf("\n**** MENU ****\n\n");
        printf("\n1. Buscar un miembro por DNI");
        printf("\n2. Eliminar un miembro por DNI.");
        printf("\n3. Agregar un nuevo miembro.");
        printf("\n4. Mostrar miembros por estado civil.");
        printf("\n5. Mostrar la lista de miembros.");
        printf("\n0. salir del programa.");
        printf("\n\ningrese una opcion: ");
        scanf("%d",&op);
		return op;
}

int busqueda_binaria(Tlista a, int n, long int buscado){
    int ini, fin, med, pos;
    ini=1;
    fin=n;
    med=(ini+fin)/2;
    pos=0;
    while(ini<=fin && a[med]!=buscado){
        if(a[med]<buscado)
            ini=med+1;
        else
            fin=med-1;
        med=(ini+fin)/2;
    }
    if(ini<=fin)
        pos=med;
    
    return pos;
}

void eliminar_uno(Tlista a, Tlista b, Tlista c, Tchar e, int*n, int pos){
    int i;
    for(i=pos; i<*n; i++){
		a[i]=a[i+1];
        b[i]=b[i+1];
        c[i]=c[i+1];
        e[i]=e[i+1];
    }
	(*n)--;
}

void agregar_uno(Tlista a, Tlista b, Tlista c, Tchar e, int*n, int pos, long int nuevo){
		a[0]=nuevo;
        printf("\ningres el celular:");
        scanf("%ld",&b[0]);
        printf("\ningres el estado:");
        fflush(stdin);
        scanf("%c",&e[0]);
        printf("\ningres la edad del miembro:");
        scanf("%ld",&c[0]);
        pos=*n;
        while(a[0]<a[pos] && pos>0){
            a[pos+1]=a[pos];
            b[pos+1]=b[pos];
            c[pos+1]=c[pos];
            e[pos+1]=e[pos];
            pos--;
        }
        a[pos+1]=a[0];
        b[pos+1]=b[0];
        c[pos+1]=c[0];
        e[pos+1]=e[0];
        (*n)++;
}

void mostrar_uno(Tlista a, Tlista b, Tlista c, Tchar e, int pos){
		printf("\n\nempleado nro %d:",pos);
		printf("\ndni: %ld,",a[pos]);
		printf("\ncelular: %ld,",b[pos]);
		printf("\nestado: %c,",e[pos]);
		printf("\nedad: %ld,",c[pos]);
}
