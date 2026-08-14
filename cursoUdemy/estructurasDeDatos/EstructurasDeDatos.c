/* ESTRUCTURAS DE DATOS EN C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generamos una estructura de datos

static void leer_nombre(char *buf, size_t size);
static int leer_entero();

struct persona{
	char nombre[20];
	int edad;
}persona1 = {"Alejandro", 26}, persona2 = {"Mia", 9};// Generamos 2 personas de tipo persona

int main(){
	puts("Ingresa el nombre de la persona 1");
	leer_nombre(persona1.nombre, sizeof persona1.nombre);
	puts("Ingresa la edad de la persona 1");
	persona1.edad = leer_entero();

	puts("Ingresa el nombre de la persona 2");
	leer_nombre(persona2.nombre, sizeof persona2.nombre);
	puts("Ingresa la edad de la persona 2");
	persona2.edad = leer_entero();
	
	printf("Persona 1 es: %s y tiene %d años\n", persona1.nombre, persona1.edad);
	printf("Persona 2 es: %s y tiene %d años\n", persona2.nombre, persona2.edad);
	return 0;
}

static void leer_nombre(char *buf, size_t size){
	if(fgets(buf, (int)size, stdin) == NULL){
		buf[0] = '\0';
		return;
	}
	size_t len = strlen(buf);
	if(len > 0 && buf[len - 1] == '\n'){
		buf[len - 1] = '\0';
		return;
	}
}

static int leer_entero(){
	char line[64];
	if(fgets(line, sizeof line, stdin) == NULL)return 0;
	int valor = 0;
	sscanf(line, "%d", &valor);
	return valor;
}


