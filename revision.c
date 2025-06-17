#include <stdio.h>
#include "registro.h"
#include "revision.h"

extern struct Vehiculo lista[];
extern int total;

void registrarRevision() {
	if (total == 0) {
		printf("\nNo hay vehiculos registrados.\n");
		return;
	}
	
	char placa[10];
	printf("\n--- Registrar Revision ---\n");
	printf("Ingrese placa del vehiculo (ABC-1234): ");
	scanf("%9s", placa);
	
	int encontrado = 0;
	for (int i = 0; i < total; i++) {
		if (strcmp(lista[i].placa, placa) == 0) {
			printf("\nVehiculo encontrado:\n");
			mostrarResumen(lista[i]);
			printf("Revision registrada exitosamente.\n");
			encontrado = 1;
			break;
		}
	}
	
	if (!encontrado) {
		printf("\nVehiculo con placa %s no encontrado.\n", placa);
	}
}
