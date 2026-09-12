/* NUMEROS PRIMOS
 * Determinar si un numero es primo o no con punteros e
 * indicar en qué posicion de memoria se guardó el numero. */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool esPrimo(int n);
static int leer_entero();

int main(){
	int numero, *apuntadorNumero = &numero;
	puts("Introduce un numero");
	numero = leer_entero();
	if(esPrimo(numero)){
		printf("El numero %d es primo.\n", numero);
	}else{
		printf("El numero %d NO es primo.\n", numero);
	}
	return 0;
}

bool esPrimo(int n){
	if(n<2)return false;
	// 2 y 3 son primos
	if(n<4)return true;
	// Descartamos multiplos de 2 y 3
	if(n%2 == 0 || n%3 == 0) return false;
	
	// Comprobar divisores hasta sqrt(n)
	int limite = (int)sqrt(n);
	for(int i = 5; i <= limite; i+=6){
		if(n % i == 0 || n % (i + 2) == 0){
			return false;
		}
	}
	return true;
}

static int leer_entero(){
	char line[64];
	if(fgets(line, sizeof line, stdin) == NULL)return 0;
	int valor = 0;
	sscanf(line, "%d", &valor);
	return valor;
}
