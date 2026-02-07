/*
 * Write a program to find the sum of all elements of an array
 * The task requires program to read a specified number of integers
 * into an array and then calculate and print the sum of these
 * elements. After storing the input values, the program should 
 * iterate through the array to compute the total sum and display 
 * the result*/

#include<stdio.h>

int main(){
  long arr[] = {};
  long sum = 0;
  for (int i=1;i<=10;i++) {
    printf("Ingresa un numero\n");
    scanf("%d", &arr[i]);
  }
  for (int j =1;j<=10;j++) {
    sum += arr[j];
  }

  printf("La suma total es de %d\n", sum);
  return 0;
}
