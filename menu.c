#include <stdio.h>
#include "menu.h"
#include "registro.h"
#include "matricula.h"
#include "revision.h"

//declaramos la funcion mostrarMenu

void mostrarMenu() {
	printf("\n=== SISTEMA SIVEM ===\n");
	printf("1. Registrar vehiculo\n");
	printf("2. Calcular matricula\n");
	printf("3. Buscar vehiculo\n");
	printf("4. Lista de vehiculos\n");
	printf("5. Salir\n");
	printf("Seleccione opcion: ");
}

//Declaramos la funcion procesarOpcion


void procesarOpcion(int opcion) {    //recibe una opcion numérica
	switch(opcion) { //evaluar el valor de la opcion
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
		buscarVehiculoPorPlaca();
		break;
	case 4:
		limpiarPantalla();
		listaVehiculos();
		break;
	case 5:
		printf("\nSaliendo del programa.\n");
		break;
	default:
		limpiarPantalla();
		printf("\nOpcion no valida.Ingrese otra opcion.\n");
	}
}
