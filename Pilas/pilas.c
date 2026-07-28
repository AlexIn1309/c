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
    printf("%d, \n", temp->valor);
    temp = temp->sig;
  }
}

int main()
{
  // Podemos agregar un dato al inicializar
  struct Nodo* pila = crearNodo(15);

  push(1, &pila);
  push(9, &pila);
  push(7, &pila);
  push(5, &pila);
  printf("creado\n");
  mostrar(&pila);
  
  return 0;
}
