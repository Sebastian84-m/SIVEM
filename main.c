#include <stdio.h>       // Librer�a est�ndar de entrada/salida
#include "menu.h"        // Prototipos del men� principal
#include "registro.h"    // Registro de veh�culos
#include "matricula.h"   // Matriculaci�n
#include "revision.h"    // Revisi�n t�cnica
#include "login.h"       // Login y usuarios
#include "limpiar.h"

// Declaraci�n de funciones auxiliares
void guardarVehiculos();
void cargarVehiculos();

int main() {
	cargarUsuarios();    // Carga los usuarios registrados
	cargarVehiculos();   // Carga los veh�culos registrados
	
	int opcion;
	
	do {
		esperar_3segundos();
		limpiar_pantalla();
		
		printf("\n=== SISTEMA DE ACCESO ===\n");
		printf("1. Iniciar sesion\n");
		printf("2. Registrar nuevo usuario\n");
		printf("3. Salir\n");
		
		// Validaci�n robusta de opci�n
		printf("Seleccione opcion : ");
		if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3) {
			printf("\nEntrada invalida. Debe ingresar un numero entre 1 y 3.\n");
			limpiar_buffer();
			esperar_3segundos(); // Vuelve al inicio del bucle
		}
		
		switch (opcion) {
		case 1:
			if (login()) {  // Si el login es exitoso
				int opcionMenu;
				do {
					mostrarMenu();
					if (scanf("%d", &opcionMenu) != 1) {
						printf("Entrada invalida. Debe colocar una de las 4 opciones.\n");
						limpiar_buffer();
					}
					
					procesarOpcion(opcionMenu);
					
					if (opcionMenu == 1) {
						guardarVehiculos();  // Guardar veh�culos si se registraron
					}
					
				} while (opcionMenu != 4);  // Salir del submen�
			}
			break;
			
		case 2:
			registrarUsuario();
			break;
			
		case 3:
			printf("\nSaliendo del programa.\n");
			break;
		}
		
	} while (opcion != 3);
	
	return 0;
}


