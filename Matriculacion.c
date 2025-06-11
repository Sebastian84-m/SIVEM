#include <stdio.h>      // Librer�a para entrada y salida est�ndar como: printf, scanf.
#include <stdlib.h>     // Librer�a para funciones del sistema como: system, malloc, etc.
#include <string.h>     // Librer�a para manipulaci�n de cadenas como: strlen, strcpy, strcmp, etc.

// Las constantes para tama�o m�ximo de veh�culos
#define MAX_VEHICULOS 100

// Estructura para representar un veh�culo
struct Vehiculo {
	char cedula[11];         // c�dula
	char placa[10];          // placa del veh�culo
	char tipo[20];           // tipo de veh�culo si es auto, Camioneta, etc.
	float avaluo;            // aval�o base del veh�culo
	float multiplicador;     // porcentaje que se aplica sobre el aval�o
	int tieneMultas;         // las multas
	float costoMatricula;    // costo final calculado para la matr�cula
	int anio;                // a�o de fabricaci�n del veh�culo
};

// Este es el arreglo donde se almacenan todos los veh�culos registrados
struct Vehiculo vehiculos[MAX_VEHICULOS];

// Contador de cu�ntos veh�culos se han registrado
int totalVehiculos = 0;

// Esta funci�n que limpia el buffer del teclado 
void limpiarBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF); // Descarta los caracteres
}

// Verifica que una cadena de 10 caracteres contenga solo n�meros
int esNumerica(const char* str) {
	for (int i = 0; i < 10; i++) {
		if (str[i] < '0' || str[i] > '9') return 0; // No es un d�gito
	}
	return 1;
}

// Solicita al usuario una c�dula v�lida si la ingres� mal anteriormente
void pedirCedula(char cedula[]) {
	int valido = 0;
	while (!valido) {
		printf("Ingrese cedula (10 digitos): ");
		scanf("%s", cedula); // se lee la c�dula como string
		if (strlen(cedula) != 10 || !esNumerica(cedula)) {
			printf("Error: la cedula debe tener exactamente 10 digitos numericos.\n");
		} else {
			valido = 1; // La c�dula es v�lida
		}
	}
}

// Verifica si una placa tiene el formato que debe ser: ABC-1234
int validarPlaca(const char placa[]) {
	if (strlen(placa) != 8) return 0; // Debe tener exactamente 8 caracteres
	
	// Verifica que los primeros 3 sean letras may�sculas si no sale error
	for (int i = 0; i < 3; i++) {
		if (!(placa[i] >= 'A' && placa[i] <= 'Z')) return 0;
	}
	
	if (placa[3] != '-') return 0; // El cuarto car�cter debe ser '-'
	
	// Verifica que los �ltimos 4 sean n�meros
	for (int i = 4; i < 8; i++) {
		if (!(placa[i] >= '0' && placa[i] <= '9')) return 0;
	}
	
	return 1; // la placa es v�lida
}

// se revisa si una placa ya fue registrada previamente
int yaRegistrado(const char placa[]) {
	for (int i = 0; i < totalVehiculos; i++) {
		if (strcmp(vehiculos[i].placa, placa) == 0) {
			return 1; // Ya existe
		}
	}
	return 0; // No existe
}

// Muestra men� de tipos de veh�culos y retorna el multiplicador correspondiente
float obtenerMultiplicadorPorTipo(char tipo[]) {
	int opcion;
	
	// Mostrar opciones de tipo de veh�culo
	printf("\nTipos de veh�culo:\n");
	printf(" 1. Auto (1.5%%)\n");
	printf(" 2. Camioneta (1.8%%)\n");
	printf(" 3. Moto (1.2%%)\n");
	printf(" 4. Otro (1.0%%)\n");
	printf("Seleccione el tipo de veh�culo: ");
	scanf("%d", &opcion);
	limpiarBuffer(); // Eliminar el salto de l�nea
	
	// Retornar multiplicador seg�n tipo
	switch (opcion) {
	case 1:
		strcpy(tipo, "Auto");
		return 0.015;
	case 2:
		strcpy(tipo, "Camioneta");
		return 0.018;
	case 3:
		strcpy(tipo, "Moto");
		return 0.012;
	default:
		strcpy(tipo, "Otro");
		return 0.010;
	}
}

// Funci�n principal
int main() {
	system("cls");  // se limpia pantalla al mostrar el resumen 
	char continuar = 's'; // esta es la condici�n para saber si se debe seguir ejecutando el bucle de registro.
	
	do {
		struct Vehiculo v;
		char conMultas;
		float av;
		
		printf("===== Registro de Vehiculo =====\n");
		
		pedirCedula(v.cedula);
		
		// Se pide el aval�o base directamente
		printf("Ingrese el aval�o base del veh�culo: ");
		scanf("%f", &av);
		limpiarBuffer();
		v.avaluo = av;
		
		// Se obtiene el tipo y multiplicador
		v.multiplicador = obtenerMultiplicadorPorTipo(v.tipo);
		
		// La validaci�n del a�o desde 1990 a 2025
		int anioValido = 0;
		while (!anioValido) {
			printf("Ingrese el a�o del veh�culo (1990 - 2025): ");
			scanf("%d", &v.anio);
			limpiarBuffer();
			if (v.anio >= 1990 && v.anio <= 2025) {
				anioValido = 1;
			} else {
				printf("A�o inv�lido. Debe estar entre 1990 y 2025.\n");
			}
		}
		
		if (v.anio <= 2018) {
			v.avaluo *= 0.8;
		}
		
		// Validaci�n de placa
		int placaValida = 0;
		while (!placaValida) {
			printf("Ingrese la placa (formato ABC-1234): ");
			scanf("%s", v.placa);
			limpiarBuffer();
			
			if (!validarPlaca(v.placa)) {
				printf("Error: formato de placa invalido.\n");
			} else if (yaRegistrado(v.placa)) {
				printf("Error: esta placa ya esta registrada.\n");
			} else {
				placaValida = 1;
			}
		}
		
		printf("�Tiene multas? (s/n): ");
		scanf(" %c", &conMultas);
		v.tieneMultas = (conMultas == 's' || conMultas == 'S') ? 1 : 0;
		
		v.costoMatricula = v.avaluo * v.multiplicador;
		if (v.tieneMultas) {
			v.costoMatricula += 500;
		}
		
		if (totalVehiculos < MAX_VEHICULOS) {
			vehiculos[totalVehiculos++] = v;
		}
		
		system("cls");
		
		// Se muestra el resumen del registro del veh�culo
		printf("\n===== Vehiculo Registrado >:) =====\n");
		printf("C�dula: %s\n", v.cedula);
		printf("A�o del veh�culo: %d\n", v.anio);
		printf("Tipo de veh�culo: %s\n", v.tipo);
		printf("Placa: %s\n", v.placa);
		printf("Aval�o ajustado: $%.2f\n", v.avaluo);
		printf("Multiplicador aplicado: %.2f%%\n", v.multiplicador * 100);
		printf("Multas: %s\n", v.tieneMultas ? "S�" : "No");
		printf("Costo total de matr�cula: $%.2f\n", v.costoMatricula);
		
		// se pregunta si desea registrar otro auto
		printf("\n�Desea registrar otro veh�culo? (s/n): ");
		scanf(" %c", &continuar);
		limpiarBuffer();
		
		system("cls");
		
	} while (continuar == 's' || continuar == 'S');
	
	printf("\nPrograma finalizado. Se registraron %d veh�culo(s).\n", totalVehiculos);
	return 0;
}
