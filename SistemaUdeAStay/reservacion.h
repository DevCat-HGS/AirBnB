#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>
#include "alojamiento.h"
#include "huesped.h"

// Declaraciones adelantadas para evitar dependencias circulares
class Alojamiento;
class Huesped;

class Reservacion {
private:
    std::string codigo;          // Código único de la reservación
    std::string fechaInicio;     // Fecha de inicio de la reservación
    int duracion;                // Duración en días
    std::string docHuesped;      // Documento del huésped
    std::string metodoPago;      // Método de pago utilizado
    std::string fechaPago;       // Fecha en que se realizó el pago
    float monto;                 // Monto total de la reservación
    char observaciones[1000];    // Observaciones adicionales
    Alojamiento* alojamiento;    // Puntero al alojamiento reservado
    Huesped* huesped;            // Puntero al huésped que realiza la reservación

public:
    // Constructor
    Reservacion(const std::string& codigo, const std::string& fechaInicio, int duracion,
                const std::string& docHuesped, const std::string& metodoPago,
                const std::string& fechaPago, float monto, const char* observaciones,
                Alojamiento* alojamiento, Huesped* huesped);
    
    // Getters y setters
    std::string getCodigo() const { return codigo; }
    void setCodigo(const std::string& codigo) { this->codigo = codigo; }
    
    std::string getFechaInicio() const { return fechaInicio; }
    void setFechaInicio(const std::string& fechaInicio) { this->fechaInicio = fechaInicio; }
    
    int getDuracion() const { return duracion; }
    void setDuracion(int duracion) { this->duracion = duracion; }
    
    std::string getDocHuesped() const { return docHuesped; }
    void setDocHuesped(const std::string& docHuesped) { this->docHuesped = docHuesped; }
    
    std::string getMetodoPago() const { return metodoPago; }
    void setMetodoPago(const std::string& metodoPago) { this->metodoPago = metodoPago; }
    
    std::string getFechaPago() const { return fechaPago; }
    void setFechaPago(const std::string& fechaPago) { this->fechaPago = fechaPago; }
    
    float getMonto() const { return monto; }
    void setMonto(float monto) { this->monto = monto; }
    
    const char* getObservaciones() const { return observaciones; }
    void setObservaciones(const char* observaciones);
    
    Alojamiento* getAlojamiento() const { return alojamiento; }
    void setAlojamiento(Alojamiento* alojamiento) { this->alojamiento = alojamiento; }
    
    Huesped* getHuesped() const { return huesped; }
    void setHuesped(Huesped* huesped) { this->huesped = huesped; }
    
    // Métodos específicos
    bool validarTraslapes() const;        // Verifica si hay traslapes con otras reservaciones
    std::string formatearFecha() const;   // Formatea la fecha para mostrarla
    void imprimirComprobante() const;     // Imprime un comprobante de la reservación
};

#endif // RESERVACION_H