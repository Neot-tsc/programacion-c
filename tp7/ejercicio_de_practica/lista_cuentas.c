#inlcude "TAD_LISTA_CUENTAS_H"
#inlcude "TAD_CUENTA_H" 

tlista cargar_lista(){
	tlista aux;
	printf("\ningrese la cantidad de elementos:");
	scanf("%d", &aux.tam);
	cargar_vector(aux.lista, aux.tam);
	return aux;
}

void mostrar_lista(tlista a){
	int i;
	printf("\ndatos de la lista\n");
	for(i=1; i<=a.tam; i++){
		mostrar_todo(a.lista, a.tam);
	}
}

void cargar_vector(tvector a, int n){
	int i;
	for(i=1; i<=n; i++){
		a[i]=cargar_cuenta();
	}
}
