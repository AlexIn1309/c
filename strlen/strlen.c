/* STRLEN
 * strlen(cadena) 
 * Devuelve un entero que representa la longitud de una cadena de texto
 * (Incluyendo espacios en blanco, pero excluyendo el caracter nul)*/

#include <stdio.h>
#include <string.h>

int main(){
	// El tamaño de la variable puede ser manyor al de la cadena real
	char arreglo[200];
	puts("Ingresa una cadena de caracteres");
	fflush(stdin);
	scanf("%s",arreglo);
	printf("\nLa longitud de tu cadena es %i",strlen(arreglo));
	return 0;
}
