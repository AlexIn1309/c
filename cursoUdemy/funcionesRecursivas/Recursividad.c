/* RECURSIVIDAD
 * Cuenta regresiva
 * */

#include <stdio.h>

void cuentaRegresiva(int numero){
	// Si el numero es menor a 0, se finaliza
	if(numero <= 0){
		return;
	}else {
		// En caso contrario, se llama a si misma
		printf("El numero es: %d\n", numero);
		cuentaRegresiva(numero-1);
	}
}

int main(){
	int n = 0;
	puts("Ingresa un numero");
	scanf("%d", &n);
	cuentaRegresiva(n);
	return 0;
}
