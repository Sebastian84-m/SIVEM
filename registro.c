#include <stdio.h>
#include <string.h>
#include "registro.h"
#define MAX 100
#include <stdlib.h>
#include <time.h>

struct Vehiculo lista[MAX];
int total = 0;

void limpiarBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
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

void limpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void mostrarResumen(struct Vehiculo v) {
	printf("Vehiculo registrado.\n");
}

void registrarVehiculo() {
	struct Vehiculo v;
	printf("\n--- Registrar Vehiculo ---\n");
	
	mostrarFecha();
	
	// Pide la cédula, solo acepta 10 dígitos numéricos
	do {
		printf("Cedula (10 digitos): ");
		scanf("%10s", v.cedula);
		limpiarBuffer();
	} while (strlen(v.cedula) != 10 || strspn(v.cedula, "0123456789") != 10);
	
	printf("Placa (ABC1234): ");
	fgets(v.placa, sizeof(v.placa), stdin); 
	v.placa[strcspn(v.placa, "\n")] = '\0';
	
	printf ("Numero de revisiones tecnicas:");
	scanf("%d", &v.revisiones);
	if (v.revisiones<3 && v.revisiones>0){
		limpiarPantalla();
		printf("No puede matricular el vehiculo. Necesita pasar las tres revisiones tecnicas.");
		return ;
	} else if (v.revisiones>3 || v.revisiones<0){
		limpiarPantalla();
		printf ("Error. Intente nuevamente");
		return ;
	}
	
	printf("Valor del vehiculo: ");
	scanf("%f", &v.avaluo);
	limpiarBuffer();
	
	printf ("Modelo:");
	fgets(v.modelo, sizeof(v.modelo), stdin);
	v.modelo[strcspn(v.modelo, "\n")] = '\0';
	
	printf("Tipo:\n 1.Vehiculo particular\n 2.Motocicletas\n 3.Transporte publico-comercial\n Seleccione: ");
	int t;
	scanf("%d", &t);
	limpiarBuffer();
	
	if(t == 1) {
		strcpy(v.tipo, "Vehiculo particular");
		v.costo = v.avaluo * 0.015;
	} 
	else if(t == 2) {
		strcpy(v.tipo, "Motocicletas");
		v.costo = v.avaluo * 0.018;
	}
	else {
		strcpy(v.tipo, "Transporte publico-comercial");
		v.costo = v.avaluo * 0.012;
	}
	
	printf("Tiene multas? (s/n): ");
	char m;
	scanf(" %c", &m);
	v.multas = (m == 's') ? 1 : 0;
	if(v.multas) v.costo += 500;
	
	if(total < MAX) {
		lista[total] = v;
		total++;
	}
	limpiarPantalla();
	mostrarResumen(v);
}
