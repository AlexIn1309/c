/* PIRAMIDE DE ASTERISCOS
 *	*
 *	**
 *	***
 *	****
 *	*****
 *  */

#include <stdio.h>

int main(){
	int tamano = 0;
	puts("Cantidad de filas para la piramide");
	scanf("%i", &tamano);
	int contador = tamano;
	for(int i = 0; i < tamano; i++){
		for(int j = 0; j >= tamano; j++){
			if(j<= contador){
				printf("*");
			}else{
				printf("a");
			
			}
			contador--;
		}
		printf("\n");
		
	}
	return 0;
}
