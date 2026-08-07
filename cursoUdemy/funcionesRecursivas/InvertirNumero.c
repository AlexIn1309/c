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
	char* invertido = (char*)malloc(12*sizeof(char));
	if(invertido == NULL) return "";
	char temporal[12];
	int longitud = snprintf(temporal, sizeof(temporal), "%d", num);

	int inicio = 0;
	int j = 0;
	if (num < 0) {
		invertido[0] = '-';
		inicio = 1;
		j = 1;
	}

	for(int i = longitud - 1; i >= inicio; i-- ){
		invertido[j++] = temporal[i];
	}
		invertido[j] = '\0';
	return invertido;
}
