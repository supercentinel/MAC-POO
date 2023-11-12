//{{_user_}} a374377@proton.me 2019-01-01
#ifndef PERSONA_HPP
#define PERSONA_HPP

#include "Direccion.hpp"
#include <iostream>

class Persona {
protected:
    int id;
    std::string nombre;
    std::string apellido;
    int edad;
    Direccion direccion;
    std::string telefono;
    std::string email;
public:
    // Constructor
    Persona();
    Persona(std::string nombre,
            std::string apellido,
            int edad,
            Direccion direccion,
            std::string telefono,
            std::string email);
    /* Persona(int id); */
    // Getters
    int getId();
    std::string getNombre();
    std::string getApellido();
    int getEdad();
    Direccion getDireccion();
    std::string getTelefono();
    std::string getEmail();
    // Setters
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setEdad(int edad);
    void setDireccion(Direccion direccion);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    // Methods
    //I/O
    friend std::ostream& operator << (std::ostream &out, const Persona &persona);
    friend std::istream& operator >> (std::istream &is, Persona &persona);
    //SQL
    /* int createTable(); */
    /* int create(); */
    /* int read(int id); */
    /* int update(); */
    /* int delet(); */
};

#endif // PERSONA_HPP
