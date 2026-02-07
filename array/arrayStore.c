/*
 * Write a programming in C to store elements in an array and print them
 * */

#include<stdio.h>

int main(){
  long arr[] = {};
  int i =0;
  int j =0;
  for (i = 1;i <= 10;i++) {
    printf("Ingresa el elemento %d\n", i);
    scanf("%d", &arr[i]);
  }
  long a[10];
  long length;
  length = sizeof(a) / sizeof(long);
  for (j = 1; j <= length; j++) {
    printf("Elemento %d es %d\n",j, arr[j]);
  }
}
