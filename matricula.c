#include <stdio.h>
#include "registro.h"
#include "matricula.h"

//Usa variables globales definidas externamente.

extern struct Vehiculo lista[];   //arreglo global de vehículos.
extern int total;                 //cuántos vehículos hay registrados

void calcularMatricula() {
	if (total == 0) {
		printf("\nNo hay vehiculos registrados.\n");
		return; // Sale de la función si la lista está vacía
	}
	
	printf("\n===== Vehiculos Registrados =====\n");
	for (int i = 0; i < total; i++) {  //Recorre todos los vehículos registrados para procesarlos uno a uno.
		printf("=============\n");
		printf("Vehiculo: %d\n", i + 1);
		printf("Placa: %s\n", lista[i].placa);
		printf("Tipo: %s\n", lista[i].tipo);
		printf("Revisiones Tecnicas: %d\n", lista[i].revisiones);
		printf("Modelo: %s\n", lista[i].modelo);
		printf("Avaluo: $%.2f\n", lista[i].avaluo);
		printf("Costo matricula: $%.2f\n\n", lista[i].costo);
	}
}
