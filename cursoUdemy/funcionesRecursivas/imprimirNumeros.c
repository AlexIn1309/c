/* Imprimir Numeros 
 * hasta el numero que el usuario ingrese 
 * Pero con una funcion recursiva*/

#include <stdio.h>

int miFuncionRecurisva(int numero){
	if (numero <=0) {
		return 1;
	}else {
		printf("Contando: %d\n", numero);
		miFuncionRecurisva(numero - 1) + 1 ;
	}
	return numero;
}

int main(int argc, char *argv[])
{
	int numUser = 0;
	puts("Ingresa un numero");
	scanf("%d", &numUser);

	for (int i = numUser; i > 0;i--) {
		printf("%d\n", miFuncionRecurisva(i));
	}
	
	return 0;
}


