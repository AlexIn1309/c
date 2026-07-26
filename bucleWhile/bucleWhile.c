/* BUCLE WHILE
 * Sintaxis
 * while(){
 *	Bloque de codigo
 * } */

#include <stdio.h>

int main(){
	bool flag = true;
	char cambio = 'n';
	while(flag){
		puts("Quieres cambiar el valor de flag?");
		puts("Si = S");
		puts("No = N");
		scanf(" %c", &cambio);
		if(cambio == 's')flag = false;
		
		printf("El valor es: %d\n", flag);

	}
	return 0;
}
