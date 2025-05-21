#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include "lista.h"
#include "reservacion.h"
#include "anfitrion.h"

// Declaraciones adelantadas para evitar dependencias circulares
class Reservacion;
class Anfitrion;

class Alojamiento {
private:
    std::string codigo;              // Código único del alojamiento
    std::string nombre;              // Nombre del alojamiento
    std::string tipo;                // Tipo de alojamiento (casa, apartamento, etc.)
    std::string departamento;        // Departamento donde se ubica
    std::string municipio;           // Municipio donde se ubica
    std::string direccion;           // Dirección exacta
    float precioNoche;               // Precio por noche
    Lista<std::string> amenidades;   // Lista de amenidades disponibles
    Anfitrion* anfitrion;            // Puntero al anfitrión que administra el alojamiento
    Lista<Reservacion*> fechasReservadas; // Lista de reservaciones para este alojamiento

public:
    // Constructor
    Alojamiento(const std::string& codigo, const std::string& nombre, const std::string& tipo,
                const std::string& departamento, const std::string& municipio, 
                const std::string& direccion, float precioNoche, Anfitrion* anfitrion);
    
    // Destructor
    ~Alojamiento();
    
    // Getters y setters
    std::string getCodigo() const { return codigo; }
    void setCodigo(const std::string& codigo) { this->codigo = codigo; }
    
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    
    std::string getTipo() const { return tipo; }
    void setTipo(const std::string& tipo) { this->tipo = tipo; }
    
    std::string getDepartamento() const { return departamento; }
    void setDepartamento(const std::string& departamento) { this->departamento = departamento; }
    
    std::string getMunicipio() const { return municipio; }
    void setMunicipio(const std::string& municipio) { this->municipio = municipio; }
    
    std::string getDireccion() const { return direccion; }
    void setDireccion(const std::string& direccion) { this->direccion = direccion; }
    
    float getPrecioNoche() const { return precioNoche; }
    void setPrecioNoche(float precioNoche) { this->precioNoche = precioNoche; }
    
    Anfitrion* getAnfitrion() const { return anfitrion; }
    void setAnfitrion(Anfitrion* anfitrion) { this->anfitrion = anfitrion; }
    
    // Métodos para gestionar amenidades
    void agregarAmenidad(const std::string& amenidad);
    void eliminarAmenidad(const std::string& amenidad);
    Lista<std::string>& getAmenidades() { return amenidades; }
    
    // Métodos específicos
    void mostrarInfo() const;                                      // Muestra información del alojamiento
    bool verificarDisponibilidad(const std::string& inicio, const std::string& fin) const; // Verifica disponibilidad
    void agregarReservacion(Reservacion* reservacion);            // Agrega una reservación
    void quitarReservacion(Reservacion* reservacion);             // Elimina una reservación
};

#endif // ALOJAMIENTO_H