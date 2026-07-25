/* Ingresa por teclado el nombre y el signo 
 * de cualquier persona y lo imprimes
 * solamente si la persona es signo aries
 * Por caso contrario, imprima No es signo aries */ 

#include <stdio.h>
#include <ctype.h>
#include <string.h> // obligatorio para usar strcmp y strcspm

int main(){
	// Inicializar las variables del signo y el nombre
	char nombre[50], signo[50];
	
	puts("Escribe tu nombre");
	fgets(nombre, 50, stdin);
	puts("Escribe tu Signo Zodiacal");
	fgets(signo, 50, stdin);
	
	
	// Eliminar el salto de línea al final de la cadena
	signo[strcspn(signo, "\n")] = '\0';

	for(int i = 0; i < signo[i] != '\0'; i++){
		signo[i] = toupper((unsigned char)signo[i]);
	}
	
	if( strcmp(signo, "ARIES")  == 0) {
	
		printf("Nombre: %s\n", nombre);
		printf("Signo: Aries\n");
	
	}else{

		puts("No es Aries");
	}
	return 0;
}
