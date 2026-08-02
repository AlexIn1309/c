/* FUNCIONES MATEMATICAS
 * ceil(x) -> Redondea al entero mayor mas cercano
 * fabs(x) -> Devuelve el valor absoluto de x
 * floor(x) -> Redondea al entero menor mas cercano
 * sqrt(x) -> Saca la raiz cuadrada de x
 * fmod(x, y) -> Calcula el resto de la division de x \ y
 * pow(x, y) -> Calcula x elevado a la potencia y*/

#include <stdio.h>
#include <math.h>

double miCeil(double numero);
double miFabs(double numero);
double miFloor(double numero);
double miRaiz(double numero);
double miFmod(double numero);
double miPow(double numero);

int main(){
	double miNumero = 0;
	puts("Ingresa un numero:"); 
	scanf("%lf", &miNumero);
	printf("Resultado de funcion CEIL: %.2f\n", miCeil(miNumero));
	printf("Resultado de funcion FABS: %.2f\n", miFabs(miNumero));
	printf("Resultado de funcion FLOOR: %.2f\n", miFloor(miNumero));
	printf("Resultado de funcion SQRT: %.2f\n", miRaiz(miNumero));
	printf("Resultado de funcion FMOD: %.2f\n", miFmod(miNumero));
	printf("Resultado de funcion POW: %.2f\n", miPow(miNumero));
	return 0;
}

double miCeil(double numero){
	return ceil(numero);
}

double miFabs(double numero){
	return fabs(numero);
}

double miFloor(double numero){
	return floor(numero);
}

double miRaiz(double numero){
	return sqrt(numero);
}

double miFmod(double numero){
	return fmod(numero*2,numero);
}

double miPow(double numero){
	return pow(numero, numero - (numero/2));
}
