/* STRCMP
 * strcmp(cadena1,cadena2) 
 * Compara 2 cadenas de texto caracter a caracter, es case-sensitive (Sensible a mayusculas y minusculas).
 * Cuando se encuentra una diferencia, esta funcion devuelve un valor entero, correspondiente a la 
 * diferencia de valor decimal segun el codigo ASCII, como en la siguiente tabla*/

/* Si cadena es 	| Devuelve
 * Igual que cadena 	| 0
 * Mayor que cadena 	| n > 0 
 * Menor que cadena 	| n < 0 */

#include <stdio.h>
#include <string.h>

int main(){
	char clave[] = "contrasena";
	char usuario[128];
	int intentos = 3;

	do{
		printf("\n\nEscribe la contrasena\n");
		fflush(stdin);
		scanf("%s", usuario);

		// Validacion de contrasena
		if(strcmp(clave, usuario) == 0){
			printf("\nBienvenido al sistema");
			break;
		}else{
			intentos--;
			printf("\nClave Incorrecta, te quedan %i intentos", intentos);
		}
	}while(intentos > 0);

	return 0;
}
