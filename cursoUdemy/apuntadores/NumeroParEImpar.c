/* NUMERO PAR E IMPAR
 * Comprobar si un numero es par o impar y señalar la posicion
 * de memoria donde se encuentra guardado el número con punteros. */

#include <stdio.h>

static int leer_entero();

int main(){
	int numero, *apuntadorNumero;
	puts("Ingresa un Numero");
	numero = leer_entero();
	apuntadorNumero = &numero;
	if(*apuntadorNumero % 2 == 0){
		printf("El numero %d es par\n", numero);
		printf("La direccion en memoria es %p\n", apuntadorNumero);
	}else{
		printf("El numero %d es impar\n", numero);
		printf("La direccion en memoria es %p\n", apuntadorNumero);
	}
}

static int leer_entero(){
	char line[64];
	if(fgets(line, sizeof line, stdin) == NULL)return 0;
	int valor = 0;
	sscanf(line, "%d", &valor);
	return valor;
}
