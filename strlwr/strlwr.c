/* STRLWR
 * strlwr(cadena)
 * Convierte a minusculas las letras de una cadena de texto*/

#include <stdio.h>
#include <ctype.h>

char *strlwr(char *cadena){
	for (int i = 0; cadena[i] != '\0';i++) {
		cadena[i] = tolower((unsigned char)cadena[i]);
	}
	return cadena;
}

int main(){
	char texto[200];

	puts("Ingresa una cadena de caracteres con mayusculas");
	scanf("%99s", texto);
	printf("Tu cadena de caracteres es: %s\n", strlwr(texto));
	return 0;
}
