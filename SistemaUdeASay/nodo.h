#ifndef NODO_H
#define NODO_H

// Clase Nodo genérica para implementar la estructura Lista
template <typename T>
class Nodo {
private:
    T dato;                // Dato almacenado en el nodo
    Nodo<T>* siguiente;    // Puntero al siguiente nodo

public:
    // Constructor
    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    
    // Getters y setters
    T getDato() const { return dato; }
    void setDato(const T& valor) { dato = valor; }
    
    Nodo<T>* getSiguiente() const { return siguiente; }
    void setSiguiente(Nodo<T>* nodo) { siguiente = nodo; }
};

#endif // NODO_H