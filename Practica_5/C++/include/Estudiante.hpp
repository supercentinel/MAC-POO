//{{_user_}} a374377@proton.me 2019-01-01
#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <iostream>
#include <istream>
#include <vector>
#include "Direccion.hpp"
#include "Persona.hpp"
#include "Materia.hpp"

class Estudiante : public Persona {
private:
    int numeroDeCuenta;
    std::string carrera;
    int semestre;
    std::vector<std::string> grupos;
    std::vector<Materia> materias;
public:
    // Contructors
    Estudiante();
    Estudiante(std::string nombre,
            std::string apellido,
            int edad,
            Direccion direccion,
            std::string telefono,
            std::string email,
            int numeroDeCuenta,
            std::string carrera,
            int semestre,
            std::vector<std::string> grupos,
            std::vector<Materia> materias);
    // Getters
    int getNumeroDeCuenta();
    std::string getCarrera();
    int getSemestre();
    std::vector<std::string> getGrupos();
    std::vector<Materia> getMaterias();
    // Setters
    void setNumeroDeCuenta(int numeroDeCuenta);
    void setCarrera(std::string carrera);
    void setSemestre(int semestre);
    void setGrupos(std::vector<std::string> grupos);
    void setMaterias(std::vector<Materia> materias);
    // Methods
    friend std::ostream& operator << (std::ostream &os, const Estudiante &estudiante);
    friend std::istream& operator >> (std::ostream &in, Estudiante &estudiante);
};

#endif // ESTUDIANTE_HPP
