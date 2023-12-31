#include <iostream>

#include "mascota.hpp"
#include "raylib.h"

// Constructor
Mascota::Mascota( int id,
                  std::string nombre,
                  std::string raza,
                  std::string nombre_propietario,
                  int peso,
                  Talla talla,
                  char sexo) {
        this->id = id;
        this->nombre = nombre;
        this->raza = raza;
        this->nombre_propietario = nombre_propietario;
        this->peso = peso;
        this->talla = talla;
        this->sexo = sexo;
}

// Getters
int Mascota::getId() {
        return this->id;
}

std::string Mascota::getNombre() {
        return this->nombre;
}

std::string Mascota::getRaza() {
        return this->raza;
}

std::string Mascota::getNombrePropietario() {
        return this->nombre_propietario;
}

int Mascota::getPeso() {
        return this->peso;
}

Talla Mascota::getTalla() {
        return this->talla;
}

char Mascota::getSexo() {
        return this->sexo;
}
// Setters
void Mascota::setId(int id) {
        this->id = id;
}

void Mascota::setNombre(std::string nombre) {
        this->nombre = nombre;
}

void Mascota::setRaza(std::string raza) {
        this->raza = raza;
}

void Mascota::setNombrePropietario(std::string nombre_propietario) {
        this->nombre_propietario = nombre_propietario;
}

void Mascota::setPeso(int peso) {
        this->peso = peso;
}

void Mascota::setTalla(Talla talla) {
        this->talla = talla;
}

void Mascota::setSexo(char sexo) {
        this->sexo = sexo;
}
// Methods
void Mascota::print() {
        std::cout << "ID: " << this->id << std::endl;
        std::cout << "Nombre: " << this->nombre << std::endl;
        std::cout << "Raza: " << this->raza << std::endl;
        std::cout << "Nombre del propietario: " << this->nombre_propietario << std::endl;
        std::cout << "Peso: " << this->peso << std::endl;
        std::cout << "Talla: " << this->talla << std::endl;
        std::cout << "Sexo: " << this->sexo << std::endl;
}

void Mascota::readFromConsole() {
        int talla;

        std::cout << "ID: ";
        std::cin >> this->id;
        std::cout << "Nombre: ";
        std::cin >> this->nombre;
        std::cout << "Raza: ";
        std::cin >> this->raza;
        std::cout << "Nombre del propietario: ";
        std::cin >> this->nombre_propietario;
        std::cout << "Peso: ";
        std::cin >> this->peso;
        std::cout << "Talla: [1] Pequeña, [2] Mediana, [3] Grande: ";
        std::cin >> talla;
        switch (talla) {
                case 1:
                        this->talla = Pequeña;
                        break;
                case 2:
                        this->talla = Mediana;
                        break;
                case 3:
                        this->talla = Grande;
                        break;
                default:
                        this->talla = Pequeña;
                        break;
        }
        std::cout << "Sexo: ";
        std::cin >> this->sexo;
}
