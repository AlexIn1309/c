/* CONVERTIR UN NUMERO ENTERO A BINARIO */

#include <stdio.h>

void numeroEnteroABinario(int num);

int main(){
	int numero = 0;
	do {
		puts("Ingresa un numero entero");
		scanf("%d", &numero);
	} while (numero<0);
	numeroEnteroABinario(numero);
	return 0;
}

void numeroEnteroABinario(int num){
	if (num>1) numeroEnteroABinario(num/2);
	printf("%d",num%2);
}
