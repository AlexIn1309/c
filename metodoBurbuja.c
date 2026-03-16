#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Nodo {
  int valor;
  struct Nodo* sig;
}; 

struct Nodo* crearNodo(int dato){
  struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
  nuevo->valor = dato;
  nuevo->sig = NULL;

  return nuevo;
}

void push(int dato, struct Nodo** pila){
  struct Nodo* nuevo = crearNodo(dato);

  nuevo->sig = *pila;
  *pila = nuevo;
}

int pop(struct Nodo** pila){
  if (!(*pila)) {
    return INT_MIN;
  }
  struct Nodo* primero = *pila;
  int dato = primero->valor;
  *pila = (*pila)->sig;
  free(primero);
  return dato;

  }

int mostrar(struct Nodo** pila){
  struct Nodo* temp = *pila;
  while(temp){
    printf("%d  ", temp->valor);
    temp = temp->sig;
  }
}

void ordenar(struct Nodo** pila){
  if (*pila == NULL) {
    printf("No hay elementos en la pila\n");
    return;
  }
  int aux = 0;
  int terminar = 0;
  do {
    terminar = 0;
  int misiguiente = 0;
  int mivalor = 0;
  struct Nodo* temp = *pila;
  struct Nodo* control = NULL;
  int contador = 0;
  
  while(temp->sig != control){
    contador ++;
    mivalor = temp->valor;
    misiguiente = temp->sig->valor;
    //printf("Esta es mi pila: %d \n", mivalor);
    //printf("Este es mi siguiente valor: %d \n", misiguiente);
      if (misiguiente < mivalor) {
        //printf("Intercambio %d\n",mivalor);
        aux = temp->valor;
        temp->valor = temp->sig->valor;
        temp->sig->valor = aux;
        terminar = 1;
      }
    temp = temp->sig;
  }
  }while(terminar);
}

int main()
{
  // Podemos agregar un dato al inicializar
  //struct Nodo* pila = crearNodo(15);
  struct Nodo* pila = NULL;
  int leer = 0;

  for (int i =0 ;i < 5;i++) {
  printf("Ingresa un numero\n");
    scanf("%d", &leer);
  push(leer, &pila);
  }
  printf("Numeros Ingresados: \n");
  mostrar(&pila);
  ordenar(&pila);
  
  printf("\n");
  printf("\n");
  printf("Numeros ordenados: \n");

  mostrar(&pila);
  return 0;
}
