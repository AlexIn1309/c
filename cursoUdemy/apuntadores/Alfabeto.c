/* 179. Alfabeto Mayuscula
 * Se imprimira todo el alfabeto con una iteracion de for 
 * Y con el uso directo de un apuntador */

#include <stdio.h>

int main(){
	
	char caracter;
	char *apuntadorCaracter;
	apuntadorCaracter = &caracter;

	for (caracter = 'A'; caracter <= 'Z'; caracter++){

		printf("%c ", *apuntadorCaracter);

	}

	puts("\n-------------");

	for (caracter = 'a'; caracter <= 'z'; caracter++){
	
		printf("%c ", *apuntadorCaracter);
	
	}


	return 0;
}
