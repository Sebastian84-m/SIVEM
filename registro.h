#ifndef REGISTRO_H
#define REGISTRO_H

struct Vehiculo {
	char cedula[11];       //se ingresa la cédula de 10 dígitos
	int anio;              //Año del vehiculo matriculado
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

//Funcion para mostrara el comprobante en pantalla 
void mostrarComprobante(struct Vehiculo v);

//Funcion para generar el comprobante de la matricula
void generarComprobante(struct Vehiculo v);

//Funcion para buscar el Vehiculo por placa
void buscarVehiculoPorPlaca();

//Funcion para guardar los datos en un archivo
void guardarVehiculos();

//Funcion para leer los datos del archivo
void cargarVehiculos();

#endif
