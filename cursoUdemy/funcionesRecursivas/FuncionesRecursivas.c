/* FUNCIONES RECURSIVAS
 * Se obtiene factorial de un numero
 * con la ayuda de las funciones recursivas*/

#include <stdio.h>

long factorial(int n);

int main(){
	int numero = 0;
	puts("Ingres un numero para calcular su factorial");
	scanf("%d", &numero);

	printf("El factorial de %i es %li\n", numero, factorial(numero));
	return 0;
}

long factorial(int n){
	if (n<=1){
		return 1;
	}else{
		return n * factorial(n -1);
	}
}
