 /* CONDICIONALES
* SENTENCIA IF
* Sintaxis
* if (true) {
* Bloque de codigo
}*/

#include <stdio.h>

int main(){
	int a, b;

	printf("Digite primer numero\n");
	scanf("%i", &a);
	printf("Digite segundo numero\n");
	scanf("%i", &b);
	if(a + b == 6){
		printf("El resultado es: %i", a+b);
	}else{
		printf("El resultado es: %i", a+b);
	}
	return 0;
}
