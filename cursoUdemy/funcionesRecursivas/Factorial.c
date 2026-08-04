/* FACTORIAL CON RECURSIVIDAD */

#include <stdio.h>

int factorial(int numero){
	int factorizado;
	if (numero<2)return 1;
	factorizado = factorial(numero-1)*numero;
	return factorizado;
}

int main(){
	int n = 0;
	puts("Ingresa numero para factorizar");
	scanf("%d", &n);
	printf("El factorial es: %d\n", factorial(n));
	return 0;
}
