/* FUNCIONES RECURSIVAS 2
 * Se obtiene factorial de un numero
 * con la ayuda de las funciones recursivas*/

#include <stdio.h>

long factorial(int n);

int main(){
	int numero = 0;
	puts("Ingres un numero para calcular su factorial");
	scanf("%d", &numero);

	for (int i = 0; i <= numero;i++) {
		printf("%li\n", factorial(i));
	}

	return 0;
}

long factorial(int n){
	if (n<=1){
		return 1;
	}else{
		return n * factorial(n -1);
	}
}
