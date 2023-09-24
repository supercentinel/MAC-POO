#ifndef REGISTRO_MASCOTAS_HPP
#define REGISTRO_MASCOTAS_HPP

#include <iostream>
#include <vector>

#include "mascota.hpp"

class RegistroMascotas {
    private:
        std::vector<Mascota> mascotas;
    public:
        // Constructor
        RegistroMascotas(std::string filename);
        // Methods
        void addMascota(Mascota mascota);
        void removeMascota(int id);
        void updateMascota(int id, Mascota mascota);
        void findMascota(int id);
        void findMascota(std::string nombre);
        void readFromFile(std::string filename);
        void writeToFile(std::string filename);

};

#endif
