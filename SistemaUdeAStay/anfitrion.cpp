#include "anfitrion.h"
#include <iostream>

// Constructor
Anfitrion::Anfitrion(const std::string& documento, int antiguedad, float puntuacion)
    : documento(documento), antiguedad(antiguedad), puntuacion(puntuacion) {
}

// Destructor
Anfitrion::~Anfitrion() {
    // Eliminar todas las referencias a alojamientos
    Nodo<Alojamiento*>* actual = alojamientos.getCabeza();
    while (actual != nullptr) {
        Alojamiento* alojamiento = actual->getDato();
        // No eliminamos el alojamiento aquí, solo la referencia
        actual = actual->getSiguiente();
    }
}

// Agregar un alojamiento
void Anfitrion::agregarAlojamiento(Alojamiento* alojamiento) {
    if (alojamiento && alojamiento->getAnfitrion() == this) {
        alojamientos.agregar(alojamiento);
    }
}

// Eliminar un alojamiento
void Anfitrion::eliminarAlojamiento(Alojamiento* alojamiento) {
    if (alojamiento) {
        alojamientos.eliminar(alojamiento);
    }
}

// Contar alojamientos
int Anfitrion::contarAlojamientos() const {
    return alojamientos.contar();
}