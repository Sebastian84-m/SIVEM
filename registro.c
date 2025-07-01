#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "registro.h"

#define MAX 100

struct Vehiculo lista[MAX];
int total = 0; // Un solo contador para vehículos registrados

void limpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void limpiarBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// Verifica que una cadena de 10 caracteres contenga solo números
int esNumerica(const char* str) {
	for (int i = 0; i < 10; i++) {
		if (str[i] < '0' || str[i] > '9') return 0; // No es un dígito
	}
	return 1;
}


// Solicita al usuario una cédula válida si la ingresa mal anteriormente
void pedirCedula(char cedula[]) {
	int valido = 0;
	while (!valido) {
		printf("Ingrese cedula (10 digitos): ");
		scanf("%10s", cedula); // Limitar a 10 caracteres
		limpiarBuffer();
		if (strlen(cedula) != 10 || !esNumerica(cedula)) {
			limpiarPantalla();
			printf("Error: la cedula debe tener exactamente 10 digitos numericos.\n");
		} else {
			valido = 1; // La cédula es válida
		}
	}
}

// Verifica si una placa tiene el formato que debe ser: ABC-1234
int validarPlaca(const char placa[]) {
	if (strlen(placa) != 8) return 0; // Debe tener exactamente 8 caracteres
	
	// Verifica que los primeros 3 sean letras mayúsculas
	for (int i = 0; i < 3; i++) {
		if (!(placa[i] >= 'A' && placa[i] <= 'Z')) return 0;
	}
	if (placa[3] != '-') return 0; // El cuarto carácter debe ser '-'
	// Verifica que los últimos 4 dígitos sean números
	for (int i = 4; i < 8; i++) {
		if (!(placa[i] >= '0' && placa[i] <= '9')) return 0;
	}
	
	return 1; // La placa es válida
}

// Se revisa si una placa ya fue registrada previamente
int yaRegistrado(const char placa[]) {
	for (int i = 0; i < total; i++) {
		if (strcmp(lista[i].placa, placa) == 0) {
			return 1; // Ya existe
		}
	}
	return 0; // No existe
}

void mostrarFecha() {
	time_t tiempo_actual;
	struct tm *info_tiempo;
	char fecha[80]; 
	
	tiempo_actual = time(NULL);
	info_tiempo = localtime(&tiempo_actual);
	strftime(fecha, sizeof(fecha), "%Y-%m-%d", info_tiempo); 
	
	printf("Fecha Actual: %s\n", fecha);
}

void mostrarResumen(struct Vehiculo v) {
	printf("Vehiculo registrado.\n");
}

void registrarVehiculo() {
	struct Vehiculo v;
	printf("\n--- Registrar Vehiculo ---\n");
	
	mostrarFecha();
	
	// Validar cédula
	pedirCedula(v.cedula);
	
	limpiarPantalla();
	
	// Validar año
	int anioValido = 0;
	while (!anioValido) {
		printf("Ingrese el anio del vehiculo (1990 - 2025): ");
		if (scanf("%d", &v.anio) == 1 && v.anio >= 1990 && v.anio <= 2025) {
			anioValido = 1;
		} else {
			printf("Anio invalido. Debe estar entre 1990 y 2025.\n");
		}
		limpiarBuffer();
	}
	
	limpiarPantalla();
	
	// Validar placa
	int placaValida = 0;
	while (!placaValida) {
		printf("Ingrese la placa (formato ABC-1234): ");
		scanf("%8s", v.placa);
		limpiarBuffer();
		
		if (!validarPlaca(v.placa)) {
			printf("Error: formato de placa invalido.\n");
		} else if (yaRegistrado(v.placa)) {
			printf("Error: esta placa ya esta registrada.\n");
		} else {
			placaValida = 1;
		}
	}
	
	limpiarPantalla();
	
	// Validar revisiones técnicas
	int revisionesValidas = 0;
	while (!revisionesValidas) {
		printf("Numero de revisiones tecnicas: ");
		if (scanf("%d", &v.revisiones) == 1) {
			if (v.revisiones == 3) {
				revisionesValidas = 1;
			} else if (v.revisiones > 3 || v.revisiones < 0) {
				printf("Error. Intente nuevamente.\n");
			} else {
				printf("No puede matricular el vehiculo. Necesita pasar las tres revisiones tecnicas.\n");
			}
		} else {
			printf("Ingrese un valor numérico valido.\n");
		}
		limpiarBuffer();
	}
	
	// Validar avalúo
	int avaluoValido = 0;
	while (!avaluoValido) {
		printf("Avaluo del vehiculo: $ ");
		if (scanf("%f", &v.avaluo) == 1 && v.avaluo > 0 && v.avaluo<500000) {
			avaluoValido = 1;
		} else {
			printf("Valor invalido. Ingrese un avaluo entre 0 y 500.000.\n");
		}
		limpiarBuffer();
	}
	
	if (v.anio <= 2018) {
		v.avaluo *= 0.8;
	}
	
	// Validar modelo
	printf("Modelo( Ejemplo: Mazda RX8): ");
	fgets(v.modelo, sizeof(v.modelo), stdin);
	v.modelo[strcspn(v.modelo, "\n")] = '\0';
	if (strlen(v.modelo) == 0) {
		printf("Error: el modelo no puede estar vacio.\n");
		return;
	}
	
	// Validar tipo
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
			printf("Opción invalida. Intente nuevamente.\n");
		}
		limpiarBuffer();
	}
	
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
	
	// Validar multas
	char m;
	int multaValida = 0;
	while (!multaValida) {
		printf("Tiene multas? (s/n): ");
		scanf(" %c", &m);
		limpiarBuffer();
		if (m == 's' || m == 'S') {
			v.multas = 1;
			multaValida = 1;
		} else if (m == 'n' || m == 'N') {
			v.multas = 0;
			multaValida = 1;
		} else {
			printf("Entrada invalida. Ingrese 's' o 'n'.\n");
		}
	}
	
	if (v.multas) {
		v.costo += 500;
	}
	
	if (total < MAX) {
		lista[total] = v;
		total++;
	}
	
	limpiarPantalla();
	mostrarResumen(v);
	mostrarComprobante(lista[total - 1]);
	generarComprobante(lista[total - 1]);
}

//Muestra el comprobante en pantalla 
void mostrarComprobante(struct Vehiculo v) {
	printf("----- COMPROBANTE DE MATRICULA -----\n");
	printf("Placa: %s\n", v.placa);
	printf("Tipo: %s\n", v.tipo);
	printf("Modelo: %s\n", v.modelo);
	printf("Año: %d\n", v.anio);
	printf("Avalúo: $%.2f\n", v.avaluo);
	printf("Valor a pagar: $%.2f\n", v.costo);
	printf("-----------------------------------\n");
}

//Funcion para generar el comprobante en un archivo txt
void generarComprobante(struct Vehiculo v) {
	char respuesta;
	printf("¿Desea generar el comprobante en archivo? (s/n): ");
	scanf(" %c", &respuesta);
	limpiarBuffer();
	
	if (respuesta != 's' && respuesta != 'S') {
		printf("No se generó el comprobante.\n");
		return;
	}
	
	FILE *archivo = fopen("comprobante.txt", "w");
	if (archivo == NULL) {
		printf("No se pudo crear el comprobante.\n");
		return;
	}
	
	fprintf(archivo, "----- COMPROBANTE DE MATRICULA -----\n");
	fprintf(archivo, "Placa: %s\n", v.placa);
	fprintf(archivo, "Tipo: %s\n", v.tipo);
	fprintf(archivo, "Modelo: %s\n", v.modelo);
	fprintf(archivo, "Año: %d\n", v.anio);
	fprintf(archivo, "Valor a pagar: %.2f\n", v.avaluo);
	fprintf(archivo, "Valor a pagar: %.2f\n", v.costo);
	fprintf(archivo, "-----------------------------------\n");
	
	fclose(archivo);
	printf("Comprobante generado correctamente.\n");
}

//Se busca el vehiculo por placa
void buscarVehiculoPorPlaca() {
	char placa[10];
	int encontrado = 0;
	
	printf("\n--- Buscar Vehiculo por Placa ---\n");
	printf("Ingrese la placa (formato ABC-1234): ");
	scanf("%9s", placa);
	limpiarBuffer();
	
	for (int i = 0; i < total; i++) {
		if (strcmp(lista[i].placa, placa) == 0) {
			printf("\nVehiculo encontrado:\n");
			mostrarComprobante(lista[i]);
			encontrado = 1;
			break;
		}
	}
	
	if (!encontrado) {
		printf("Vehiculo con placa %s no encontrado.\n", placa);
	}
}

//Guarda los datos registrados en un archivo txt
void guardarVehiculos() {
	FILE *archivo = fopen("vehiculos.txt", "w");
	if (archivo == NULL) {
		printf("Error al guardar en archivo.\n");
		return;
	}
	
	for (int i = 0; i < total; i++) {
		fprintf(archivo, "%s,%s,%s,%s,%d,%d,%.2f,%.2f,%d\n",
				lista[i].cedula,
				lista[i].placa,
				lista[i].modelo,
				lista[i].tipo,
				lista[i].anio,
				lista[i].revisiones,
				lista[i].avaluo,
				lista[i].costo,
				lista[i].multas);
	}
	
	fclose(archivo);
	printf("Vehículos guardados en vehiculos.txt\n");
}

//Funcion para leer las datos del arhivo 
void cargarVehiculos() {
	FILE *archivo = fopen("vehiculos.txt", "r");
	if (archivo == NULL) {
		total = 0;  // Archivo no existe todavía
		return;
	}
	
	total = 0;
	while (fscanf(archivo, "%10[^,],%8[^,],%29[^,],%29[^,],%d,%d,%f,%f,%d\n",
				  lista[total].cedula,
				  lista[total].placa,
				  lista[total].modelo,
				  lista[total].tipo,
				  &lista[total].anio,
				  &lista[total].revisiones,
				  &lista[total].avaluo,
				  &lista[total].costo,
				  &lista[total].multas) == 9) {
		total++;
		if (total >= MAX) break;
	}
	
	fclose(archivo);
	printf("Vehículos cargados desde vehiculos.txt\n");
}



