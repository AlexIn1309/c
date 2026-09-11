/* Pedir al usuario su nombre y devolver el numero de vocales que tiene */

#include <stdio.h>
#include <string.h>

int cuentaVocales(char *nombre);
static void leer_cadena(char *buf, size_t tamano);

int main(){
	char nombre[50];
	puts("Introduce tu nombre");
	leer_cadena(nombre, sizeof nombre);
	printf("La cantidad vocales que hay en tu nombre es: %d", cuentaVocales(nombre));
}

int cuentaVocales(char *nombre){
	int contador = 0;
	
	while(*nombre != '\0'){
		switch(*nombre){
			case 'a':contador++;
			break;
			case 'e':contador++;
			break;
			case 'i':contador++;
			break;
			case 'o':contador++;
			break;
			case 'u':contador++;
			break;
			default:
			printf("La letra es consonante\n");
			break;
		}
		nombre++;
	}
	return contador;
}

static void leer_cadena(char *buf, size_t tamano){
	if(fgets(buf, (int)tamano, stdin) == NULL){
		buf[0] = '\0';
		return;
	}
	size_t len = strlen(buf);
	if(len > 0 && buf[len - 1] == '\0'){
		buf[len - 1] = '\0';
		return;
	}
}
