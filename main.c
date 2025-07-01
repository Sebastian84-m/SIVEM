#include <stdio.h>    // Incluye la librer�a est�ndar de entrada/salida (para printf/scanf)
#include "menu.h"       
#include "registro.h"    
#include "matricula.h"   
#include "revision.h"    

//declaramos las funciones
void guardarVehiculos();
void cargarVehiculos();

int main() {
	int opcion;
	//Se cargan los datos al inicio 
	cargarVehiculos();
	//creamos el bucle de la funcion mostrarMenu
	do {
		mostrarMenu();
		
		if(scanf("%d", &opcion) != 1) {  //Verifica si el usuario ingres� un n�mero. Si no, muestra un error.
			printf("Entrada invalida. Debe colocar una de las 4 opciones.\n");
			while(getchar() != '\n');  // Limpia la parte mal escrita.
		}
		procesarOpcion(opcion); //Ejecuta una acci�n seg�n la opci�n seleccionada por el usuario.
		
		if (opcion == 1) {  // Solo guardamos si registramos un nuevo veh�culo
			guardarVehiculos();
		}
	} while(opcion != 5);
	return 0;
}
