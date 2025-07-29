#include "limpiar.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Para limpieza de buffer más efectiva

// Limpiar pantalla (Windows)
void limpiar_pantalla() {
	system("cls");
}

// Limpiar buffer de entrada
void limpiar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// Esperar 3 segundos (Windows)
void esperar_3segundos() {
#ifdef _WIN32
	Sleep(3000);
#else
	sleep(3);
#endif
}
