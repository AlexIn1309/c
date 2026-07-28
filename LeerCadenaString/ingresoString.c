#include<stdio.h>
// Recibe nombre y saluda con nombre

int main(){
  char nombre[100];
  printf("Escribe tu nombre: ");
  scanf("%100s", nombre);
  printf("Hola %s\n", nombre);
}
