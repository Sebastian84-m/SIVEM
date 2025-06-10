#include <stdio.h>      // Librería para entrada y salida estándar como printf, scanf.
#include <string.h>     // Librería para funciones de manejo de cadenas
#define MAX_REVISIONES 3   // Constante que define el número máximo de revisiones técnicas

// La función principal del programa
int main (){
	// Variables para almacenar los datos del vehículo
	char placa [20];
	char marca [20];
	int modelo ;
	float valorVehiculo;
	float pagoMatricula;   // Monto que se pagará por matrícula
	
	int total = 0;  // Contador de revisiones realizadas
	
	// Arreglo para almacenar hasta MAX_REVISIONES revisiones técnicas
	RevisionTecnica revisiones[MAX_REVISIONES];
	
	// Registro de datos del vehículo del usuario
	printf("===== Registro del Vehículo =====\n");
	printf("Ingrese la placa: ");
	scanf("%s", placa);
	
	printf("Ingrese la marca: ");
	scanf("%s", marca);
	
	printf("Ingrese el modelo (año): ");
	scanf("%d", &modelo);
	
	printf("Ingrese el valor del vehículo: ");
	scanf("%f", &valorVehiculo);
	
	// Cálculo del pago de matrícula con el 1.5% del valor del vehículo
	pagoMatricula = valorVehiculo * 0.015;
	
	// Muestra los datos ingresados y el resultado del cálculo
	printf("\n=== Datos del Vehículo ===\n");
	printf("Placa: %s\n", placa);
	printf("Marca: %s\n", marca);
	printf("Modelo: %d\n", modelo);
	printf("Valor del vehículo: %.2f\n", valorVehiculo);
	printf("Pago de matrícula: %.2f\n", pagoMatricula);
	
	// Llamada a la función para registrar una revisión técnica
	registrarRevision(revisiones, &total);
	
	return 0;  // Fin del programa
}
	
	// Estructura para representar una revisión técnica
	typedef struct {
		char placa[10];       // Placa del vehículo
		char fecha[11];       // Fecha de la revisión (formato YYYY-MM-DD)
		char resultado[15];   // Resultado de la revisión ("Aprobado" o "No aprobado")
	} RevisionTecnica;
	
	// Función para registrar una revisión técnica
	void registrarRevision (RevisionTecnica revisiones[], int *total ){
		// Verifica si ya se alcanzó el número máximo de revisiones
		if (*total >= MAX_REVISIONES) {
			printf("No se puede registrar mas revisiones");
			return;
		}
		
		// Solicita los datos de la revisión técnica
		printf("Ingrese la placa del vehiculo: ");
		scanf("%s", revisiones[*total].placa);
		
		printf("Ingrese la fecha (YYYY-MM-DD): ");
		scanf("%s", revisiones[*total].fecha);
		
		printf("Ingrese el resultado (Aprobado / No aprobado): ");
		scanf("%s", revisiones[*total].resultado);
		
		// Incrementa el contador de revisiones
		(*total)++;
		
		// Muestra confirmación
		printf("Revision registrada con exito \n");
		printf("Cantidad de revisiones realizadas: %d\n", *total);
	}
		
