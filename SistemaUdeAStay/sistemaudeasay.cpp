#include "sistemaudeasay.h"
#include <iostream>
#include <fstream>

// Constructor
SistemaUdeASay::SistemaUdeASay() {
    // Inicializar el sistema
    std::cout << "Inicializando Sistema UdeASay..." << std::endl;
    // Cargar datos almacenados si existen
    cargarDatos();
}

// Destructor
SistemaUdeASay::~SistemaUdeASay() {
    // Guardar datos antes de finalizar
    guardarDatos();
    
    // Liberar memoria de alojamientos
    Nodo<Alojamiento*>* actualAloj = alojamientos.getCabeza();
    while (actualAloj != nullptr) {
        Alojamiento* alojamiento = actualAloj->getDato();
        actualAloj = actualAloj->getSiguiente();
        delete alojamiento;
    }
    
    // Liberar memoria de huéspedes
    Nodo<Huesped*>* actualHuesp = huespedes.getCabeza();
    while (actualHuesp != nullptr) {
        Huesped* huesped = actualHuesp->getDato();
        actualHuesp = actualHuesp->getSiguiente();
        delete huesped;
    }
    
    // Liberar memoria de reservaciones
    Nodo<Reservacion*>* actualRes = reservaciones.getCabeza();
    while (actualRes != nullptr) {
        Reservacion* reservacion = actualRes->getDato();
        actualRes = actualRes->getSiguiente();
        delete reservacion;
    }
    
    std::cout << "Sistema UdeASay finalizado." << std::endl;
}

// Método de login
bool SistemaUdeASay::login() {
    // Implementación básica - en un sistema real se verificaría contra la BD
    std::cout << "Iniciando sesión en el sistema..." << std::endl;
    // Aquí iría la lógica de autenticación
    monitor.registrarInteraccion();
    return true; // Por ahora siempre retorna éxito
}

// Registrar un nuevo alojamiento
void SistemaUdeASay::registrarAlojamiento() {
    // Implementación básica - en un sistema real se solicitarían datos al usuario
    std::cout << "Registrando nuevo alojamiento..." << std::endl;
    // Aquí iría la lógica de registro
    monitor.registrarInteraccion();
}

// Cancelar una reserva existente
void SistemaUdeASay::cancelarReserva() {
    // Implementación básica - en un sistema real se solicitaría el código de reserva
    std::cout << "Cancelando reserva..." << std::endl;
    // Aquí iría la lógica de cancelación
    monitor.registrarInteraccion();
}

// Cargar datos desde archivos
void SistemaUdeASay::cargarDatos() {
    // Implementación básica - en un sistema real se cargarían datos desde archivos o BD
    std::cout << "Cargando datos del sistema..." << std::endl;
    // Aquí iría la lógica de carga de datos
    monitor.registrarInteraccion();
}

// Guardar datos en archivos
void SistemaUdeASay::guardarDatos() {
    // Implementación básica - en un sistema real se guardarían datos en archivos o BD
    std::cout << "Guardando datos del sistema..." << std::endl;
    // Aquí iría la lógica de guardado de datos
    monitor.registrarInteraccion();
}

// Consultar información del sistema
void SistemaUdeASay::consultar() {
    // Implementación básica - en un sistema real se mostrarían opciones de consulta
    std::cout << "Consultando información..." << std::endl;
    // Aquí iría la lógica de consulta
    monitor.registrarInteraccion();
}

// Actualizar el historial del sistema
void SistemaUdeASay::actualizarHistorico() {
    // Implementación básica - en un sistema real se actualizaría el historial
    std::cout << "Actualizando historial..." << std::endl;
    // Aquí iría la lógica de actualización
    monitor.registrarInteraccion();
}