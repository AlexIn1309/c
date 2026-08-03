#include <stdio.h>
#include <math.h>
#include <errno.h>

#define PI 3.14159265358979323846

/* Wrappers con manejo de errores o conversiones según se requiera */
double miACos(double numero);
double miASin(double numero);
double miATan(double numero);
double miCos(double numero);
double miSin(double numero);
double miTan(double numero);

int main(void) {
    double miNumero = 0;

    puts("Ingresa un numero para realizar los calculos:");
    if (scanf("%lf", &miNumero) != 1) {
        fprintf(stderr, "Error: Entrada no valida.\n");
        return 1;
    }

    printf("\n--- Resultados (Valores en Radianes) ---\n");

    /* Validación de dominio para acos y asin */
    if (miNumero >= -1.0 && miNumero <= 1.0) {
        printf("acos(%.2f) = %.4f rad\n", miNumero, miACos(miNumero));
        printf("asin(%.2f) = %.4f rad\n", miNumero, miASin(miNumero));
    } else {
        printf("acos/asin: Fuera de dominio [-1, 1] (produce NaN)\n");
    }

    printf("atan(%.2f) = %.4f rad\n", miNumero, miATan(miNumero));
    printf("cos(%.2f)  = %.4f\n", miNumero, miCos(miNumero));
    printf("sin(%.2f)  = %.4f\n", miNumero, miSin(miNumero));
    printf("tan(%.2f)  = %.4f\n", miNumero, miTan(miNumero));

    return 0;
}

double miACos(double numero) { return acos(numero); }
double miASin(double numero) { return asin(numero); }
double miATan(double numero) { return atan(numero); }
double miCos(double numero)  { return cos(numero);  }
double miSin(double numero)  { return sin(numero);  }
double miTan(double numero)  { return tan(numero);  }
