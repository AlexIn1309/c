// factorial
/* 1 * 1 = 1
 * 1 * 2 = 2
 * 2 * 3 = 6
 * 6 * 4 = 24
 * 24 * 5 =120
 *
 * */

#include<stdio.h>
#define PI 3.1416

int main(){
  int numero=0;
  int factorial = 0;
  printf("Escribe un numero\n");
  scanf("%d",&numero);
  // recibimos 5
  // tenemos que comenzar a multiplicar 1 * 2
  for (int i = 1;i<numero;i++) {
    if (i == 1) {
      factorial = 2;
    }
    if (i != 1) {
      factorial = factorial * (i+1);
      printf("ciclo :%d\n", i);
      printf("factorial actual: %d\n", factorial);
    }
  }
  printf("factorial final: %d\n\n", factorial);
  return 0;
}
