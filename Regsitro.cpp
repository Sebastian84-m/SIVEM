#include <stdio.h>      // Librer�a para entrada y salida est�ndar como printf, scanf.
#include <string.h>     // Librer�a para funciones de manejo de cadenas
#define MAX_REVISIONES 3   // Constante que define el n�mero m�ximo de revisiones t�cnicas

// La funci�n principal del programa
int main (){
	// Variables para almacenar los datos del veh�culo
	char placa [20];
	char marca [20];
	int modelo ;
	float valorVehiculo;
	float pagoMatricula;   // Monto que se pagar� por matr�cula
	
	int total = 0;  // Contador de revisiones realizadas
	
	// Arreglo para almacenar hasta MAX_REVISIONES revisiones t�cnicas
	RevisionTecnica revisiones[MAX_REVISIONES];
	
	// Registro de datos del veh�culo del usuario
	printf("===== Registro del Veh�culo =====\n");
	printf("Ingrese la placa: ");
	scanf("%s", placa);
	
	printf("Ingrese la marca: ");
	scanf("%s", marca);
	
	printf("Ingrese el modelo (a�o): ");
	scanf("%d", &modelo);
	
	printf("Ingrese el valor del veh�culo: ");
	scanf("%f", &valorVehiculo);
	
	// C�lculo del pago de matr�cula con el 1.5% del valor del veh�culo
	pagoMatricula = valorVehiculo * 0.015;
	
	// Muestra los datos ingresados y el resultado del c�lculo
	printf("\n=== Datos del Veh�culo ===\n");
	printf("Placa: %s\n", placa);
	printf("Marca: %s\n", marca);
	printf("Modelo: %d\n", modelo);
	printf("Valor del veh�culo: %.2f\n", valorVehiculo);
	printf("Pago de matr�cula: %.2f\n", pagoMatricula);
	
	// Llamada a la funci�n para registrar una revisi�n t�cnica
	registrarRevision(revisiones, &total);
	
	return 0;  // Fin del programa
}
	
	// Estructura para representar una revisi�n t�cnica
	typedef struct {
		char placa[10];       // Placa del veh�culo
		char fecha[11];       // Fecha de la revisi�n (formato YYYY-MM-DD)
		char resultado[15];   // Resultado de la revisi�n ("Aprobado" o "No aprobado")
	} RevisionTecnica;
	
	// Funci�n para registrar una revisi�n t�cnica
	void registrarRevision (RevisionTecnica revisiones[], int *total ){
		// Verifica si ya se alcanz� el n�mero m�ximo de revisiones
		if (*total >= MAX_REVISIONES) {
			printf("No se puede registrar mas revisiones");
			return;
		}
		
		// Solicita los datos de la revisi�n t�cnica
		printf("Ingrese la placa del vehiculo: ");
		scanf("%s", revisiones[*total].placa);
		
		printf("Ingrese la fecha (YYYY-MM-DD): ");
		scanf("%s", revisiones[*total].fecha);
		
		printf("Ingrese el resultado (Aprobado / No aprobado): ");
		scanf("%s", revisiones[*total].resultado);
		
		// Incrementa el contador de revisiones
		(*total)++;
		
		// Muestra confirmaci�n
		printf("Revision registrada con exito \n");
		printf("Cantidad de revisiones realizadas: %d\n", *total);
	}
		
