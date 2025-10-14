#include <stdio.h>
#define max 50

typedef int vector[max];
void baraja(vector a, int* n);
int nuevo();
int esta(vector, int, int);

int main (void){
    vector a;
    int n;
    baraja(a,&n);
    printf("\n%d\n",n);
	for(int i=1; i<=n; i++){
		printf("\n%d\n",a[i]);
	}
    return 0;
}
int nuevo(){
    int nuevo;
    printf("\ningrese uno:");
    scanf("%d",&nuevo);
    return nuevo;
}

/*void baraja(vector a, int* n){*/
/*    int i,j;*/
/*    i=0;*/
/*    do*/
/*    {*/
/*        i++;*/
/*        a[i]=nuevo();*/
/*		a[0]=a[i];*/
/*        j=i-1;*/
/*        while(a[0]<a[j] /*&& a[0]!=a[j]){*/
/*            a[j+1]=a[j];*/
/*            j--;*/
/*        }*/
        /*if (a[j]!=a[0])*/
/*            a[j+1]=a[0];  */
/*    } while (a[0]!=0);*/
/*    *n=i-1;*/
/*}*/

	void baraja(vector a, int *n){
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
int esta(vector a, int n, int nuevo){
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
