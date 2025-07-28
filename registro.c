#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "registro.h"
#include "limpiar.h"
#include <ctype.h>

#define MAX 100

struct Vehiculo lista[MAX];
int total = 0;  // Contador global de vehiculos registrados

// Convierte una cadena a mayusculas
void convertirMayusculas(char *cadena) {
	for (int i = 0; cadena[i] != '\0'; i++) {
		cadena[i] = toupper((unsigned char)cadena[i]);
	}
}

// Verifica que una cadena de 10 caracteres contenga solo numeros
int esNumerica(const char *str) {
	for (int i = 0; i < 10; i++) {
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

// Solicita al usuario una cedula valida
void pedirCedula(char cedula[]) {
	int valido = 0;
	while (!valido) {
		printf("Ingrese cedula (10 digitos): ");
		scanf("%s", cedula);
		limpiar_buffer();
		if (strlen(cedula) != 10 || !esNumerica(cedula)) {
			limpiar_pantalla();
			printf("Error: la cedula debe tener exactamente 10 digitos numericos.\n");
		} else {
			valido = 1;
		}
	}
}

// Valida que la placa cumpla con el formato correcto
int validarPlaca(const char placa[]) {
	if (strlen(placa) != 8) return 0;
	for (int i = 0; i < 3; i++) {
		if (!(placa[i] >= 'A' && placa[i] <= 'Z')) return 0;
	}
	if (placa[3] != '-') return 0;
	for (int i = 4; i < 8; i++) {
		if (!(placa[i] >= '0' && placa[i] <= '9')) return 0;
	}
	return 1;
}

// Verifica si una placa ya fue registrada previamente
int yaRegistrado(const char placa[]) {
	for (int i = 0; i < total; i++) {
		if (strcmp(lista[i].placa, placa) == 0) {
			return 1;
		}
	}
	return 0;
}

// Muestra la fecha actual
void mostrarFecha() {
	time_t tiempo_actual;
	struct tm *info_tiempo;
	char fecha[80];
	
	tiempo_actual = time(NULL);
	info_tiempo = localtime(&tiempo_actual);
	strftime(fecha, sizeof(fecha), "%Y-%m-%d", info_tiempo);
	
	printf("Fecha Actual: %s\n", fecha);
}

// Muestra un resumen del vehiculo registrado
void mostrarResumen(struct Vehiculo v) {
	printf("Vehiculo registrado.\n");
}

// Proceso de registro de un vehiculo
void registrarVehiculo() {

	limpiar_pantalla();
	struct Vehiculo v;
	
	// Obtener fecha y hora actual
	time_t ahora = time(NULL);
	struct tm *k = localtime(&ahora);
	strftime( v.fechaHora, sizeof(v.fechaHora), "%Y-%m-%d %H:%M", k);
	
	
	printf("\n--- Registrar Vehiculo ---\n");
	mostrarFecha();
	
	//Llamado del la funcion para la validacion y registro de la cedula
	pedirCedula(v.cedula);
	limpiar_pantalla();
	
	
	
	//Funcion y validacion para el registro del anio del vehiculo
	int anioValido = 0;
	while (!anioValido) {
		printf("Ingrese el anio del vehiculo (1990 - 2025): ");
		if (scanf("%d", &v.anio) == 1 && v.anio >= 1990 && v.anio <= 2025) {
			anioValido = 1;
		} else {
			limpiar_pantalla();
			printf("Anio invalido. Debe estar entre 1990 y 2025.\n");
		}
		limpiar_buffer();
	}
	limpiar_pantalla();
	
	
	
	
	//Funcion y validacion para el registro del formato correcto de la placa
	int placaValida = 0;
	while (!placaValida) {
		printf("Ingrese la placa (formato ABC-1234): ");
		scanf("%s", v.placa);
		convertirMayusculas(v.placa);
		
		if (!validarPlaca(v.placa)) {
			limpiar_pantalla();
			printf("Error: formato de placa invalido.\n");
		} else if (yaRegistrado(v.placa)) {
			limpiar_pantalla();
			printf("Error: esta placa ya esta registrada.\n");
		} else {
			placaValida = 1;
		}
		limpiar_buffer();
	}
	limpiar_pantalla();
	
	
	
	
	//Validacion para que los vehiculos cumplan con las tres reviiones tecnicas
	int revisionesValidas = 0;
	while (!revisionesValidas) {
		printf("Numero de revisiones tecnicas: ");
		if (scanf("%d", &v.revisiones) == 1) {
			if (v.revisiones == 3) {
				revisionesValidas = 1;
			} else if (v.revisiones > 3 || v.revisiones < 0) {
				limpiar_pantalla();
				printf("Error. Intente nuevamente.\n");
			} else {
				limpiar_pantalla();
				printf("No puede matricular el vehiculo. Necesita pasar las tres revisiones tecnicas.\n");
				return;
			}
		} else {
			limpiar_pantalla();
			printf("Ingrese un valor numerico valido.\n");
		}
		limpiar_buffer();
	}
	limpiar_pantalla();
	
	
	
	//Funcion y validacion para el avaluo del vehiculo
	int avaluoValido = 0;
	while (!avaluoValido) {
		printf("Avaluo del vehiculo: $ ");
		if (scanf("%f", &v.avaluo) == 1 && v.avaluo > 0 && v.avaluo <= 500000) {
			avaluoValido = 1;
		} else {
			limpiar_pantalla();
			printf("Valor invalido. Ingrese un avaluo entre 0 y 500000.\n");
		}
		limpiar_buffer();
	}
	
	if (v.anio <= 2018) {
		v.avaluo *= 0.8;
	}
	limpiar_pantalla();
	
	
	
	//Funcion para solicitar el tipo de vehiculo que es y calcular el valor a pagar por la matricula
	int tipoValido = 0;
	int t;
	while (!tipoValido) {
		printf("Tipo:\n");
		printf("1. Vehiculo particular\n");
		printf("2. Motocicletas\n");
		printf("3. Transporte publico-comercial\n");
		printf("Seleccione (1-3): ");
		if (scanf("%d", &t) == 1 && (t >= 1 && t <= 3)) {
			tipoValido = 1;
		} else {
			limpiar_pantalla();
			printf("Opcion invalida. Intente nuevamente.\n");
		}
		limpiar_buffer();
	}
	limpiar_pantalla();
	
	switch (t) {
	case 1:
		strcpy(v.tipo, "Vehiculo particular");
		v.costo = 18 + (v.avaluo * 0.015);
		break;
	case 2:
		strcpy(v.tipo, "Motocicletas");
		v.costo = 9.30 + (v.avaluo * 0.018);
		break;
	case 3:
		strcpy(v.tipo, "Transporte publico-comercial");
		v.costo = 20.50 + (v.avaluo * 0.012);
		break;
	}
	limpiar_pantalla();
	
	
	
	//Funcion para determinar y agregar al valor a pagar en caso de tener multas
	char respuesta[4];
	int multaValida = 0;
	
	while (!multaValida) {
		printf("Tiene multas? (s o n): ");
		scanf("%3s", respuesta);
		limpiar_buffer();
		
		if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 || 
			strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 || 
			strcmp(respuesta, "Si") == 0) {
			v.multas = 1;
			multaValida = 1;
		} else if (strcmp(respuesta, "n") == 0 || strcmp(respuesta, "N") == 0 || 
				   strcmp(respuesta, "no") == 0 || strcmp(respuesta, "NO") == 0 || 
				   strcmp(respuesta, "No") == 0) {
			v.multas = 0;
			multaValida = 1;
		} else {
			limpiar_pantalla();
			printf("Entrada invalida.\n");
		}
	}
	limpiar_pantalla();
	
	if (v.multas) {
		v.costo += 500;
	}
	
	if (total < MAX) {
		lista[total] = v;
		total++;
	}
	
	limpiar_pantalla();
	mostrarResumen(v);
	mostrarComprobante(lista[total - 1]);
	generarComprobante(lista[total - 1]);
}

// Muestra el comprobante en pantalla
// Muestra el comprobante en pantalla
void mostrarComprobante(struct Vehiculo v) {
	printf("=========== COMPROBANTE DE MATRICULA ===========\n");
	printf("Fecha de registro: %s\n", v.fechaHora);	
	printf("Placa: %s\n", v.placa);
	printf("Tipo: %s\n", v.tipo);
	printf("Anio: %d\n", v.anio);
	printf("Avaluo: $%.2f\n", v.avaluo);
	printf("Valor a pagar: $%.2f\n", v.costo);
	printf("===============================================\n");
}

// Genera el comprobante en un archivo
void generarComprobante(struct Vehiculo v) {
	char respuesta;
	printf("Desea generar el comprobante en archivo? (s/n): ");
	scanf(" %c", &respuesta);
	limpiar_buffer();
	
	if (respuesta != 's' && respuesta != 'S') {
		limpiar_pantalla();
		printf("No se genero el comprobante.\n");
		return;
	}
	
	FILE *archivo = fopen("comprobante.txt", "w");
	if (archivo == NULL) {
		printf("No se pudo crear el comprobante.\n");
		return;
	}
	
	fprintf(archivo, "----- COMPROBANTE DE MATRICULA -----\n");
	fprintf(archivo, "Fecha de registro: %s\n", v.fechaHora);	
	fprintf(archivo, "Placa: %s\n", v.placa);
	fprintf(archivo, "Tipo: %s\n", v.tipo);
	fprintf(archivo, "Anio: %d\n", v.anio);
	fprintf(archivo, "Avaluo: $%.2f\n", v.avaluo);
	fprintf(archivo, "Valor a pagar: $%.2f\n", v.costo);
	fprintf(archivo, "-----------------------------------\n");
	
	fclose(archivo);
	limpiar_pantalla();
	printf("Comprobante generado correctamente.\n");
}

// Busca un vehiculo por placa
void buscarVehiculoPorPlaca() {
	char placa[10];
	int encontrado = 0;
	
	printf("\n--- Buscar Vehiculo por Placa ---\n");
	printf("Ingrese la placa (formato ABC-1234): ");
	scanf("%9s", placa);
	limpiar_buffer();
	convertirMayusculas(placa);
	
	for (int i = 0; i < total; i++) {
		if (strcmp(lista[i].placa, placa) == 0) {
			printf("\nVehiculo encontrado:\n");
			mostrarComprobante(lista[i]);
			generarComprobante(lista[i]);
			encontrado = 1;
			break;
		}
	}
	
	if (!encontrado) {
		printf("Vehiculo con placa %s no encontrado.\n", placa);
	}
}

// Guarda los vehiculos en un archivo
void guardarVehiculos() {
	FILE *archivo = fopen("vehiculos.txt", "w");
	if (archivo == NULL) {
		printf("Error al guardar en archivo.\n");
		return;
	}
	
	for (int i = 0; i < total; i++) {
		fprintf(archivo, "%s,%s,%s,%d,%d,%.2f,%.2f,%d,%s\n",
				lista[i].cedula,
				lista[i].placa,
				lista[i].tipo,
				lista[i].anio,
				lista[i].revisiones,
				lista[i].avaluo,
				lista[i].costo,
				lista[i].multas,
				lista[i].fechaHora);
		
	}
	
	fclose(archivo);
}

// Carga los vehiculos desde el archivo
void cargarVehiculos() {
	FILE *archivo = fopen("vehiculos.txt", "r");
	if (archivo == NULL) {
		total = 0;
		return;
	}
	
	total = 0;
	while (fscanf(archivo, "%10[^,],%9[^,],%29[^,],%d,%d,%f,%f,%d,%19[^\n]\n",
				  lista[total].cedula,
				  lista[total].placa,
				  lista[total].tipo,
				  &lista[total].anio,
				  &lista[total].revisiones,
				  &lista[total].avaluo,
				  &lista[total].costo,
				  &lista[total].multas,
				  lista[total].fechaHora) == 9) {
		
		total++;
		if (total >= MAX) break;
	}
	
	fclose(archivo);
}

