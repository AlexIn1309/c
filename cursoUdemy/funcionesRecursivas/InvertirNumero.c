/* INVERTIR NUMERO CON RECURSIVIDAD
 * Se realizara una funcion para invertir o voltear un numero con recursividad*/

#include <stdio.h>
#include <stdlib.h>

char* invertir(int num);

int main(){
	int numero;
	

	do {
		puts("Ingresa un numero entero");
		scanf("%d",&numero);
	} while (numero<0);

	char* resultado = invertir(numero);
	printf("Tu numero es: %s\n", resultado);

	free(resultado);

	return 0;
}

char* invertir(int num){
	char* numString = (char*)malloc(12*sizeof(char));

	if (numString != NULL) {
		snprintf(numString, 12, "%d", num);
	}
	return numString;
}
