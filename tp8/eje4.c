#include <stdio.h>

int restoRec(int, int);


int main(void){
    int num, res, div;
    printf("\ningrese un numero entero positivo:");
    scanf("%d", &num);
    printf("\ningrese el divisor:");
    scanf("%d", &div);
    res=restoRec(num, div);
    printf("\n el resultado es:%d", res);

    return 0;
}

int restoRec(int num, int div){
    if(num < div){
        return num;
    } else {
        return restoRec(num - div, div);
    }
}