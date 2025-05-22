#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>
#include "lista.h"
#include "alojamiento.h"

// Declaración adelantada para evitar dependencias circulares
class Alojamiento;

class Anfitrion {
private:
    std::string documento;        // Documento de identidad del anfitrión
    int antiguedad;               // Antigüedad en años como anfitrión
    float puntuacion;             // Puntuación del anfitrión (de 0 a 5)
    Lista<Alojamiento*> alojamientos; // Lista de alojamientos que administra

public:
    // Constructor
    Anfitrion(const std::string& documento, int antiguedad = 0, float puntuacion = 5.0);
    
    // Destructor
    ~Anfitrion();
    
    // Getters y setters
    std::string getDocumento() const { return documento; }
    void setDocumento(const std::string& documento) { this->documento = documento; }
    
    int getAntiguedad() const { return antiguedad; }
    void setAntiguedad(int antiguedad) { this->antiguedad = antiguedad; }
    
    float getPuntuacion() const { return puntuacion; }
    void setPuntuacion(float puntuacion) { this->puntuacion = puntuacion; }
    
    // Métodos para gestionar alojamientos
    void agregarAlojamiento(Alojamiento* alojamiento);
    void eliminarAlojamiento(Alojamiento* alojamiento);
    Lista<Alojamiento*>& getAlojamientos() { return alojamientos; }
    int contarAlojamientos() const;
};

#endif // ANFITRION_H