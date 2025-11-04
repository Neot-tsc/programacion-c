#include <stdio.h> 
void averigua(int, int); 
int main(void) { 
int x;  
printf("\n Ingrese un número natural ");  
scanf("%d",&x); averigua(x,2);  
return 0;  
}  

//descompocicion de un numero en factores primos
void averigua(int N, int f){  
    if (N>1) 
        if (N%f==0) { 
            printf("\t %d",f);  
            averigua(N/f, f);  
        }  
        else   
            averigua(N, f+1);  
    else 
        printf("\t %d", 1);  
}    