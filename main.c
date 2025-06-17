#include <stdio.h>    // Incluye la librería estándar de entrada/salida (para printf/scanf)
#include "menu.h"       
#include "registro.h"    
#include "matricula.h"   
#include "revision.h"    

//declaramos las funciones

int main() {
	int opcion;
	
	//creamos el bucle de la funcion mostrarMenu
	do {
		mostrarMenu();
		
		if(scanf("%d", &opcion) != 1) {  //Verifica si el usuario ingresó un número. Si no, muestra un error.
			printf("Entrada invalida. Debe colocar una de las 4 opciones.\n");
			while(getchar() != '\n');  // Limpia la parte mal escrita.
			continue;
		}
		procesarOpcion(opcion); //Ejecuta una acción según la opción seleccionada por el usuario.
		
	} while(opcion != 5);
	
	
	return 0;
}
