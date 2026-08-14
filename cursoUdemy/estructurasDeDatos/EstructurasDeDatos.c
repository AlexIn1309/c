/* ESTRUCTURAS DE DATOS EN C */

#include <stdio.h>

// Generamos una estructura de datos

struct persona{
	char nombre[20];
	int edad;
}persona1 = {"Alejandro", 26}, persona2 = {"Mia", 9};// Generamos 2 personas de tipo persona

int main(){
	printf("Persona 1 es: %s y tiene %d años\n", persona1.nombre, persona1.edad);
	printf("Persona 2 es: %s y tiene %d años\n", persona2.nombre, persona2.edad);
	return 0;
}
