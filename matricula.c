#include <stdio.h>
#include "registro.h"
#include "matricula.h"

//Usa variables globales definidas externamente.

extern struct Vehiculo lista[];   //arreglo global de veh�culos.
extern int total;                 //cu�ntos veh�culos hay registrados

void calcularMatricula() {
	if (total == 0) {
		printf("\nNo hay vehiculos registrados.\n");
		return; // Sale de la funci�n si la lista est� vac�a
	}
	
	printf("Vehiculos Registrado\n");
	for (int i = 0; i < total; i++) {  //Recorre todos los veh�culos registrados para procesarlos uno a uno.
		printf("=============\n");
		printf("Vehiculo: %d\n", i + 1);
		printf("Cedula %s\n",lista[i].cedula);
		printf("Placa: %s\n", lista[i].placa);
		printf("Avaluo: $%.2f\n", lista[i].avaluo);
		printf("Costo matricula: $%.2f\n\n", lista[i].costo);
	}
}


