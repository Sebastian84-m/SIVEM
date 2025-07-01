#include <stdio.h>
#include <string.h>
#include "login.h"

// Funci�n que verifica usuario y contrase�a en el archivo
int verificarLogin(char usuario[], char clave[]) {
	FILE *archivo = fopen("usuarios.txt", "r"); // Abre archivo en modo lectura
	if (archivo == NULL) {
		return 0; // Si no existe el archivo, retorna falso
	}
	
	char user[20]; // Buffer para usuario del archivo
	char pass[20]; // Buffer para contrase�a del archivo
	int encontrado = 0; // Flag para indicar si se encontr�
	
	// Lee el archivo l�nea por l�nea
	while (fscanf(archivo, "%s %s", user, pass) == 2) {
		if (strcmp(usuario, user) == 0 && strcmp(clave, pass) == 0) {
			encontrado = 1; // Credenciales correctas
			break;
		}
	}
	
	fclose(archivo); // Cierra el archivo
	return encontrado; // Retorna resultado
}

// Funci�n para registrar nuevos usuarios
void registrarUsuario() {
	char nuevoUser[20]; // Buffer para nuevo usuario
	char nuevaPass[20]; // Buffer para nueva contrase�a
	
	printf("\n--- REGISTRO DE USUARIO ---\n");
	printf("Nuevo usuario: ");
	scanf("%s", nuevoUser);
	printf("Nueva contrase�a: ");
	scanf("%s", nuevaPass);
	
	FILE *archivo = fopen("usuarios.txt", "a"); // Abre en modo append
	if (archivo == NULL) {
		printf("Error al abrir archivo de usuarios\n");
		return;
	}
	
	// Escribe el nuevo usuario en el archivo
	fprintf(archivo, "%s %s\n", nuevoUser, nuevaPass);
	fclose(archivo); // Cierra el archivo
	printf("Usuario registrado con �xito!\n");
}