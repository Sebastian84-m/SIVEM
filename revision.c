#include <stdio.h>
#include "registro.h"
#include "revision.h"
#include "limpiar.h"

extern struct Vehiculo lista[];
extern int total;

void listaVehiculos(){
	if (total == 0) {
		printf("\nNo hay vehiculos registrados.\n");
		return; // Sale de la función si la lista está vacía
	}
	
	printf("\nVehiculos Registrados \n");
	for (int i = 0; i < total; i++) {  //Recorre todos los vehículos registrados para procesarlos uno a uno.
		printf("%d.-||", i + 1);
		printf("Fecha: %s ||", lista[i].fechaHora);
		printf("Placa: %s ||", lista[i].placa);
		printf("Anio: %d ||",lista[i].anio);
		printf("Tipo: %s ||", lista[i].tipo);
		printf("Avaluo: $%.2f\n", lista[i].avaluo);
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
	}
	char z;
	
	do {
		printf("Desea volver al menu? (S o N): ");
		scanf(" %c", &z);
		limpiar_buffer();
		if (!(z == 'S' || z == 's' || z == 'N' || z == 'n')) {
			printf("Entrada inválida. Por favor ingrese solo 'S' o 'N'.\n");
		}
	} while (!(z == 'S' || z == 's' || z == 'N' || z == 'n'));
	
	if (z == 'N' || z == 'n') {
		limpiar_pantalla();
		printf("Gracias por usar.\n");
		exit(0);
	}
	limpiar_pantalla();
	return ;
}
