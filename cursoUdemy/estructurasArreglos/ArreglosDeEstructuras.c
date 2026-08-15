/* ARREGLOS DE ESTRUCTURAS EN C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void leer_nombre(char *buf, size_t tamano);
static int leer_entero();

struct persona{
	char nombre[20];
	int edad;
}persona[5];

int main(){
	int i;
	for (int i = 0; i < 5; i++) {
		printf("Escribe el nombre de la persona %d\n", (i + 1));
		leer_nombre(persona[i].nombre, sizeof persona[i].nombre);
		printf("Escribe la edad de la persona %d\n", (i + 1));
		persona[i].edad = leer_entero();
	}
	return 0;
}

static void leer_nombre(char *buf, size_t tamano){
	if (fgets(buf, (int)tamano, stdin) == NULL) {
		buf[0] = '\0';
		return;
	}
	size_t len = strlen(buf);
	if (len > 0 && buf[len - 1] == '\n') {
		buf[len - 1] = '\0';
		return;
	}
}

static int leer_entero(){
	char linea[64];
	if (fgets(linea,sizeof linea, stdin) == NULL) return 0;
	int valor = 0;
	sscanf(linea, "%d", &valor);
	return valor;
}
