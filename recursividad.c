#include <stdio.h>

int factorizar(int num, int contador, int limite){
  printf("mi numero es: %d\n", num);
  if (limite != contador + 1) {
    contador++;
    printf("conteo: %d\n", contador);
    num =  num * contador;
    num = factorizar(num, contador, limite);
  }
  return num;

}

int main(){
	int num = 0;
	int resultado = 0;
	printf("Escribe un numero: \n");
  scanf("%d", &num);
  int limite = num;
  resultado = factorizar(num, 1, limite);
  printf("El factor de %d es %d\n", num, resultado);
  return 0;
}
