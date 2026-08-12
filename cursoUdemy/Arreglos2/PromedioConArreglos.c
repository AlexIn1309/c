/* PROMEDIO CON ARREGLOS */

#include <stdio.h>

int main(){
	// 8 datos
	int x[8];

	// Suma dde valores
	int suma = 0;

	for (int i = 0; i < 8; i++) {
		printf("\nDato:  %d\n", i + 1);
		scanf("%d", &x[i]);
		suma += x[i];
	}

	float promedio = suma / 8;
	printf("\nEl promedio de tus elementos es %.2f\n", promedio);

	return 0;
}
