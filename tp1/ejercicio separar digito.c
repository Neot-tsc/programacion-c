#include <stdio.h>

/*dado un nuemro natural, mostrar la suma de sus digitos impares*/

int main(int argc, char *argv[]) {
	int n, sum, c, dig;
	sum=0;
	printf("\ningrese un numero natural: ");
	scanf("%d", &n);
	c=n;
	while(c>0){
		dig=c%10;
		if(dig%2!=0)
			sum+=dig;
		c=c/10;
	}
	printf("\nel numero ingresado es :%d ,y la suma de sus digitos impares es %d: ", n, sum);
	return 0;
}

