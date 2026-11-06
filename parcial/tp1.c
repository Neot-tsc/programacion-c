#include <stdio.h>
#include <math.h>
//calculadora
void ingreso(float*);
float suma(float,float);
float resta(float,float);
float producto(float,float);
int validaciondiv(float);
float divicion(float,float);
int resto(int,int);
int opciones();
void mostrar(float);


int main(void){
    int op,v,c,d;
    float a,b,r;
    do
    {
        op=opciones();
        switch(op){
            case 1:
                printf("\ningrese el valor de a:");
                ingreso(&a);
                printf("\ningrese el valor de b:");
                ingreso(&b);
                r=suma(a,b);
                mostrar(r);
                break;
            case 2:
                printf("\ningrese el valor de a:");
                ingreso(&a);
                printf("\ningrese el valor de b:");
                ingreso(&b);
                r=resta(a,b);
                mostrar(r);
                break;
            case 3:
                printf("\ningrese el valor de a:");
                ingreso(&a);
                printf("\ningrese el valor de b:");
                ingreso(&b);
                r=producto(a,b);
                mostrar(r);
                break;
            case 4:
                printf("\ningrese el valor de a:");
                ingreso(&a);
                printf("\ningrese el valor de b:");
                ingreso(&b);
                v=validaciondiv(b);
                if(v==1){
                    r=divicion(a,b);
                    mostrar(r);
                }
                else
                    printf("\nb es igual a 0, syntac error");
                break;
            case 5:
                printf("\ningrese el valor de a:");
                ingreso(&a);
                printf("\ningrese el valor de b:");
                ingreso(&b);
                c=(int)trunc(a);
                d=(int)trunc(b);
                v=validaciondiv(d);
                if(v==1){
                    r=resto(c,d);
                    mostrar(r);
                }
                else
                    printf("\nb es igual a 0, syntac error");
                break;
            default:
                printf("\nsaliendo del pograma.....");
        }
    } while (op!=0);
    


    return 0;
}

float suma(float a,float b){
    return a+b;
}

float resta(float a,float b){
    return a-b;
}

float producto(float a,float b){
    return a*b;
}
int validaciondiv(float b){
    int r;
    if(b!=0)
        r=1;
    else 
        r=0;
    return r;
}

float divicion(float a,float b){
    return a/b;
}
int resto(int a,int b){
    return a%b;
}
int opciones(){
    int op;
    printf("\n## MENU ##\n");
    printf("\n1. suma");
    printf("\n2. resta");
    printf("\n3. producto");
    printf("\n4. divicion");
    printf("\n5. resto");
    printf("\n0. salir");
    printf("\n\nseleccione una opcion");
    scanf("%d",&op);
    return op;
}
void mostrar(float r){
    printf("\n resultado de la operacion=%f", r);
}

void ingreso(float *a){
    scanf("%f", a);
}