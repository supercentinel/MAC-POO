#include <iostream>
#include <ostream>
#include <vector>

#include "Estudiante.hpp"
#include "Materia.hpp"

// Contructors
Estudiante::Estudiante() {
    this->numeroDeCuenta = 0;
    this->carrera = "";
    this->semestre = 0;
}

Estudiante::Estudiante(std::string nombre,
        std::string apellido,
        int edad,
        Direccion direccion,
        std::string telefono,
        std::string email,
        int numeroDeCuenta,
        std::string carrera,
        int semestre,
        std::vector<std::string> grupos,
        std::vector<Materia> materias) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->direccion = direccion;
    this->telefono = telefono;
    this->email = email;
    this->numeroDeCuenta = numeroDeCuenta;
    this->carrera = carrera;
    this->semestre = semestre;
    this->grupos = grupos;
    this->materias = materias;
}

// Getters
int Estudiante::getNumeroDeCuenta() {
    return this->numeroDeCuenta;
}

std::string Estudiante::getCarrera() {
    return this->carrera;
}

int Estudiante::getSemestre() {
    return this->semestre;
}

std::vector<std::string> Estudiante::getGrupos() {
    return this->grupos;
}

std::vector<Materia> Estudiante::getMaterias() {
    return this->materias;
}

// Setters
void Estudiante::setNumeroDeCuenta(int numeroDeCuenta) {
    this->numeroDeCuenta = numeroDeCuenta;
}

void Estudiante::setCarrera(std::string carrera) {
    this->carrera = carrera;
}

void Estudiante::setSemestre(int semestre) {
    this->semestre = semestre;
}

void Estudiante::setGrupos(std::vector<std::string> grupos) {
    this->grupos = grupos;
}

void Estudiante::setMaterias(std::vector<Materia> materias) {
    this->materias = materias;
}

// Methods
std::ostream& operator << (std::ostream & os, const Estudiante &estudiante) {
    os << "Nombre: " << estudiante.nombre << std::endl;
    os << "Apellido: " << estudiante.apellido << std::endl;
    os << "Edad: " << estudiante.edad << std::endl;
    os << "Direccion: " << estudiante.direccion << std::endl;
    os << "Telefono: " << estudiante.telefono << std::endl;
    os << "Email: " << estudiante.email << std::endl;
    os << "Numero de cuenta: " << estudiante.numeroDeCuenta << std::endl;
    os << "Carrera: " << estudiante.carrera << std::endl;
    os << "Semestre: " << estudiante.semestre << std::endl;
    os << "Grupos: " << std::endl;
    for (int i = 0; i < estudiante.grupos.size(); i++) {
        os << "\t" << estudiante.grupos[i] << std::endl;
    }
    os << "Materias: " << std::endl;
    for (int i = 0; i < estudiante.materias.size(); i++) {
        os << "\t" << estudiante.materias[i] << std::endl;
    }

    return os;
}
