/* =====================================================================
 * MANEJO DE ARCHIVOS EN C (Moderno, Seguro y Didáctico)
 *
 * Resumen de Modos de Apertura en fopen():
 * --------------------------------------------------------------------- 
 * "r"	: Lectura. El archivo debe de existir. Posición: Inicio.
 * "w"	: Escritura. Si existe, se TRUNCA (borra contenido); si no, se crea.
 * "a"	: Anexar (Append). Escribe al FINAL. Si no existe, se crea.
 * "r+"	: Lectura y Escritura. El archivo DEBE de existir. Posicion, al INICIO.
 * "w+"	: Lectura y Escritura. TRUNCA si existe o CREA uno nuevo.
 * "a+"	: Lectura y Anexado. Lectura desde cualquier lugar, escrituras SIEMPRE al final.
 * "rb", "wb", "ab", "rb+", "wb+", "ab+" : Versiones para datos BINARIOS.
 * ==================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructura para la demostración de archivos binarios. */

typedef struct {
	int id;
	char nombre[30];
	float promedio;
}Estudiante;

/* Declaración de funciones auxiliares */
void demo_escritura_w(void);
void demo_lectura_r(void);
void demo_anexado_a(void);
void demo_lectura_escritura_r_plus(void);
void demo_creacion_lectura_w_plus(void);
void demo_archivos_binarios(void);

int main(void) {
	printf("====================================================\n");
	printf("     DEMOSTRACIÓN COMPLETA DE ARCHIVOS EN C\n");
	printf("====================================================\n\n");

	demo_escritura_w();
	demo_lectura_r();
	demo_anexado_a();
	demo_lectura_escritura_r_plus();
	demo_creacion_lectura_w_plus();
	demo_archivos_binarios();

	printf("\n====================================================\n");
	printf(" ¡Todas las pruebas finalizaron con éxito!\n");
	printf("====================================================\n");

	return 0;
}


/* -------------------------------------------------------------------
 * 1. MODO "w" - Crear y escribir en un archivo de texto
 * ------------------------------------------------------------------- */

void demo_escritura_w(void){
	printf("[1] MODO 'w' (Escritura / Sobreescritura)\n");
	printf("-----------------------------------------\n");
	
	FILE *archivo = fopen("ejemplo_w.txt", "w");
	if(archivo == NULL){
		perror("Error al abrir ejemplo_w.txt");
		return;
	}

	/* fputs y fprintf son las formas estandar de escribir texto */
	fputs("Linea 1: Lenguaje C Moderno. \n", archivo);
	fprintf(archivo, "Linea 2: ID de prueba = %d, Valor = %.2f\n", 101, 98.5);
	fputs("Linea 3: Fin del contenido inicial.. \n", archivo);

	fclose(archivo);
	printf("-> Se creo 'ejemplo_w.txt' y se escribieron 3 lineas.\n\n");
}


/* -------------------------------------------------------------------------
 * 2. MODO "r" - Leer un archivo línea por línea de forma segura
 * ------------------------------------------------------------------------- */

void demo_lectura_r(void){
	printf("[2] MODO 'r' (Lectura)\n");
	printf("----------------------\n");
	
	FILE *archivo = fopen("ejemplo_w.txt", "r");
	if(archivo == NULL){
		perror("Error al abrir ejemplo_w.txt para lectura");
		return;
	}
	
	char buffer[256];
	int numero_linea = 1;
	printf("Contenido leido desde 'ejemplo_w.txt':\n");
	/* fgets lee linea por linea evitando el desbordamiento del buffer */
	while(fgets(buffer, sizeof(buffer), archivo) != NULL){
		printf(" [%d] %s", numero_linea++, buffer);
	}
	
	fclose(archivo);
	printf("\n-> Archivo leido correctamente hasta EOF (End Of File). \n\n");
	printf("-> Se creo 'ejemplo_w.txt' y se escribieron 3 lineas.\n\n");
}

/* -------------------------------------------------------------------------
 * 3. MODO "a" - Anexar datos al final del archivo sin borrar lo existente
 * ------------------------------------------------------------------------- */

void demo_anexado_a(void){
	printf("[3] MODO 'a' (Anexar / Append)\n");
	printf("------------------------------\n");
	
	FILE *archivo = fopen("ejemplo_w.txt", "a");
	if(archivo == NULL){
		perror("Error al abrir ejemplo_w.txt para anexar");
		return;
	}

	fprintf(archivo, "Linea 4: Esta linea fue agregada con el modo 'a'. \n");
	fclose(archivo);
	
	printf("-> Se agrego una nueva linea al final de 'ejemplo_w.txt'. \n");
	
	/* Verificamos leyendo el contenido actualizado */
	archivo = fopen("ejemplo_w.txt", "r");
	if(archivo != NULL){
		char buffer[256];
		printf("Contenido actualizado:\n");
		while(fgets(buffer, sizeof(buffer), archivo) != NULL){
			printf(" %s", buffer);
		}
		fclose(archivo);
	}
	printf("\n");
}

/* -------------------------------------------------------------------------
 * 4. MODO "r+" - Lectura y Modificación in-situ (Rewind y Seek)
 * ------------------------------------------------------------------------- */
void demo_lectura_escritura_r_plus(void) {
	printf("[4] MODO 'r+' (Lectura y Escritura - Requiere archivo existente)\n");
	printf("----------------------------------------------------------------\n");
	
	FILE *archivo = fopen("ejemplo_w.txt", "r+");
	if(archivo == NULL){
		perror("Error al abrir 'ejemplo_w.txt' con 'r+'");
		return;
	}

	/* Sobreescribimos el INICIO del archivo */
	fputs("XXXXXX", archivo);
	
	/* Reposicionamos el puntero al inicio para leer la modificacion */
	rewind(archivo);
	
	char buffer[256];
	printf("Contenido tras sobreescribir los primeros 6 caracteres:\n");
	while(fgets(buffer, sizeof(buffer), archivo) != NULL){
		printf(" %s", buffer);
	}

	fclose(archivo);
	printf("\n");
}

/* -------------------------------------------------------------------------
 * 5. MODO "w+" - Crear archivo temporal / nuevo para escribir y luego leer
 * ------------------------------------------------------------------------- */

void demo_creacion_lectura_w_plus(void){
	printf("[5] MODO 'w+' (Escritura y Lectura - TRUNCADO / CREAR)\n");
	printf("------------------------------------------------------\n");
	
	FILE *archivo = fopen("ejemplo_w.txt","w+");
	if(archivo == NULL){
		perror("Error al crear ejemplo_wplus.txt");
		return;
	}
	
	fputs("Dato A: Servidor en ejecucion\n", archivo);
	fputs("Dato B: Puerto 8080 activo\n", archivo);
	
	/* IMPORTANTE: Para leer lo escrito, se debe volver al inicio con fseek o rewind */
	fseek(archivo, 0, SEEK_SET);
	
	char buffer[256];
	printf("Leyendo directamente del archivo recien creado en modo 'w+': \n");
	while(fgets(buffer, sizeof(buffer), archivo) != NULL){
		printf(" %s", buffer);
	}
	
	fclose(archivo);
	printf("\n");
}

/* -------------------------------------------------------------------------
 * 6. MODO BINARIO ("wb" y "rb") - Manipulacion de estructuras directas
 * ------------------------------------------------------------------------- */

void demo_archivos_binarios(void){
	printf("[6] MODOS BINARIOS ('wb' / 'rb') - Escritura y Lectura de Structs\n");
	printf("-----------------------------------------------------------------\n");
	
	Estudiante lista_escritura[2] = {
		{1, "Alex", 9.5f},
		{2, "Leslie", 9.8f}
	};
	
	/* 1. Escribir struct binario */
	FILE *archivo = fopen("estudiantes.bin", "wb");
	if(archivo == NULL){
		perror("Error al abrir estudiantes.bin para escritura");
		return;
	}
	
	size_t escritos = fwrite(lista_escritura, sizeof(Estudiante), 2, archivo);
	fclose(archivo);
	printf("-> Se escribieron %zu registros binarios en 'estudiantes.bin'.\n", escritos);

	/* 2. Leer struct binario */
	archivo = fopen("estudiantes.bin", "rb");
	if(archivo == NULL){
		perror("Error al abrir estudiantes.bin para lectura");
		return;
	}

	Estudiante leido;
	printf("Registros leidos desde el archivo bianrio:\n");
	while(fread(&leido, sizeof(Estudiante), 1, archivo) == 1){
		printf(" [ID: %d] Nombre: %-8s | Promedio: %.2f\n", leido.id, leido.nombre, leido.promedio);
	}

	fclose(archivo);
	printf("\n");
}


