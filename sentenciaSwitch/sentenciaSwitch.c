/* Sentencia switch (expression)
* */

#include <stdio.h>

int main(){
	puts("Selecciona dia de la semana\n");
	puts("1. Lunes\n");
	puts("2. Martes\n");
	puts("3. Miercoles\n");
	puts("4. Jueves\n");
	puts("5. Viernes\n");
	puts("6. Sabado\n");
	puts("7. Domingo\n");
	int numDay = 0;
	scanf("%i", &numDay);
	switch(numDay){
		case 1: printf("Seleccionaste el Lunes.");
			break;
		case 2: printf("Seleccionaste el Martes.");
			break;
		case 3: printf("Seleccionaste el Miercoles.");
			break;
		case 4: printf("Seleccionaste el Jueves.");
			break;
		case 5: printf("Seleccionaste el Viernes.");
			break;
		case 6: printf("Seleccionaste el Sabado.");
			break;
		case 7: printf("Seleccionaste el Domingo.");
			break;
		default: printf("Selecciona una opcion valida.");
			break;
	}
	return 0;
}
