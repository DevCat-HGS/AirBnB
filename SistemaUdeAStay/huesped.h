#ifndef HUESPED_H
#define HUESPED_H

#include <string>
#include "lista.h"
#include "reservacion.h"

// Declaración adelantada para evitar dependencias circulares
class Reservacion;

class Huesped {
private:
    std::string documento;        // Documento de identidad del huésped
    std::string nombre;           // Nombre completo del huésped
    int antiguedadMeses;          // Antigüedad en meses como usuario
    float puntuacion;             // Puntuación del huésped (de 0 a 5)
    Lista<Reservacion*> reservacionesActivas; // Lista de reservaciones activas

public:
    // Constructor
    Huesped(const std::string& documento, const std::string& nombre, 
            int antiguedadMeses = 0, float puntuacion = 5.0);
    
    // Destructor
    ~Huesped();
    
    // Getters y setters
    std::string getDocumento() const { return documento; }
    void setDocumento(const std::string& documento) { this->documento = documento; }
    
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    
    int getAntiguedadMeses() const { return antiguedadMeses; }
    void setAntiguedadMeses(int antiguedadMeses) { this->antiguedadMeses = antiguedadMeses; }
    
    float getPuntuacion() const { return puntuacion; }
    void setPuntuacion(float puntuacion) { this->puntuacion = puntuacion; }
    
    // Métodos para gestionar reservaciones
    void agregarReservacion(Reservacion* reservacion);
    void eliminarReservacion(Reservacion* reservacion);
    Lista<Reservacion*>& getReservacionesActivas() { return reservacionesActivas; }
    int contarReservaciones() const;
};

#endif // HUESPED_H