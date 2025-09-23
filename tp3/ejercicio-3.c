#include <stdio.h>

void Invertido(int,int*);
void Intercambio(int,int,int*,int*);

int main (){
	int invertido, a, b, ban;
	ban=1;
	char op;
	while (ban==1){
		printf("ingrese un valor para a:");
		scanf("%d", &a);
		printf("ingrese un valor para b:");
		scanf("%d", &b);
		printf("\n## ingrese una opccion del menu ##\n");
		printf("a) nuestre el numero invertido de A\n");
		printf("b) nuestre el numero invertido de B\n");
		printf("c) muenstra ambos numeros dejando el mayor en A y el menor en B\n");
		scanf("\n%c", &op);
		switch (op){
		case 'a':
			Invertido(a, &invertido);
			printf("el invertido de a es :%d\n", invertido);
			break;
			
		case 'b':
			Invertido(b, &invertido);
			printf("el invertido de a es :%d\n", invertido);
			break;
			
		case 'c':
			Intercambio(a,b,&a,&b);
			printf("numeros invertidos\na:%d\nb=:%d\n\n", a, b);
			break;
		default:
			ban=0;
		}
	}
	printf("//programa apagado//");
	
	return 0;
}
	
	void Invertido(int a,int *x){
		int dig, cont=0; 
		while (a!=0)
		{
			dig=a%10;
			a=a/10;
			cont=cont*10+dig;
			*x=cont;
		}
	}
		
		void Intercambio(int a, int b, int *a1, int *b1){
			int copia=a;
			if (b>a){
				*a1=b;
				*b1=copia;
			}
		}
			
