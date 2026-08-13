/* BUSQUEDA BINARIA
 * Generar un arreglo de 10 elementos desordenados
 * Despues ordenarlos con el metodo burbuja
 * Finalmente, pedir un dato al usuario y buscarlo dentro del arreglo
 * y utilizar la busqueda binaria para determinar si existe o no */

#include <stdio.h>

void metodoBurbuja(int miArr[]);
void imprimirArreglo(int miArr[]);
void busquedaBinaria(int miArr[], int numBuscaar);

int main(){
	int miArreglo[10] = {1,3,5,7,9,2,4,6,8,10};
	int dato;

	metodoBurbuja(miArreglo);

	imprimirArreglo(miArreglo);

	puts("Ingresa valor a buscar");
	scanf("%d", &dato);

	busquedaBinaria(miArreglo, dato);

	// Metodo burbuja
	return 0;
}

void metodoBurbuja(int miArr[]){
	int auxiliar;
	for (int i = 0; i< 10; i++) {
		for (int j = 0; j < 10;j++) {
			if (miArr[j] > miArr[j + 1]) {
				auxiliar = miArr[j];
				miArr[j] = miArr[j + 1];
				miArr[j + 1] = auxiliar;
			}
		}
	}
}

void imprimirArreglo(int miArr[]){
	puts("Arreglo Ordenado");
	for (int i = 1; i< 10; i++) {
		printf("%i\n", miArr[i]);
	}
}

void busquedaBinaria(int miArr[], int numBuscaar){
	int inferior = 0;
	int superior = 10;
	int mitad;
	char bandera = 'F';
	while (inferior < superior) {
		mitad = (inferior + superior) / 2;

		if (miArr[mitad] == numBuscaar) {
			bandera = 'V';
			break;
		}
		if (miArr[mitad] > numBuscaar) {
			superior = mitad;
			mitad = (inferior + superior) / 2;
		}
		if (miArr[mitad] < numBuscaar) {
			inferior = mitad;
			mitad = (inferior + superior) / 2;
		
		}

	}

	if(bandera == 'F'){
		puts("El nunero no existe");
	}else{
		printf("El numero '%d' esta en la posicion: %d", numBuscaar, mitad);
	}
}
