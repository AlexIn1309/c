/* Se genera una funcion que devuelve numeros ordenados */

#include <stdio.h>

void ordenamientoAscendente(int a, int b, int c, int *resultado){
	// Almacenar los valores iniciales
	resultado[0] = a;
	resultado[1] = b;
	resultado[2] = c;

	// Algoritmo simple de ordenamiento para 3 elementos
	int auxiliar;

	if (resultado[0] > resultado[1]) {
		auxiliar = resultado[0];
		resultado[0] = resultado[1];
		resultado[1] = auxiliar;
	}
	if(resultado[1] > resultado[2]){
		auxiliar = resultado[1];
		resultado[1] = resultado[2];
		resultado[2] = auxiliar;
	} 
	// Verificar de nuevo el primero por si el intercambio anterior lo desordeno
	
	if (resultado[0] > resultado[1]) {
		auxiliar = resultado[0];
		resultado[0] = resultado[1];
		resultado[1] = auxiliar;
	}
}

int main(){
	int a,b,c;
	int resultado[3]; // Arreglo paraa guardar 3 numeros
	puts("Ingresa un numero");
	scanf("%d",&a);
	puts("Ingresa el siguiente numero");
	scanf("%d",&b);
	puts("Ingresa el ultimo numero");
	scanf("%d",&c);
	ordenamientoAscendente(a,b,c, resultado);
	printf("Tu arreglo ordenado es: [%d, %d, %d]\n", resultado[0], resultado[1], resultado[2] );
	return 0;
}


