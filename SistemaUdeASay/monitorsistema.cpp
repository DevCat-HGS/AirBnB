#include "monitorsistema.h"
#include <iostream>

// Sumar bytes a la memoria total utilizada
void MonitorSistema::sumarMemoria(size_t bytes) {
    memoriaTotal += bytes;
}

// Registrar una nueva interacción con el sistema
void MonitorSistema::registrarInteraccion() {
    interaccionesTotales++;
}

// Generar un reporte del estado del sistema
void MonitorSistema::reporte() const {
    std::cout << "===== REPORTE DEL SISTEMA =====" << std::endl;
    std::cout << "Memoria total utilizada: " << memoriaTotal << " bytes" << std::endl;
    std::cout << "Interacciones totales: " << interaccionesTotales << std::endl;
    std::cout << "==============================" << std::endl;
}