#include <stdio.h>
#include "menu.h"
#include "registro.h"
#include "matricula.h"
#include "revision.h"

void mostrarMenu() {
	printf("\n=== SISTEMA SIVEM ===\n");
	printf("1. Registrar vehiculo\n");
	printf("2. Calcular matricula\n");
	printf("3. Buscar vehiculo\n");
	printf("4. Lista de vehiculos\n");
	printf("5. Salir\n");
	printf("Seleccione opcion: ");
}

void procesarOpcion(int opcion) {
	switch(opcion) {
	case 1:
		limpiarPantalla();
		registrarVehiculo();
		break;
	case 2:
		limpiarPantalla();
		calcularMatricula();
		break;
	case 3:
		limpiarPantalla();
		registrarRevision();
		break;
	case 4:
		limpiarPantalla();
		break;
	case 5:
		printf("\nSaliendo del programa.\n");
		break;
	default:
		limpiarPantalla();
		printf("\nOpcion no valida.Ingrese otra opcion.\n");
	}
}
