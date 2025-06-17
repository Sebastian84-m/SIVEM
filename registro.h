#ifndef REGISTRO_H
#define REGISTRO_H

struct Vehiculo {
	char placa[10];        // Formato ABC1234 
	char fecha[80];        // Fecha en la que se matricula
	char tipo[50];         // Particular, motocicleta y transporte publico
	char modelo[50];       // Modelo del vehiculo
	int revisiones;        // La cantidad de revisiones que tiene el vehiculo
	float avaluo;          // Avaluo del vehiculo
	float costo;           // Costo total de matrícula
	int multas;            // Registra las multas
};

// Función para registrar un nuevo vehículo
void registrarVehiculo();

// Función para mostrar resumen de un vehículo
void mostrarResumen(struct Vehiculo v);

#endif
