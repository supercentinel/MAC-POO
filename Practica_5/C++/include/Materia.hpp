//{{_user_}} a374377@proton.me 2019-01-01
#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <iostream>

class Materia {
private:
    std::string nombre;
    std::string clave;
    std::string profesor;
    std::string horario;
    std::string salon;
    int creditos;
    int calificacion;
public:
    //Contructors
    Materia();
    Materia(std::string nombre,
            std::string clave,
            std::string profesor,
            std::string horario,
            std::string salon,
            int creditos,
            int calificacion);
    // Setters
    void setNombre(std::string nombre);
    void setClave(std::string clave);
    void setProfesor(std::string profesor);
    void setHorario(std::string horario);
    void setSalon(std::string salon);
    void setCreditos(int creditos);
    void setCalificacion(int calificacion);
    // Getters
    std::string getNombre();
    std::string getClave();
    std::string getProfesor();
    std::string getHorario();
    std::string getSalon();
    int getCreditos();
    int getCalificacion();
    // Methods
    friend std::ostream& operator << (std::ostream &os, const Materia &materia);
    friend std::istream& operator >> (std::ostream &in, Materia &materia);
};

#endif // MATERIA_HPP
