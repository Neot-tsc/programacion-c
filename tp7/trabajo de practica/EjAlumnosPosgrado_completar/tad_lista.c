#include "tad_lista.h"
void cargar_vector(Tvec,int*);
void mostrar_lista_p(Tvec,int);
void comprobar_fecha(Tvec,int,long);
void modificar_uno(Tvec, int);

int retorna_tam(Tlista aux){
	return aux.tam;
}
/* carga_lista(){
	Tlista aux;	int i;
	printf("ingrese cantidad de alumnos: ");
	scanf("%d",&aux.tam);
	for(i=1;i<=aux.tam;i++)	
	   aux.v[i]=carga_alumnno();
*/	
Tlista carga_lista(){  /*PUBLICO*/
	Tlista aux;
	cargar_vector(aux.v,&aux.tam);
	return aux;
}

void cargar_vector(Tvec v,int *tam){
	int i;
	printf("\ningrese el tamanio de la lista:");
	scanf("%d",tam);
	for(i=1; i<=*tam; i++){
		v[i]=cargar_alumno();
	}
}
void agregar(Tlista *aux){  /*PUBLICO*/
	(aux->tam)++;
	aux->v[aux->tam]=cargar_alumno();
	
}
int buscar_x_Dni_Curso(Tvec v, int tam,long doc,Tcad c){
	int i;
	i=1;
	while((i<=tam)&&(compara_x_dni(v[i],doc)!=0)&&compara_postgrado(v[i],c)!=0)
		i++;
	if(i<=tam) return i;
	else return -1;
	
}

void modificar_uno(Tvec v, int tam){
	int pos;
	long dni;
	Tcad curso;	
	
	printf("\nIngrese DNI del alumno a modificar: ");
	scanf("%ld",&dni);
	printf("\nIngrese Curso de Postgrado del alumno a modificar: ");
	fflush(stdin);
	CargaCadena(curso);
	pos=buscar_x_Dni_Curso(v,tam);
	if(pos!=-1){
		v[pos].dni=dni;
		strcmp(v[pos].curso,curso);
	}
	
	
}
void modificar_alumno(Tlista *aux){  /*PUBLICO*/
	/** COMPLETAR */
	
}
	
void mostrar_lista(Tlista aux){  /*PUBLICO*/
	int i;
	for(i=1; i<=aux.tam; i++)
		mostrar_alumno(v[i]);
}
void dar_bajas(Tlista* aux){   /*PUBLICO*/
	long fec;
	printf("\ningrese fecha a comparar AAAAMMDD: ");
	scanf("%ld",&fec);
	comprobar_fecha(aux->v,aux->tam,fec);
}
	
void comprobar_fecha(Tvec v,int tam, long f){
	int i,cant;
	for (i=1;i<=tam;i++){
		cant=f-retornar_fechaFin(v[i]);
		if (cant>10000)
			modificar_estado_a_baja(&v[i]);
	}
}
void generaxEstado(Tvec vec,int t, Tvec nue,int *ntam){
	int e,i;
	printf("\ningrese el Estado de la lista a crear: ");
	scanf("%d",&e);
	*ntam=0;
	for (i=1;i<=t;i++){
	 if(retorna_estado(vec[i])==e){
		 (*ntam)++;
		 nue[*ntam]=vec[i];	 
	 }
	}	
}
Tlista generarOtra_estado(Tlista lista){  /*PUBLICO*/
	Tlista aux;
	generaxEstado(lista.v,lista.tam, aux.v,&aux.tam);
	return aux;
}
void ordenar_lista_apenom(Tvec vec,int n){
	int i,j;
	Talumno aux;
	
	
	}
void ordenar_lista(Tlista *aux){// PUBLICO
	ordenar_lista_apenom(aux->v,aux->tam);
}
