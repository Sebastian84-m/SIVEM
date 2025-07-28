#include <stdio.h>       // Librería estándar de entrada/salida
#include "menu.h"        // Prototipos del menú principal
#include "registro.h"    // Registro de vehículos
#include "matricula.h"   // Matriculación
#include "revision.h"    // Revisión técnica
#include "login.h"       // Login y usuarios
#include "limpiar.h"

// Declaración de funciones auxiliares
void guardarVehiculos();
void cargarVehiculos();

int main() {
	cargarUsuarios();    // Carga los usuarios registrados
	cargarVehiculos();   // Carga los vehículos registrados
	
	int opcion;
	
	do {
		esperar_3segundos();
		limpiar_pantalla();
		
		printf("\n=== SISTEMA DE ACCESO ===\n");
		printf("1. Iniciar sesion\n");
		printf("2. Registrar nuevo usuario\n");
		printf("3. Salir\n");
		
		// Validación robusta de opción
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
						guardarVehiculos();  // Guardar vehículos si se registraron
					}
					
				} while (opcionMenu != 4);  // Salir del submenú
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


