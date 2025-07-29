#include <stdio.h>
#include <string.h>
#include "login.h"
#include "limpiar.h"

#define MAX_USUARIOS 10
#define MAX_LONGITUD_USUARIO 25
#define MAX_LONGITUD_CONTRASENA 15

struct Usuario {
	char nombre[MAX_LONGITUD_USUARIO + 1];
	char contrasena[MAX_LONGITUD_CONTRASENA + 1];
};

struct Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

void cargarUsuarios() {
	FILE *archivo = fopen("usuarios.txt", "r");
	if (archivo == NULL) return;
	
	char linea[MAX_LONGITUD_USUARIO + MAX_LONGITUD_CONTRASENA + 3];
	while (fgets(linea, sizeof(linea), archivo) != NULL) {
		linea[strcspn(linea, "\n")] = 0; 
		
		if (sscanf(linea, "%s %s", 
				   usuarios[totalUsuarios].nombre, 
				   usuarios[totalUsuarios].contrasena) == 2) {
			totalUsuarios++;
			if (totalUsuarios >= MAX_USUARIOS) break;
		}
	}
	
	fclose(archivo);
}

void guardarUsuarios() {
	FILE *archivo = fopen("usuarios.txt", "w");
	if (archivo == NULL) return;
	
	for (int i = 0; i < totalUsuarios; i++) {
		fprintf(archivo, "%s %s\n", 
				usuarios[i].nombre, 
				usuarios[i].contrasena);
	}
	
	fclose(archivo);
}

void registrarUsuario() {
	if (totalUsuarios >= MAX_USUARIOS) {
		printf("Maximo de usuarios alcanzado!\n");
		return;
	}
	limpiar_pantalla();
	printf("\n--- Registro de Nuevo Usuario ---\n");
	
	char input_buffer[MAX_LONGITUD_USUARIO + 2];
	int len;
	
	// Limpiar el buffer de entrada antes de pedir el nombre de usuario
	limpiar_buffer(); 
	
	printf("Nombre de usuario (hasta %d caracteres): ", MAX_LONGITUD_USUARIO);
	if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
		printf("\nError en lectura de usuario.\n");
		return;
	}
	
	len = strlen(input_buffer);
	if (len > 0 && input_buffer[len - 1] == '\n') {
		input_buffer[len - 1] = '\0';
	} else {
		limpiar_buffer(); 
	}
	
	if (strlen(input_buffer) > MAX_LONGITUD_USUARIO) {
		printf("Error: El nombre de usuario excede el maximo de %d caracteres. Intenta de nuevo.\n", MAX_LONGITUD_USUARIO);
		esperar_3segundos();
		return;
	}
	strcpy(usuarios[totalUsuarios].nombre, input_buffer);
	
	printf("Contrasena (hasta %d caracteres): ", MAX_LONGITUD_CONTRASENA);
	if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
		printf("\nError en lectura de contrasena.\n");
		return;
	}
	
	len = strlen(input_buffer);
	if (len > 0 && input_buffer[len - 1] == '\n') {
		input_buffer[len - 1] = '\0';
	} else {
		limpiar_buffer();
	}
	
	if (strlen(input_buffer) > MAX_LONGITUD_CONTRASENA) {
		printf("Error: La contrasena excede el maximo de %d caracteres. Intenta de nuevo.\n", MAX_LONGITUD_CONTRASENA);
		esperar_3segundos();
		return;
	}
	strcpy(usuarios[totalUsuarios].contrasena, input_buffer);
	
	totalUsuarios++;
	guardarUsuarios();
	
	printf("Usuario registrado con exito\n");
}

int login() {
	limpiar_pantalla();
	
	char nombre_input[MAX_LONGITUD_USUARIO + 2];
	char contrasena_input[MAX_LONGITUD_CONTRASENA + 2];
	int len;
	
	printf("\n--- Inicio de Sesion ---\n");
	
	// Limpiar el buffer de entrada antes de pedir el nombre de usuario
	// Esto es crucial si una funcion anterior dejo un '\n'
	limpiar_buffer(); 
	
	printf("Usuario: ");
	if (fgets(nombre_input, sizeof(nombre_input), stdin) == NULL) {
		printf("\nError en lectura de usuario\n");
		esperar_3segundos();
		return 0;
	}
	
	len = strlen(nombre_input);
	if (len > 0 && nombre_input[len - 1] == '\n') {
		nombre_input[len - 1] = '\0';
	} else {
		limpiar_buffer(); 
	}
	
	if (strlen(nombre_input) > MAX_LONGITUD_USUARIO) {
		printf("\nError: El nombre de usuario excede el maximo de %d caracteres.\n", MAX_LONGITUD_USUARIO);
		esperar_3segundos();
		return 0;
	}
	
	printf("Contrasena: ");
	if (fgets(contrasena_input, sizeof(contrasena_input), stdin) == NULL) {
		printf("\nError en lectura de contrasena\n");
		esperar_3segundos();
		return 0;
	}
	
	len = strlen(contrasena_input);
	if (len > 0 && contrasena_input[len - 1] == '\n') {
		contrasena_input[len - 1] = '\0';
	} else {
		limpiar_buffer();
	}
	
	if (strlen(contrasena_input) > MAX_LONGITUD_CONTRASENA) {
		printf("\nError: La contrasena excede el maximo de %d caracteres.\n", MAX_LONGITUD_CONTRASENA);
		esperar_3segundos();
		return 0;
	}
	
	for (int i = 0; i < totalUsuarios; i++) {
		if (strcmp(nombre_input, usuarios[i].nombre) == 0 &&
			strcmp(contrasena_input, usuarios[i].contrasena) == 0) {
			printf("Bienvenido, %s!\n", nombre_input);
			esperar_3segundos();
			limpiar_pantalla();
			return 1;
		}
	}
	
	printf("\nUsuario o contrasena incorrectos.\n");
	esperar_3segundos();
	return 0;
}
