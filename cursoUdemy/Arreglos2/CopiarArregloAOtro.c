/* COPIAR UN ARREGLO A OTRO */

#include <stdio.h>

void copiandoArreglos(int arrA[], int arrb[], int tamano);
void imprimirArreglo(int arregloImprimir[]);

int main(){
	int arreglo1[5] = {2,3,4,5,6};
	int arregloDos[5];
	imprimirArreglo(arregloDos);

	printf("Copiando arreglo1 a arregloDos...\n");
	copiandoArreglos(arreglo1,arregloDos,5);
	imprimirArreglo(arregloDos);

	return 0;
}

void copiandoArreglos(int arrA[], int arrB[], int tamano){
	for (int i = 0; i < tamano; i++) {
		arrB[i] = arrA[i];
	}
}

void imprimirArreglo(int arregloImprimir[]){
	for (int i = 0; i < 5; i++) {
		printf("%i", arregloImprimir[i]);
	}
}
