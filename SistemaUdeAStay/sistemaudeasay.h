#ifndef SISTEMAUDEASAY_H
#define SISTEMAUDEASAY_H

#include "lista.h"
#include "alojamiento.h"
#include "huesped.h"
#include "reservacion.h"
#include "monitorsistema.h"

class SistemaUdeASay {
private:
    Lista<Alojamiento*> alojamientos;    // Lista de alojamientos disponibles
    Lista<Huesped*> huespedes;           // Lista de huéspedes registrados
    Lista<Reservacion*> reservaciones;   // Lista de reservaciones realizadas
    MonitorSistema monitor;              // Monitor del sistema

public:
    // Constructor y destructor
    SistemaUdeASay();
    ~SistemaUdeASay();
    
    // Métodos de autenticación
    bool login();
    
    // Métodos para gestionar alojamientos
    void registrarAlojamiento();
    void cancelarReserva();
    
    // Métodos para cargar y guardar datos
    void cargarDatos();
    void guardarDatos();
    
    // Métodos de consulta
    void consultar();
    
    // Método para actualizar el historial
    void actualizarHistorico();
    
    // Getters para acceder a las listas
    Lista<Alojamiento*>& getAlojamientos() { return alojamientos; }
    Lista<Huesped*>& getHuespedes() { return huespedes; }
    Lista<Reservacion*>& getReservaciones() { return reservaciones; }
    MonitorSistema& getMonitor() { return monitor; }
};

#endif // SISTEMAUDEASAY_H