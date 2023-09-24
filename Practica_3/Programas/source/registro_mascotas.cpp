#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "mascota.hpp"
#include "registro_mascotas.hpp"

// Constructor
RegistroMascotas::RegistroMascotas(std::string filename) {
        this->readFromFile(filename);
}

// Methods
void RegistroMascotas::addMascota(Mascota mascota) {
        this->mascotas.push_back(mascota);
}

void RegistroMascotas::removeMascota(int id) {
        int i=0;

        for(i=0; i<this->mascotas.size(); i++) {
                if(this->mascotas[i].getId() == id) {
                        this->mascotas.erase(this->mascotas.begin() + i);
                        return;
                }
        }

        std::cout << "Mascota no encontrada" << std::endl;
}

void RegistroMascotas::updateMascota(int id, Mascota mascota) {
        int i=0;

        for(i=0; i<this->mascotas.size(); i++) {
                if(this->mascotas[i].getId() == id) {
                        this->mascotas[i] = mascota;
                        return;
                }
        }

        std::cout << "Mascota no encontrada" << std::endl;
}

void RegistroMascotas::findMascota(int id) {
        int i=0;

        for(i=0; i<this->mascotas.size(); i++) {
                if(this->mascotas[i].getId() == id) {
                        mascotas[i].print();
                        return;
                }
        }

        std::cout << "Mascota no encontrada" << std::endl;
}

// Overloaded method to find by name
void RegistroMascotas::findMascota(std::string nombre) {
        int i=0;

        for(i=0; i<this->mascotas.size(); i++) {
                if(this->mascotas[i].getNombre() == nombre) {
                        mascotas[i].print();
                        return;
                }
        }

        std::cout << "Mascota no encontrada" << std::endl;
}

void RegistroMascotas::readFromFile(std::string filename) {
        std::ifstream inputFile(filename);
        std::string line;

        // Check if file is open
        if(!inputFile.is_open()) {
                std::cout << "Error al abrir el archivo" << std::endl;
                return;
        }

        // Read file line by line
        while(getline(inputFile, line)) {
                std::stringstream ss(line);
                std::string token;
                std::vector<std::string> tokens;

                // Split line by commas
                while(std::getline(ss, token, ',')) {
                        tokens.push_back(token);
                }

                // Create a new Mascota object
                Mascota dummy = Mascota(
                        std::stoi(tokens[0]),
                        tokens[1],
                        tokens[2],
                        tokens[3],
                        std::stoi(tokens[4]),
                        static_cast<Talla>(std::stoi(tokens[5])),
                        tokens[6][0]
                );

                //adding dummy to the vector
                this->mascotas.push_back(dummy);
        }

}

void RegistroMascotas::writeToFile(std::string filename) {
        int i = 0;
        std::ofstream outputFile(filename);

        if(!outputFile.is_open()) {
                std::cout << "Error al abrir el archivo" << std::endl;
                return;
        }


        for(i=0; i<this->mascotas.size(); i++) {
                outputFile << this->mascotas[i].getId() << ",";
                outputFile << this->mascotas[i].getNombre() << ",";
                outputFile << this->mascotas[i].getRaza() << ",";
                outputFile << this->mascotas[i].getNombrePropietario() << ",";
                outputFile << this->mascotas[i].getPeso() << ",";
                outputFile << this->mascotas[i].getTalla() << ",";
                outputFile << this->mascotas[i].getSexo() << std::endl;
        }
}
