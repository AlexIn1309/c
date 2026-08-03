/* SRAND
 * srand(time(NULL))
 * variable = limiteInferior + rand()%((limiteSuperior + 1) - limiteInferior)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int funcionAleatoria(void);

int main(void) {
    funcionAleatoria();
    return 0;
}

int funcionAleatoria(void) {
    int numero;

    srand(time(NULL));

    numero = 1 + rand() % 100;

    printf("Tu numero de la suerte es: %d\n", numero);

    return numero;
}
