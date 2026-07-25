/* OPERADOR TERNARIO
* Sintaxis:
* Condicion ? Expresion1 : Expresion2;*/

#include <stdio.h>

int main(){
	int numero;
	puts("Escribe un numero\n");
	scanf("%i", &numero);
	(numero%2==0) ? printf("El numero es par\n"): printf("El numero es impar\n");
	return 0;
}
