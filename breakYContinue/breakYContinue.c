/* BREAK & CONTINUE
 * Sintaxis
 *  */

#include <stdio.h>

int main(){
	int multiplo = 0;

	printf("Escribe el numero que sera ignorado\n");
	scanf("%i", &multiplo);

	for(int i = 0; i < (multiplo * 5); i++){
		if(i == multiplo)
			continue;
			printf("\n%i", i);
	}
	puts("///////////////////////");
	
	for(int i = 0; i < (multiplo * 5); i++){
		if(i == multiplo)
			break;
			printf("\n%i", i);
	}
	return 0;
}
