/*Ejercicio 2: 
Diseñe módulos (prototipo más implementación) para cada uno de los casos que se enuncian 
a continuación, con el propósito de utilizarlos en problemas posteriores: 
a) Calcule y retorne la cantidad de horas, minutos y segundos que existen en una cantidad de segundos 
ingresada por el usuario. 
b) Manipule dos números enteros quitando la última cifra del primero y añadiéndola al final del segundo. 
c) Reciba dos variables enteras e intercambie sus valores.*/

#include <stdio.h>

int menu(void);
void cant_horas_min_seg(int seg, int *h, int *m, int *s);
int separa_digito(float *);
void anade_digito(int, float *);
void intercambio(int *, int *);


int main (void){
    int op,segtotal,hora, min, seg,dig,a, b;
    float num1,num2;
    
    do
    {
        op=menu();
        switch (op)
        {
        case 1:
            printf("\ningrese la cantiad de segundos a calcular: ");
            scanf("%d",&segtotal);
            cant_horas_min_seg(segtotal, &hora, &min, &seg);
            printf("\nen la cantidad de :%d, la cantidad de horas, minutos y segundos es: %d:%d:%d",segtotal,hora,min,seg);
            break;
        case 2:
            printf("\ningrese dos numeros enteros");
            printf("\ningrese el numero a: ");
            scanf("%d",&num1);
            printf("\ningrese el numero b: ");
            scanf("%d",&num2);
            dig=separa_digito(&num1);
            anade_digito(dig,&num2);
            printf("\nlos nuevos valores son a: %d y b: %d",num1,num2);
            break;
        case 3:
            printf("\ningrese dos numeros enteros");
            printf("\ningrese el numero a: ");
            scanf("%d",&a);
            printf("\ningrese el numero b: "); 
            scanf("%d",&b);
            intercambio(&a,&b);
            printf("\nlos nuevos valores son a: %d y b: %d",a,b);
            break;
        
        default:
            break;
        }
    } while (op!=0);
    

    return 0;
}




int menu(void){
    int op;
    do
    {
        printf("\n**main menu**\n\n");
        printf("\n1) Calcule y retorne la cantidad de horas, minutos y segundos que existen en una cantidad de segundos ingresada por el usuario.");
        printf("\n2) Manipule dos numeros enteros quitando la ultima cifra del primero y a�adiendola al final del segundo.");
        printf("\n3) Reciba dos variables enteras e intercambie sus valores.");
        printf("\n0) salir.");
        printf("\ningrese una opcion: ");
        scanf("%d",&op);
    } while (op!=0);
    return op;
}

void cant_horas_min_seg(int seg, int *h, int *m, int *s){
    int horas, minutos, segundos;
    horas=seg/3600;
    seg=seg%3600;
    minutos=seg/60;
    seg=seg%60;
    segundos=seg;
    *h=horas;
    *m=minutos;
    *s=segundos;
}

int separa_digito(float *n){
    float dig;
    dig=*n%10;
    *n=*n/10;
    return dig;
}

void anade_digito(int dig, float *n){
    *n=*n*10+dig;
}

void intercambio(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
