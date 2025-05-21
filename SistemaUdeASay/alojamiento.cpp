#include "alojamiento.h"
#include <iostream>

// Constructor
Alojamiento::Alojamiento(const std::string& codigo, const std::string& nombre, const std::string& tipo,
                         const std::string& departamento, const std::string& municipio, 
                         const std::string& direccion, float precioNoche, Anfitrion* anfitrion)
    : codigo(codigo), nombre(nombre), tipo(tipo), departamento(departamento),
      municipio(municipio), direccion(direccion), precioNoche(precioNoche),
      anfitrion(anfitrion) {
    // Si el anfitrión existe, agregar este alojamiento a su lista
    if (anfitrion) {
        anfitrion->agregarAlojamiento(this);
    }
}

// Destructor
Alojamiento::~Alojamiento() {
    // Eliminar todas las reservaciones asociadas
    Nodo<Reservacion*>* actual = fechasReservadas.getCabeza();
    while (actual != nullptr) {
        Reservacion* reservacion = actual->getDato();
        // No eliminamos la reservación aquí, solo la referencia
        actual = actual->getSiguiente();
    }
    
    // Si el anfitrión existe, eliminar este alojamiento de su lista
    if (anfitrion) {
        anfitrion->eliminarAlojamiento(this);
    }
}

// Agregar una amenidad
void Alojamiento::agregarAmenidad(const std::string& amenidad) {
    amenidades.agregar(amenidad);
}

// Eliminar una amenidad
void Alojamiento::eliminarAmenidad(const std::string& amenidad) {
    amenidades.eliminar(amenidad);
}

// Mostrar información del alojamiento
void Alojamiento::mostrarInfo() const {
    std::cout << "===== INFORMACIÓN DEL ALOJAMIENTO =====" << std::endl;
    std::cout << "Código: " << codigo << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Ubicación: " << municipio << ", " << departamento << std::endl;
    std::cout << "Dirección: " << direccion << std::endl;
    std::cout << "Precio por noche: $" << precioNoche << std::endl;
    std::cout << "Anfitrión: " << (anfitrion ? anfitrion->getDocumento() : "No especificado") << std::endl;
    
    // Mostrar amenidades
    std::cout << "Amenidades:" << std::endl;
    Nodo<std::string>* actual = amenidades.getCabeza();
    while (actual != nullptr) {
        std::cout << "- " << actual->getDato() << std::endl;
        actual = actual->getSiguiente();
    }
    
    std::cout << "Reservaciones: " << fechasReservadas.contar() << std::endl;
    std::cout << "========================================" << std::endl;
}

// Verificar disponibilidad en un rango de fechas
bool Alojamiento::verificarDisponibilidad(const std::string& inicio, const std::string& fin) const {
    // Implementación básica - en un sistema real se verificaría contra la BD
    // o se haría una verificación más sofisticada de fechas
    return true; // Por ahora asumimos que siempre está disponible
}

// Agregar una reservación
void Alojamiento::agregarReservacion(Reservacion* reservacion) {
    if (reservacion && reservacion->getAlojamiento() == this) {
        fechasReservadas.agregar(reservacion);
    }
}

// Quitar una reservación
void Alojamiento::quitarReservacion(Reservacion* reservacion) {
    if (reservacion) {
        fechasReservadas.eliminar(reservacion);
    }
}