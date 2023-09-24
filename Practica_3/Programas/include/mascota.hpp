#ifndef MASCOTA_HPP
#define MASCOTA_HPP

#include <iostream>
#include <string>

class Mascota {
    protected:
        int id;
        std::string nombre;
        std::string raza;
        std::string nombre_propietario;
        int peso;
        int talla;
        char sexo;
    public:
        // Constructor
        Mascota(int id,
                std::string nombre,
                std::string raza,
                std::string nombre_propietario,
                int peso,
                int talla,
                char sexo);
        // Getters
        int getId();
        std::string getNombre();
        std::string getRaza();
        std::string getNombrePropietario();
        int getPeso();
        int getTalla();
        char getSexo();
        // Setters
        void setId(int id);
        void setNombre(std::string nombre);
        void setRaza(std::string raza);
        void setNombrePropietario(std::string nombre_propietario);
        void setPeso(int peso);
        void setTalla(int talla);
        void setSexo(char sexo);
        // Methods
        void print();
};

#endif
