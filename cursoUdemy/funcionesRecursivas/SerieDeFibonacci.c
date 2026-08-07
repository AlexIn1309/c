/* SERIE DE FIBONACCI CON RECURSIVIDAD */

#include <stdio.h>

unsigned long long memo[100] = {0};

unsigned long long serieDeFibonacci(int num) {
    if (num == 1 || num == 2) return 1;
    if (memo[num] != 0) return memo[num]; // Si ya se calculó, se devuelve de inmediato

    memo[num] = serieDeFibonacci(num - 1) + serieDeFibonacci(num - 2);
    return memo[num];
}

int main() {
    int numero = 0;
    puts("Ingresa un numero: ");
    scanf("%d", &numero);
    
    for (int i = 1; i <= numero; ++i) {
        printf("%llu\n", serieDeFibonacci(i));
    }
    return 0;
}
