/* =================================================================
 * SISTEMA DE FORMULARIO DE REGISTRO EN FORMATO CSV (C11 / C17 / C23) 
 * ================================================================= 
 * DESCRIPCIÓN
 * Formulario dinamico que captura datos desde consola y los 
 * persiste en un archivo de text con formato CSV 
 * ----------------------------------------------------------------
 * HERRAMIENTAS Y FUNCIONES
 * - fopen(..., "a+"): Abre en modo anexo para conservar datos previos y permite verificar si está vacio
 * - fseek() / fteel(): Para verificar el tamano del archivo y decidir si escribir el encabezado CSV
 * - fgets() / strcspn(): Lectura segura de cadenas evitando desbordamiento de buffer y removiendo '\n'
 * - fprintf(): Escritura estructurada con comas como delimitadores.
 * - fflush(stdin) / getchar(): Limpieza manual de buffer de entrad antes de lecturas de text
 * ----------------------------------------------------------------
 * PSEUDOCODIGO / ESTRUCTRURA DEL PROGRAMA:
 * 1. Definir estructura de usuario (id, nombre, edad, correo)
 * 2. Abrir archivo "usuarios.csv" en modo "a+"
 * 3. Si el archivo esta vacio (ftell == o):
 * 	Escribir encabezado: "ID,NOMBRE,EDAD,CORREO"
 * 4. Bucle principal (Menu interactivo):
 * 	Opcion 1: Capturar formulario e insertar nuevo registro al CSV
 *        Opción 2: Mostrar todos los registros guardados en el CSV leyendo línea por línea.
 *        Opción 3: Salir.
 * 5. Cerrar archivo y finalizar.
 * ================================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO_CSV "usuarios.csv"
#define MAX_BUFFER 256

/* Estructura para el usuario */
typedef struct {
	int id;
	char nombre[50];
	int edad;
	char correo[50];
} Usuario;

/* Declaracion de funciones */
void limpiar_salto_de_linea(char *cadena);
void limpiar_buffer_stdin(void);
void inicializar_csv(void);
void agregar_usuarios_csv(void);
void listar_usuarios_csv(void);

int main(void){
	int opcion = 0;

	/* Revisar que archivo exista y tenga encabezados */
	inicializar_csv();
	
	do{
		printf("===========================================\n");
		printf("     FORMULARIO DE REGISTRO (CSV)          \n");
		printf("===========================================\n");
		printf("1. Registrar nuevo usuario\n");
		printf("2. Ver todos los registros del CSV\n");
		printf("3. Salir\n");
		printf("Seleccione una opcion (1-3): ");
		
		if(scanf("%d", &opcion) != 1){
			printf("\n[!] Ingresa un numero\n\n");
			limpiar_buffer_stdin();
			continue;
		}
	
		limpiar_buffer_stdin(); // Retira el \n sobrante
		
		switch(opcion){
			case 1:
				agregar_usuarios_csv();
				break;
			case 2:
				listar_usuarios_csv();
				break;
			case 3:
				printf("\nSaliendo... Los datos estan guardados en %s\n",ARCHIVO_CSV);
				break;
			default:
				printf("\n[!] Opcion no valida \n\n");
		}
	}while(opcion != 3);
	return 0;
}


/* Remueve el caracter '\n' que coloca fgets al presionar Enter */
void limpiar_salto_linea(char *cadena){
	cadena[strcspn(cadena, "\r\n")] = '\0';
}

/* Limpia el buffer de entrada estandar (stdin) */
void limpiar_buffer_stdin(void){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

/* Comprueba si el archivo existe o esta vacio para escribir el encabezado */
void inicializar_csv(void){
	FILE *fp = fopen(ARCHIVO_CSV, "a+");
	if(fp == NULL){
		perror("Error al inicializar el archivo CSV");
		exit(EXIT_FAILURE);
	}
	
	/* Mueve al final del archivo para ver su tamano */
	fseek(fp, 0, SEEK_END);
	long tamano = ftell(fp);
	
	/* Si el archivo esta vacio (tamano 0), escribimos el encabeza CSV */
	if(tamano == 0){
		fputs("ID,NOMBRE,EDAD,CORREO\n", fp);
		fflush(fp);
	}
	fclose(fp);
}

/* Captura datos por consola y los escribe en formato CSV */
void agregar_usuarios_csv(void){
	Usuario usr;
	
	printf("\n-- CAPTURA DE DATOS --");
	
	printf("Ingresa ID numerico:\n");
	while(scanf("%d", &usr.id) != 1){
		printf("[!] Ingresa ID valido (int):\n");
		limpiar_buffer_stdin();
	}
	limpiar_buffer_stdin();
	
	printf("Ingrese Nombre Completo: ");
	if(fgets(usr.nombre,sizeof(usr.nombre),stdin) != NULL){
		limpiar_salto_linea(usr.nombre);
	}

	printf("Ingresa Edad:\n");
	while(scanf("%d", &usr.edad) != 1){
		printf("[!] Ingresa EDAD valida (int):\n");
		limpiar_buffer_stdin();
	}
	limpiar_buffer_stdin();
	
	printf("Ingrese correo electronico: ");
	if(fgets(usr.correo,sizeof(usr.correo),stdin) != NULL){
		limpiar_salto_linea(usr.correo);
	}

	/* Abre archivo en modo 'a' para anexar al final */
	FILE *fp = fopen(ARCHIVO_CSV, "a");
	if(fp == NULL){
		perror("Error al abrir el archivo para guardar");
		return;
	}
	
	/* Se guardan los campos separados por comas */
	fprintf(fp, "%d,%s,%d,%s\n", usr.id, usr.nombre, usr.edad, usr.correo);
	fclose(fp);
	printf("-> ¡Registro guardado exitosamente en '%s'!\n\n", ARCHIVO_CSV);	
}

/* Lee el archivo CSV linea por linea y se presenta formateado */
void listar_usuarios_csv(void){
	FILE *fp = fopen(ARCHIVO_CSV, "r");
	if(fp == NULL){
		perror("Error al abrir archivo CSV para su lectura\n");
		return;
	}

	char buffer[MAX_BUFFER];
	int numero_linea = 0;
	
	printf("============================================");
	printf("      CONTENIDO DEL ARCHIVO  %s      \n", ARCHIVO_CSV);
	printf("============================================");

	while(fgets(buffer, sizeof(buffer), fp) != NULL){
		limpiar_salto_linea(buffer);
		numero_linea++;

		if(numero_linea == 1){
			// Linea de encabezado 
			printf(" [ENCABEZADO] -> %s\n", buffer);
			printf("-----------------------------------------");
		}else{
			// Formatear visualmente los valores separados por coman
			int id, edad;
			char nombre[50], correo[50];
	
			if(sscanf(buffer, "%d,%49[^,],%d,%49s", &id,nombre,&edad,correo) == 4){
				printf("  Fila %-2d | ID: %-4d | Nombre: %-15s | Edad: %-2d | Correo: %s\n", numero_linea - 1, id, nombre, edad, correo);
			}else{
				printf("  Fila %-2d (bruta) -> %s\n", numero_linea - 1, buffer);
			}
		}
	}
	fclose(fp);
	printf("===================================================\n\n");
}




