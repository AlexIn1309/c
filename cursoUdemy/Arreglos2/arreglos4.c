/* Escribe un programa en el cual se solicite al usuario 
 * llenar un arreglo de de 10 elementos 
 * Siendo posible unicamente ingresar 0s y 1s
 * Una vez que el usuario llene el arreglo con la 
 * representacion de un numero binario 
 * Podra elegir entre las siguientes condificaciones */

/* a) Binario puro
 * b) Punto fijo (6 bit entero y 4 bit decimal)
 * c) Complemento a 2 */

/* El programa realizara la conversion y 
 * como salida mostrara el resultado en representacion decimal */

#include <stdio.h>

void binarioPuro(int numArreglo[]);
void puntoFijo(int numArreglo[]);
void complementoA2(int numArreglo[]);

int main(){
	int miArreglo[10];
	int miSwitch = 1;
	char leerOpcion = 'a';
	puts("Llena el arreglo de 10 elementos");
	puts("Recibiendo unicamente 0s y 1s");
	for (int i = 0; i< 10;i++) {
		printf("Ingresa el numero: %d\n", i);
		scanf("%d", &miArreglo[i]);
		if (miArreglo[i] > 1) {
			puts("Unicamente recibe 1s y 0s");
			i--;
		}
	}



	while (miSwitch == 1) {

	puts("Escoge una opcion");
	puts(" a) Binario puro");
	puts(" b) Punto fijo (6 bit entero y 4 bit decimal)");
	puts(" c) Complemento a 2");
	puts(" d) Salir");
	scanf(" %c", &leerOpcion);
		switch (leerOpcion) {
			case 'a':
				binarioPuro(miArreglo);
			break;
			case 'b':
				puntoFijo(miArreglo);
			break;
			case 'c':
			break;
				case 'd':
				miSwitch=0;
			break;
				default:
				puts("Ingresa una opcion valida");
			break;
		}
	}
	return 0;
}


void binarioPuro(int numArreglo[]){
	int valor = 512;
	int convertido = 0;

	for (int i = 0; i < 10; i++) {
		if (numArreglo[i] == 1) {
			convertido +=valor;
		}
		valor /=2;
	}

	printf("El valor es: %i", convertido);
}

void puntoFijo(int numArreglo[]){
	int convertido = 0;
	int valor = 32;
	float convertidoDecimal = 0;
	float valorDecimal = 0.5;

	for (int i = 0; i < 6; i++) {
		if (numArreglo[i] == 1) {
			convertido += valor;
		}
		valor/=2;
	}

	for (int i = 6; i < 10; i++) {
		if (numArreglo[i] == 1) {
			convertidoDecimal += valor;
		}
		valor/=2;
	}
	printf("El valor convertido es: %.4f", convertido + convertidoDecimal);
}

void complementoA2(int numArreglo[]){
	for (int i = 0;i < 10;i++) {
		if (numArreglo[i] == 1) {
			numArreglo[i] = 0;
		}else {
			numArreglo[i] = 1;
		}
	}
}
