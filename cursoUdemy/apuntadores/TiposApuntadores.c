/* Hacer una variable de tipo int. otra de tipo float y otra de tipo char,
 * almacenar datos en cada una de las variables.
 * Posteriormente indicar la posicion de la memoria donde se encuentran
 * guardados los datos de cada variable. */

#include <stdio.h>

int main(){
	int entero = 10, *apuntadorEntero = &entero;
	float flotante = 10.5, *apuntadorFlotante = &flotante;
	char caracter = 'a', *apuntadorCaracter = &caracter;
	puts("----------");

	printf("Entero (variable): %d\n", entero);
	printf("Apuntador *: %d\n", *apuntadorEntero);
	printf("Apuntador Entero: %p\n", apuntadorEntero);
	printf("Direccion en Memoria de Entero: %p\n", &entero);

	puts("----------");

	printf("Flotante (variable): %.2f\n", flotante);
	printf("Apuntador *: %.2f\n", *apuntadorFlotante);
	printf("Apuntador Flotante: %p\n", apuntadorFlotante);
	printf("Direccion en Memoria de Flotante: %p\n", &flotante);

	puts("----------");

	printf("Caracter (variable): %c\n", caracter);
	printf("Apuntador *: %c\n", *apuntadorCaracter);
	printf("Apuntador Caracter: %p\n", apuntadorCaracter);
	printf("Direccion en Memoria de Caracter: %p\n", &caracter);
	puts("----------");

	return 0;
}


