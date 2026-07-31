/* STRCPY (Destino, Fuente)
 * Permite copiar una cadena de texto en otra.
 * Debes considerar que la dimension del array destino debe de ser igual o mayor que el array origen
 * y que ademas sobreescribe el contenido del destino*/

#include <stdio.h>
#include <string.h>

int main(){
	char origen[] = "Programacion";
	// Dado que "Programacion" tiene 12 caracteres
	// Creamos el array destino de la misma dimension
	
	char destino[13];
	
	strcpy(destino, origen);
	printf("%s\n", destino);
	printf("Impresion");
	
	return 0;
}
