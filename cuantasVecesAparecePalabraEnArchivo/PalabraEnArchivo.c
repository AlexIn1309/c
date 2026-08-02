#include <stdio.h>
#include <string.h>

int main(){
	FILE* miArchivo = fopen("prueba.txt", "r");
	int apariciones = 0;

	if (miArchivo == NULL) {
		puts("This function doesn't need newline.");
	}else {
		char textoRecibido[1000];
		char palabraBuscada[20];
		puts("Cual es la palabra que estas buscando?");
		scanf("%s", palabraBuscada);
		while (fscanf(miArchivo, "%s", textoRecibido) != EOF) {
			if (strcmp(textoRecibido, palabraBuscada) == 0) {
				apariciones++;
			}
		}
	}
	fclose(miArchivo);
	printf("La palabra esta presente %i veces",apariciones);
	return 0;
}
