#include <stdio.h>
#include "menu.h"
#include "registro.h"
#include "matricula.h"
#include "revision.h"
#include "limpiar.h"
#include "revision.h"

//declaramos la funcion mostrarMenu

void mostrarMenu() {
	printf("\n=== SISTEMA SIVEM ===\n");
	printf("1. Registrar vehiculo\n");
	printf("2. Buscar vehiculo\n");
	printf("3. Lista de vehiculos\n");
	printf("4. Salir\n");
	printf("Seleccione opcion: ");
}

//Declaramos la funcion procesarOpcion


void procesarOpcion(int opcion) {    //recibe una opcion numérica
		switch(opcion) { //evaluar el valor de la opcion
	case 1:
		limpiar_pantalla(); 
		limpiar_buffer();
		registrarVehiculo();
		break;
	case 2:
		limpiar_pantalla();
		limpiar_buffer();
		buscarVehiculoPorPlaca();
		break;
	case 3:
		limpiar_pantalla();
		limpiar_buffer();
		listaVehiculos();
		break;
	case 4:
		printf("\nSaliendo del programa.\n");
		break;
	default:
		limpiar_pantalla();
		limpiar_buffer();
		printf("\nOpcion no valida.Ingrese otra opcion.\n");
	}
}
