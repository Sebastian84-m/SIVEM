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
void listaVehiculos(){
	if (total == 0) {
		printf("\nNo hay vehiculos registrados.\n");
		return; // Sale de la función si la lista está vacía
	}
	
	printf("\n===== Vehiculos Registrados =====\n");
	for (int i = 0; i < total; i++) {  //Recorre todos los vehículos registrados para procesarlos uno a uno.
		printf("Vehiculo: %d\n", i + 1);
		printf("Cedula %s\n",lista[i].cedula);
		printf("Placa: %s\n", lista[i].placa);
		printf("Año: %d\n",lista[i].anio);
		printf("Tipo: %s\n", lista[i].tipo);
		printf("Revisiones Tecnicas: %d\n", lista[i].revisiones);
		printf("Modelo: %s\n", lista[i].modelo);
		printf("Avaluo: $%.2f\n", lista[i].avaluo);
		printf("Costo matricula: $%.2f\n\n", lista[i].costo);
	}
}
