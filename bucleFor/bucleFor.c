/* BUCLE FOR
 * Sintaxis:
 * for(int i = 0; condicion ; i++){
 *	bloque de codigo
 * } */

#include <stdio.h>

int main(){
	int miarreglo[] = {9,7,4,5};
	int tamanyo = sizeof(miarreglo) / sizeof(miarreglo[0]);
	for(int i = 0; i < tamanyo ; i++){
		printf("El elemento de tu arreglo es: %i\n", miarreglo[i]);
	}
	return 0;
}
