#ifndef REGISTRO_H
#define REGISTRO_H

struct Vehiculo {
	char placa[10];        // Formato ABC1234 
	char fecha[80];        // Fecha en la que se matricula
	char tipo[50];         // Particular, motocicleta y transporte publico
	char modelo[50];       // Modelo del vehiculo
	int revisiones;        // La cantidad de revisiones que tiene el vehiculo
	float avaluo;          // Avaluo del vehiculo
	float costo;           // Costo total de matr�cula
	int multas;            // Registra las multas
};

// Funci�n para registrar un nuevo veh�culo
void registrarVehiculo();

// Funci�n para mostrar resumen de un veh�culo
void mostrarResumen(struct Vehiculo v);

#endif
