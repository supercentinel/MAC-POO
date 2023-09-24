#ifndef MASCOTA_HPP
#define MASCOTA_HPP

#include <iostream>
#include <string>

enum Talla {
    Pequeña = 1,
    Mediana,
    Grande
};

class Mascota {
    protected:
        int id;
        std::string nombre;
        std::string raza;
        std::string nombre_propietario;
        int peso;
        Talla talla;
        char sexo;
    public:
        // Constructor
        Mascota(int id,
                std::string nombre,
                std::string raza,
                std::string nombre_propietario,
                int peso,
                Talla talla,
                char sexo);
        // Getters
        int getId();
        std::string getNombre();
        std::string getRaza();
        std::string getNombrePropietario();
        int getPeso();
        Talla getTalla();
        char getSexo();
        // Setters
        void setId(int id);
        void setNombre(std::string nombre);
        void setRaza(std::string raza);
        void setNombrePropietario(std::string nombre_propietario);
        void setPeso(int peso);
        void setTalla(Talla talla);
        void setSexo(char sexo);
        // Methods
        void print();
        void readFromConsole();
};

#endif
