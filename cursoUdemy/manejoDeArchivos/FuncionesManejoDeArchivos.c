/* ===================================================================================================================
 * FUNCIONES DE MANEJO DE ARCHIVOS EN C (Moderno, Seguro y Didáctico)
 * -------------------------------------------------------------------------------------------------------------------
 * Análisis de la Tabla de Funciones
 * -------------------------------------------------------------------------------------------------------------------
 *  FUNCIÓN     |    ESTADO     | DIAGNÓSTICO / USO MODERNO RECOMENDADO
 * -------------------------------------------------------------------------------------------------------------------
 *  fopen()     | Vigente       | Usar siempre comprobando si devuelve NULL. 
 * 		|		| En C11 se introdujo fopen_s() como
 *              |               | alternativa segura opcional, pero fopen() 
 *		|		| sigue siendo el estándar universal.
 * -------------------------------------------------------------------------------------------------------------------
 *  fclose()    | Vigente       | Obligatorio para liberar descriptores de 
 *		|		| archivo y asegurar el volcado del buffer
 *              |               | en disco.
 * -------------------------------------------------------------------------------------------------------------------
 *  fgets()     | Vigente       | La mejor opción para leer texto. Reemplazó
 *		|		| por completo a gets(). Debe verificarse que
 *              |               | el retorno no sea NULL.
 * -------------------------------------------------------------------------------------------------------------------
 *  fputs()     | Vigente       | Eficiente y segura para escribir cadenas 
 *		|		| sencillas sin formato.
 * -------------------------------------------------------------------------------------------------------------------
 *  fseek()     | Con reservas  | Útil en archivos pequeños/medianos. 
 *		|		| Para archivos grandes (>2GB) en 64-bits
 *              |               | se prefiere fgetpos()/fsetpos() o fseeko()
 *		|		| para evitar desbordamiento.
 * -------------------------------------------------------------------------------------------------------------------
 *  fprintf()   | Vigente       | Estándar universal para salida con formato
 *		|		| en flujos de archivo.
 * -------------------------------------------------------------------------------------------------------------------
 *  fscanf()    | Precaución    | Insegura con cadenas (%s) si no se acota el ancho (ej. %29s).
 *              |               | Es más seguro combinar fgets() con sscanf().
 * -------------------------------------------------------------------------------------------------------------------
 *  feof()      | Uso incorrecto| NO usar como condición de control en bucles (while(!feof)).
 *              |               | Solo se evalúa DESPUÉS de que una lectura falla para comprobar EOF.
 * -------------------------------------------------------------------------------------------------------------------
 *  ferror()    | Vigente       | Esencial para detectar si ocurrieron errores de lectura/escritura en el flujo.
 * -------------------------------------------------------------------------------------------------------------------
 *  rewind()    | Con reservas  | Equivale a fseek(fp, 0, SEEK_SET), pero no retorna errores ni limpia banderas.
 *              |               | Se prefiere el uso directo de fseek().
 * -------------------------------------------------------------------------------------------------------------------
 *  remove()    | Vigente       | Elimina un archivo del sistema de archivos.
 * -------------------------------------------------------------------------------------------------------------------
 *  fflush()    | Uso delimitado| VÁLIDO ÚNICAMENTE para flujos de SALIDA (stdout, archivos en escritura).
 *              |               | Usarlo en flujos de entrada (stdin) produce comportamiento indefinido.
 * =================================================================================================================== */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demo_escritura_segura(void);
void demo_lectura_y_posicionamiento(void);
void demo_procesamiento_fscanf_vs_fgets(void);

int main(void) {
	printf("====================================================\n");
	printf("   DEMOSTRACIÓN DE FUNCIONES ESTÁNDAR DE ARCHIVOS\n");
	printf("====================================================\n\n");

	demo_escritura_segura();
	demo_lectura_y_posicionamiento();
	demo_procesamiento_fscanf_vs_fgets();

	/* remove(): Borra los archivos de prueba al finalizar */
	if (remove("config.txt") == 0 && remove("datos.txt") == 0) {
		printf("[remove] Archivos de prueba eliminados correctamente.\n");
	}

	return 0;
}

/* 1. fopen, fprintf, fputs y fflush */
void demo_escritura_segura(void){
	printf("[1] DEMO: fopen, fprintf, fputs, fflush\n");
	printf("---------------------------------------\n");
	
	FILE *fp = fopen("config.txt", "w");
	if(fp == NULL){
		perror("Error al abrir config.txt");
		return;
	}
	
	fputs("# Archivo de configuracion\n", fp);
	
	/* fprintf para formato */
	fprintf(fp, "puerto=%d\n", 8080);
	fprintf(fp, "timeout=%.1f\n", 30.5);

	/* fflush fuerza el volcado del bufer al disco sin cerrar el archivo */
	fflush(fp);
	printf("-> Datos volcados al disco con fflush().\n");
	fclose(fp);
	printf("-> Archivo cerrado con fclose().\n\n");
}

/* 2. Uso de fgets, fseek, rewind, feof y ferror */
void demo_lectura_y_posicionamiento(void){
	printf("[2] DEMO: fgets, fseek, rewind, feof, feero\n");
	printf("-------------------------------------------\n");

	FILE *fp = fopen("config.txt", "r");
	if(fp == NULL){
		perror("Error al abrir config.txt");
		return;
	}
	
	/* fseek: Mover el puntero al final para calcular el tamaño  */
	if(fseek(fp, 0, SEEK_END) == 0){
		long tamano = ftell(fp);
		printf("-> Tamanio de archivo (fseek/ftell): %ld bytes\n", tamano);
	}

	/* rewind: Volver al inicio equivale a fseek(fp, 0, SEEK_SET) */
	rewind(fp);
	
	char buffer[128];
	printf("Contenido del archivo (usando fgets en bucle):\n");
	
	/* FORMA CORRECTA: Controlar el bucle con la funcion de lectura, NO feof() */
	while(fgets(buffer, sizeof(buffer), fp) != NULL){
		printf(" %s",buffer);
	}
	
	/* feof y ferror se evaluan DESPUES de que termina la lectura para saber que paso */
	if(ferror(fp)){
		printf("\n[ERROR] Se produjo un error durante la lectura.\n");
	}else if(feof(fp)){
		printf("\n-> Se alcanza el final del archivo (EOF) Correctamente. \n");
	}

	fclose(fp);
	printf("\n");
	
}

/* 3. Forma segura de procesar datos con formato (evitando riesgos de fscanf) */
void demo_procesamiento_fscanf_vs_fgets(void){
	printf("[3] DEMO: Formato seguro (fscanf acotado vs sscanf)\n");
	printf("---------------------------------------------------\n");
	
	/* Preparamos un archivo de datos */
	FILE *fp_out = fopen("datos.txt", "w");
	if(fp_out != NULL){
		fprintf(fp_out, "Usuario 25 105.5\n");
		fprintf(fp_out, "Usuario 30 200.0\n");
		fclose(fp_out);
	}

	FILE *fp_in = fopen("datos.txt", "r");
	if(fp_in == NULL)return;
	
	char nombre[30];
	int edad;
	float saldo;
	
	printf("a) Leyendo con fscanf de forma segura (con limite de ancho %%29s):\n");
	/* Siempre especificar ancho maximo de %s para evitar buffer overflow */
	while(fscanf(fp_in, "%29s %d %f", nombre, &edad, &saldo) == 3){
		printf(" Nombre: %-10s | Edad: %d | Saldo: %.2f\n", nombre, edad, saldo);
	}
	
	/* B. Alternativa MAS robusta: fgets + sscanf */
	rewind(fp_in);
	char linea[128];
	
	printf("\nb) Alternativa Moderna recomendada (fgets + sscanf):\n");
	while(fgets(linea, sizeof(linea), fp_in) != NULL){
		if(sscanf(linea, "%29s %d %f", nombre, &edad, &saldo) == 3){
			printf(" Parsed: %-10s | %d anios | $%.2f\n", nombre, edad, saldo);
		}
	}

	fclose(fp_in);
	printf("\n");
}




