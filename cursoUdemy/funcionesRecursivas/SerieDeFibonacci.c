/* SERIE DE FIBONACCI CON RECURSIVIDAD */

#include <stdio.h>

int serieDeFibonacci(int num);

int main(){
	int numero = 0;
	puts("Ingresa un numero: ");
	scanf("%d", &numero);
	puts("debug");
	for (int i = 1; i<= numero; ++i) {
		printf("%d\n",serieDeFibonacci(i));
	}
	return 0;
}

int serieDeFibonacci(int num){

	if(num == 1 || num == 2){
		return 1;
	} else {
		return (serieDeFibonacci(num-1) + serieDeFibonacci(num-2));
	}
}
