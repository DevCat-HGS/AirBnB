#include "reservacion.h"
#include <iostream>
#include <cstring>

// Constructor
Reservacion::Reservacion(const std::string& codigo, const std::string& fechaInicio, int duracion,
                         const std::string& docHuesped, const std::string& metodoPago,
                         const std::string& fechaPago, float monto, const char* obs,
                         Alojamiento* alojamiento, Huesped* huesped)
    : codigo(codigo), fechaInicio(fechaInicio), duracion(duracion),
      docHuesped(docHuesped), metodoPago(metodoPago), fechaPago(fechaPago),
      monto(monto), alojamiento(alojamiento), huesped(huesped) {
    // Copiar observaciones con límite de tamaño
    setObservaciones(obs);
}

// Setter para observaciones con control de tamaño
void Reservacion::setObservaciones(const char* obs) {
    if (obs) {
        strncpy(observaciones, obs, 999);
        observaciones[999] = '\0'; // Asegurar que termine en null
    } else {
        observaciones[0] = '\0';
    }
}

// Verifica si hay traslapes con otras reservaciones
bool Reservacion::validarTraslapes() const {
    // Implementación básica - en un sistema real se verificaría contra la BD
    // o contra las reservaciones existentes del alojamiento
    return true; // Por ahora asumimos que no hay traslapes
}

// Formatea la fecha para mostrarla
std::string Reservacion::formatearFecha() const {
    // Implementación básica - en un sistema real se usaría una biblioteca de fechas
    return fechaInicio + " (" + std::to_string(duracion) + " días)";
}

// Imprime un comprobante de la reservación
void Reservacion::imprimirComprobante() const {
    std::cout << "===== COMPROBANTE DE RESERVACIÓN =====" << std::endl;
    std::cout << "Código: " << codigo << std::endl;
    std::cout << "Fecha: " << formatearFecha() << std::endl;
    std::cout << "Huésped: " << (huesped ? huesped->getNombre() : "No especificado") << std::endl;
    std::cout << "Alojamiento: " << (alojamiento ? alojamiento->getNombre() : "No especificado") << std::endl;
    std::cout << "Monto total: $" << monto << std::endl;
    std::cout << "Método de pago: " << metodoPago << std::endl;
    std::cout << "Fecha de pago: " << fechaPago << std::endl;
    std::cout << "Observaciones: " << observaciones << std::endl;
    std::cout << "======================================" << std::endl;
}