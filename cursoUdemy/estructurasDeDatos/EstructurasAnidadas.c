/* 153. Estructuras Anidadas */

#include <stdio.h>
#include <string.h>

struct infoDireccion{
	char direccion[30];
	char ciudad[20];
	char provincia[20];
};

struct empleado{
	char nombre[30];
	struct infoDireccion dirEmpleado;
	double salario;
}empleados[2];

static void leer_cadena(char *buf, size_t size);
static double leer_flotante();
static void printEmpleado(struct empleado miEmpleado);


int main(){
	for(int i = 0; i < 2;i++){
		printf("Ingresa nombre de persona %d\n", i + 1);
		leer_cadena(empleados[i].nombre, sizeof empleados[i].nombre);
		puts("Ingresa Direccion:");
		leer_cadena(empleados[i].dirEmpleado.direccion, sizeof empleados[i].dirEmpleado.direccion);
		puts("Ingresa Ciudad:");
		leer_cadena(empleados[i].dirEmpleado.ciudad, sizeof empleados[i].dirEmpleado.ciudad);
		puts("Ingresa Provincia:");
		leer_cadena(empleados[i].dirEmpleado.provincia, sizeof empleados[i].dirEmpleado.provincia);
		puts("Ingresa Salario:");
		empleados[i].salario = leer_flotante();
	}

	for(int i = 0; i < 2; i++){
		printEmpleado(empleados[i]);
	}
}

static void leer_cadena(char *buf, size_t size){
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

static double leer_flotante(){
	char line[64];
	if(fgets(line, sizeof line, stdin) == NULL)return 0;
	double valor = 0;
	sscanf(line, "%lf", &valor);
	return valor;
}

static void printEmpleado(struct empleado miEmpleado){
	printf("Nombre es %s\n", miEmpleado.nombre);
	printf("Salario %.4f\n", miEmpleado.salario);
	printf("Direccion %s\n", miEmpleado.dirEmpleado.direccion);
}
