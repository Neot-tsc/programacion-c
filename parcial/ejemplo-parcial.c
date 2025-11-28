/*dado una lista de patentes de autos de arg, las cualespueden corresponder a uno de los dos formatos vigentes:
antiguo(ADS312) 
nuevo (HJ123TU)
se pide que el programa carge una lista de patentes, determine y muestre la cantidad de patentes qeu corrsponden al 
formato antiguo, y luego orene la lista, que primero aparezca todas las patents ddel formato antiguo
ordenadas alfabeticamente las antiguas y las viejas, usar m-sort, */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef char tcad[max];

void leecad(tcad);
int compara_cad(tcad,tcad);

typedef tcad tpatente[max];
void cargar_patentes(tpatente, int*);
void mostrar_patentes(tpatente, int);
int cant_car(tcad);
void marge(tpatente, int,int,int);
void m_sort(tpatente, int, int);
void antiguas(tpatente, int, tpatente, int*);
void nuevas(tpatente, int, tpatente, int*);
void union_ant_nue(tpatente, int, tpatente, int, tpatente, int);





int main(){
    tpatente patentes, pantiguas, pnuevas, final;
    int n, n_ant, n_nue;

    cargar_patentes(patentes, &n);
    
    // Separar patentes antiguas y nuevas
    antiguas(patentes, n, pantiguas, &n_ant);
    nuevas(patentes, n, pnuevas, &n_nue);
    
    printf("\nCantidad de patentes antiguas: %d\n", n_ant);
    
    // Ordenar cada grupo
    if(n_ant > 0)
        m_sort(pantiguas, 1, n_ant);
    if(n_nue > 0)
        m_sort(pnuevas, 1, n_nue);
    
    // Unir ambos grupos
    union_ant_nue(pantiguas, n_ant, pnuevas     , n_nue, final, n);
    
    printf("\nPatentes ordenadas (antiguas primero):\n");
    mostrar_patentes(final, n_ant + n_nue);

    return 0;
}

void leecad_rec(tcad cad, int j){
    char c;
    c=getchar();
    if(c!=EOF && c!='\n' && j<max-1){
        cad[j]=c;
        leecad_rec(cad, j+1);
    }
    else{
        cad[j]='\0';
        while(c!=EOF && c!='\n')
            c=getchar();
    }
}

void leecad(tcad cad){
    leecad_rec(cad, 0);
}

void cargar_patentes_rec(tpatente a, int i, int n){
    if(i <= n){
        printf("Ingrese la patente %d: ", i);
        fflush(stdin);
        leecad(a[i]);
        cargar_patentes_rec(a, i+1, n);
    }
}

void cargar_patentes(tpatente a, int *n){
    printf("\nIngrese la cantidad de patentes: ");
    scanf("%d",n);
    cargar_patentes_rec(a, 1, *n);
}
void mostrar_patentes_rec(tpatente a, int i, int n){
    if(i <= n){
        printf("%s\n", a[i]);
        mostrar_patentes_rec(a, i+1, n);
    }
}

void mostrar_patentes(tpatente a, int n){
    mostrar_patentes_rec(a, 1, n);
}
int cant_car(tcad cad){
    return (strlen(cad));
}

void copiar_resto_rec(tpatente origen, int t, int limite, tpatente destino, int* k){
    if(t <= limite){
        (*k)++;
        strcpy(destino[*k], origen[t]);
        copiar_resto_rec(origen, t+1, limite, destino, k);
    }
}

void copiar_a_original_rec(tpatente aux, int t, int limite, tpatente a, int ini){
    if(t <= limite){
        strcpy(a[ini+t-1], aux[t]);
        copiar_a_original_rec(aux, t+1, limite, a, ini);
    }
}

void mezclar_rec(tpatente a, int* i, int med, int* j, int fin, tpatente aux, int* k){
    if(*i <= med && *j <= fin){
        (*k)++;
        if(strcmp(a[*i], a[*j]) < 0){
            strcpy(aux[*k], a[*i]);
            (*i)++;
        }
        else{
            strcpy(aux[*k], a[*j]);
            (*j)++;
        }
        mezclar_rec(a, i, med, j, fin, aux, k);
    }
}

void marge(tpatente a, int ini, int med, int fin){
    tpatente aux;
    int i, j, k;
    k = 0;
    i = ini;
    j = med + 1;
    mezclar_rec(a, &i, med, &j, fin, aux, &k);
    copiar_resto_rec(a, i, med, aux, &k);
    copiar_resto_rec(a, j, fin, aux, &k);
    copiar_a_original_rec(aux, 1, k, a, ini);
}
void m_sort(tpatente a, int ini, int fin){
    int med;
    if(ini<fin){
        med=(ini+fin)/2;
        m_sort(a, ini, med);
        m_sort(a, med+1, fin);
        marge(a, ini, med, fin);
    }
}

void antiguas_rec(tpatente a, int i, int n, tpatente b, int* j){
    if(i <= n){
        if(cant_car(a[i])==6){
            (*j)++;
            strcpy(b[*j], a[i]);
        }
        antiguas_rec(a, i+1, n, b, j);
    }
}

void antiguas(tpatente a, int n, tpatente b, int* m){
    *m = 0;
    antiguas_rec(a, 1, n, b, m);
}

void nuevas_rec(tpatente a, int i, int n, tpatente b, int* j){
    if(i <= n){
        if(cant_car(a[i])==7){
            (*j)++;
            strcpy(b[*j], a[i]);
        }
        nuevas_rec(a, i+1, n, b, j);
    }
}

void nuevas(tpatente a, int n, tpatente b, int* m){
    *m = 0;
    nuevas_rec(a, 1, n, b, m);
}
void copiar_rec(tpatente origen, int i, int n, tpatente destino, int* k){
    if(i <= n){
        (*k)++;
        strcpy(destino[*k], origen[i]);
        copiar_rec(origen, i+1, n, destino, k);
    }
}

void union_ant_nue(tpatente a, int n1, tpatente b, int n2, tpatente c, int n3){
    int k = 0;
    copiar_rec(a, 1, n1, c, &k);
    copiar_rec(b, 1, n2, c, &k);
}