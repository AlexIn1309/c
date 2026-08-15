/* CREAR UN TIPO DE DATO CON ESTRUCTURAS
 * typedef structNombreDeLaEstructura
 * Variable_1
 * Variable_2
 * Variable_3  */

#include <stdio.h>

int main(){
	// Definir un nuevo tipo de dato llamado "MiNuevoTipoDeDato"
	typedef int MiNuevoTipoDeDato;
	typedef float Gastos;
	Gastos comida = 100.98;

	// Ahora puedes generar mas datos de este mismo tipo
	MiNuevoTipoDeDato variable_1;
	// Siendo de igual manera que su tipo de dato fundamental como lo es el 'int'
	int variable_2;
	puts("Ingresa 1 entero");
	scanf("%d",&variable_1);
	puts("Ingresa 2do entero");
	scanf("%d",&variable_2);
	printf("Tu numero 1 es: %d\n", variable_1);
	printf("Tu numero 2 es: %d\n", variable_2);
	return 0;
}
