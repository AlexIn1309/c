/*
 * Escriba un programa que calcule la raiz cuadrada de un numero con n decimales, por el metodo de aproximaciones sucesivas
 * Nota: Metodo de aproximaciones sucesivas
 * Se basa en ensayo y error. A este tipo de algoritmos se les llama de aproximaciones sucesivas:
 * se empieza por un valor inicial y se va modificando para acercarse al resultado
 * En ested caso se comienza suponiendo que la raiz es 1
 * Se comprueba la raiz * raiz = num
 * y si no es asi, se suma un incremento, y se vuelve a comprobar.
 * Se repiten estos pasos hasta que raiz*raiz>num
 * Para computar el valor con un numero determinado de decimales se repiten esos pasos con un incremento cada vez menor
 * La primera vuela 1, la segunda vuelta 0,1, la tercera vuelta 0,01
 * En cada paso la precision es una decimal mas, por lo que se repite hasta que el numero de decimales sea
 * introducido por el usuario, o hasta que se encuentre el valor exacto
 * */

#include<stdio.h>

int main(){
  printf("Ingresa tu numero raiz\n");
  float sup = 0;
  scanf("%f", &sup);
  float x = sup /2;
  float num = 0;
  for (int i = 0;i < 10;i++) {
    num = 0.5 * (x + sup / x);
    x = num;
  }
  printf("el resultado es: %f\n", x);
  return 0;
}

