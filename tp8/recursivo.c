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