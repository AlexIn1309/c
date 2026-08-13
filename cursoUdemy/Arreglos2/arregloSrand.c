/* ARREGLOS Y SRAND
 * Escribir un programa que tenga un arreglo de 
 * 100 numeros aleatorios entre 1 y 1000. 
 * Una vez creado, se debe organizar de tal manera
 * que almacene los numeros pares en un array y los impares en otro */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD 100

int main(){

	int numero[CANTIDAD];
	int pares[CANTIDAD];
	int impares[CANTIDAD];

	// Generar numeros random
	srand(time(NULL));

	for (int i = 0; i < CANTIDAD; i++) {
		numero[i] = rand() % + (1000+1);
	}
	puts("Pares:\n");
	for (int i = 0;i<CANTIDAD;i++) {
		if (numero[i]%2==0) {
			printf("%d\n", numero[i]);
		}
	}

	puts("Impares:\n");
	for (int i = 0;i<CANTIDAD;i++) {
		if (numero[i]%2 != 0) {
			printf("%d\n", numero[i]);
		}
	}
	
	return 0;
}
