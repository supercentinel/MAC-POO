#include "Materia.hpp"

#include <iostream>
#include <istream>
#include <ostream>
#include <sys/types.h>

// Contructors
Materia::Materia() {
    this->id = 0;
    this->nombre = "";
    this->clave = "";
    this->profesor = "";
    this->horario = "";
    this->salon = "";
    this->creditos = 0;
    this->calificacion = 0;
}

Materia::Materia(std::string nombre,
        std::string clave,
        std::string profesor,
        std::string horario,
        std::string salon,
        int creditos,
        int calificacion) {
    this->id = 0;
    this->nombre = nombre;
    this->clave = clave;
    this->profesor = profesor;
    this->horario = horario;
    this->salon = salon;
    this->creditos = creditos;
    this->calificacion = calificacion;
}

// Setters
void Materia::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Materia::setClave(std::string clave) {
    this->clave = clave;
}

void Materia::setProfesor(std::string profesor) {
    this->profesor = profesor;
}

void Materia::setHorario(std::string horario) {
    this->horario = horario;
}

void Materia::setSalon(std::string salon) {
    this->salon = salon;
}

void Materia::setCreditos(int creditos) {
    this->creditos = creditos;
}

void Materia::setCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

// Getters
int Materia::getId() {
    return this->id;
}

std::string Materia::getNombre() {
    return this->nombre;
}

std::string Materia::getClave() {
    return this->clave;
}

std::string Materia::getProfesor() {
    return this->profesor;
}

std::string Materia::getHorario() {
    return this->horario;
}

std::string Materia::getSalon() {
    return this->salon;
}

int Materia::getCreditos() {
    return this->creditos;
}

int Materia::getCalificacion() {
    return this->calificacion;
}

// Methods
std::ostream& operator << (std::ostream &os, const Materia &materia) {
    os << "Id: " << materia.id << std::endl;
    os << "Nombre: " << materia.nombre << std::endl;
    os << "Clave: " << materia.clave << std::endl;
    os << "Profesor: " << materia.profesor << std::endl;
    os << "Horario: " << materia.horario << std::endl;
    os << "Salon: " << materia.salon << std::endl;
    os << "Creditos: " << materia.creditos << std::endl;
    os << "Calificacion: " << materia.calificacion << std::endl;
    return os;
}

std::istream& operator >> (std::istream &in, Materia &materia) {
    std::cout << "Nombre: ";
    in >> materia.nombre;
    std::cout << "Clave: ";
    in >> materia.clave;
    std::cout << "Profesor: ";
    in >> materia.profesor;
    std::cout << "Horario: ";
    in >> materia.horario;
    std::cout << "Salon: ";
    in >> materia.salon;
    std::cout << "Creditos: ";
    in >> materia.creditos;
    std::cout << "Calificacion: ";
    in >> materia.calificacion;
    return in;
}
