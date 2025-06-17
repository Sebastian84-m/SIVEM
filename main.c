#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "registro.h"
#include "matricula.h"
#include "revision.h"

int main() {
	int opcion;
	
	do {
		mostrarMenu();
		scanf("%d", &opcion);
		limpiarBuffer();
		procesarOpcion(opcion);
		
	} while(opcion != 5);


	return 0;
}
