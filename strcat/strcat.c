/* STRCAT (Destino, Fuente) 
 * Concatena la cadena fuente en el destino.
 * Debes considerar que la cadena destino 
 * debe de tener un tamano tal que pueda albergar la cadena resultante*/

#include <stdio.h>
#include <string.h>

int main(){
	char cadena1[] = "Alejandro";
	char cadena2[] = "Moran";

	char final[50];

	// Concatenamos

	strcat(final,cadena1);
	strcat(final," - ");
	strcat(final,cadena2);
	
	// Imprimimos
	printf("El nombre es: %s", final);
	
	return 0;
}
