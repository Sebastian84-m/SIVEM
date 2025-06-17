a#include <stdio.h>
#include "registro.h"
#include "matricula.h"

extern struct Vehiculo lista[];
extern int total;
void calcularMatricula() {
	if (total == 0) {
		printf("\nNo hay vehiculos registrados.\n");
		return;
	}
	
	printf("\n--- Vehiculos Registrados ---\n");
	for (int i = 0; i < total; i++) {
		printf("=============\n\nVehiculo:%d\nPlaca:%s\nTipo:%s\nRevisiones Tecnicas:%d\nModelo:%s\nAvaluo:$%.2f\nCosto matricula:$%.2f\n  ", 
			   i+1,lista[i].placa,lista[i].tipo, lista[i].revisiones,lista[i].modelo,lista[i].avaluo, lista[i].costo);
	}
}
