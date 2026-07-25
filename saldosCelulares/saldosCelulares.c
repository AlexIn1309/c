/* SALDOS DE CELULARES
 * Calcular tarifas de saldo en celulares 
 * y poner precios
 * De 1000 a 1500 Premium
 * De 500 a 999 Intermedia
 * De 100 a 499 Basica */

#define Tarifa1 "Premium"
#define Tarifa2 "Intermedia"
#define Tarifa3 "Basica"

#include <stdio.h>
#include <string.h>

int main(){
	float precio;
	char plan[50];
	printf("%s",&Tarifa1);
	puts("Digite el Monto: ");
	scanf("%f", &precio);
	if(precio >= 1000 && precio <= 1500){
		strcpy(plan, Tarifa1);
	}
	if(precio >= 500 && precio <= 999){
		strcpy(plan, Tarifa2);
	}
	if(precio >= 100 && precio <= 499){
		strcpy(plan, Tarifa3);
	}

	printf("El plan que puedes costear es: %s", plan);
	return 0;
}
