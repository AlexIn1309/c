// Escribe un programa para trabajar sobre un arreglo de 10 elementos 
// En el cual se solicite al usuario los valores de dicho arreglo y
// posteriormente se puedan hacer las siguientes operaciones

// 1) Ingresar o Modificar los Elementos del arreglo
// 2) Calcular la Suma de los elementos
// 3) Calcular el Producto de los elementos
// 4) Calcular la Suma de los elementos divisibles entre 3
// 5) Multiplicar por 3 cada elemento del arreglo

#include <stdio.h>

int main(){
	int miArreglo[10];
	for(int i = 0; i < 10;i++){
		printf("Ingresa el numero: %i\n", i);
		scanf("%d", &miArreglo[i]);
	}

	int tamano = sizeof(miArreglo) / sizeof(miArreglo[0]);

	int iterador = 0;
	
	while(iterador < tamano){
		printf("Tu numero es: %i\n", miArreglo[iterador]);
		iterador++;
	}
	return 0;
}
