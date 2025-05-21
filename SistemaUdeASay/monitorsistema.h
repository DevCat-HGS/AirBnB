#ifndef MONITORSISTEMA_H
#define MONITORSISTEMA_H

#include <cstddef> // Para size_t

class MonitorSistema {
private:
    size_t memoriaTotal;         // Memoria total utilizada por el sistema
    int interaccionesTotales;    // Contador de interacciones con el sistema

public:
    // Constructor
    MonitorSistema() : memoriaTotal(0), interaccionesTotales(0) {}
    
    // Métodos para monitoreo
    void sumarMemoria(size_t bytes);
    void registrarInteraccion();
    size_t obtenerMemoria() const { return memoriaTotal; }
    int obtenerInteracciones() const { return interaccionesTotales; }
    void reporte() const; // Genera un reporte del estado del sistema
};

#endif // MONITORSISTEMA_H