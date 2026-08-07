/*
 * This task requires writing a C program to read a user-defined number of integer  
 * values into a n array and then display these values in reverse oreder. After storing the values, the program
 * should first print them in the original order and then print them in the reversed order.
 * */

#include<stdio.h>

int main(){
  long arr[] = {};
  int i =0;
  int j =0;
  int k = 0;
  for (i = 1;i <= 10;i++) {
    printf("Ingresa el elemento %d\n", i);
    scanf("%d", &arr[i]);
  }
  long a[10];
  long length;
  length = sizeof(a) / sizeof(long);
  printf("Orden correcto\n");
  for (j = 1; j <= length; j++) {
    printf("Elemento %d es %d\n",j, arr[j]);
  }

  printf("Impresion reversed\n");
  for (k = 10; k >= 1; k--) {
    printf("Elemento %d es %d\n",k, arr[k]);
  }
}
