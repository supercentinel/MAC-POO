#include <iostream>
#include <vector>

#include "Direccion.hpp"
#include "Materia.hpp"
#include "Persona.hpp"
#include "Estudiante.hpp"

int main() {
        //Class Direccion
        //Contructors
        Direccion d1, d2;
        Direccion d3("Calle 3",
                77,
                "Colonia 3",
                "Municipio 3",
                "Estado 2",
                "Pais 2",
                77777);
        //Setters
        d1.setCalle("Calle 1");
        d1.setNumero(11);
        d1.setColonia("Colonia 1");
        d1.setMunicipio("Municipio 1");
        d1.setEstado("Estado 1");
        d1.setPais("Pais 1");
        d1.setCodigoPostal(11111);
        //Getters
        std::cout << "d1.getId(): " << d1.getId() << std::endl;
        std::cout << "d1.getCalle(): " << d1.getCalle() << std::endl;
        std::cout << "d1.getNumero(): " << d1.getNumero() << std::endl;
        std::cout << "d1.getColonia(): " << d1.getColonia() << std::endl;
        std::cout << "d1.getMunicipio(): " << d1.getMunicipio() << std::endl;
        std::cout << "d1.getEstado(): " << d1.getEstado() << std::endl;
        std::cout << "d1.getPais(): " << d1.getPais() << std::endl;
        std::cout << "d1.getCodigoPostal(): " << d1.getCodigoPostal() << std::endl;
        //I/O
        std::cout << "d3: " << d3 << std::endl;
        /* std::cin >> d2; */

        //Class Persona
        //Contructors
        Persona p1, p2;
        Persona p3("Nombre 3",
                "Apellido 3",
                33,
                d3,
                "7777777777",
                "asdasd@assf.com");
        // Setters
        p1.setNombre("Nombre 1");
        p1.setApellido("Apellido 1");
        p1.setEdad(11);
        p1.setDireccion(d1);
        p1.setTelefono("121414124");
        p1.setEmail("asdfasd@assad.com");
        // Getters
        std::cout << p1.getId() << std::endl;
        std::cout << p1.getNombre() << std::endl;
        std::cout << p1.getApellido() << std::endl;
        std::cout << p1.getEdad() << std::endl;
        std::cout << p1.getDireccion() << std::endl;
        std::cout << p1.getTelefono() << std::endl;
        std::cout << p1.getEmail() << std::endl;
        // I/O
        std::cout << p3 << std::endl;
        /* std::cin >> p2; */

        //Materia Class
        //Contructors
        Materia m1, m2;
        Materia m3("Materia 3",
                "A3",
                "Profesor 3",
                "Lunes: 7:00-9:00",
                "Salon 3",
                15,
                7);
        // Setters
        m1.setNombre("Materia 1");
        m1.setClave("A1");
        m1.setProfesor("Profesor 1");
        m1.setHorario("Lunes: 7:00-9:00");
        m1.setSalon("Salon 1");
        m1.setCreditos(10);
        m1.setCalificacion(8);
        // Getters
        std::cout << m1.getId() << std::endl;
        std::cout << m1.getNombre() << std::endl;
        std::cout << m1.getClave() << std::endl;
        std::cout << m1.getProfesor() << std::endl;
        std::cout << m1.getHorario() << std::endl;
        std::cout << m1.getSalon() << std::endl;
        std::cout << m1.getCreditos() << std::endl;
        std::cout << m1.getCalificacion() << std::endl;
        // I/O
        std::cout << m3 << std::endl;
        /* std::cin >> m2; */

        //Class Estudiante
        //Vectors for Estudiante
        std::vector<Materia> materias;
        materias.push_back(m1);
        materias.push_back(m2);
        materias.push_back(m3);

        std::vector<std::string> grupos;
        grupos.push_back("Grupo 1");
        grupos.push_back("Grupo 2");
        grupos.push_back("Grupo 3");

        //Contructors
        Estudiante e1, e2;
        Estudiante e3("Nombre 3",
                "Apellido 3",
                17,
                d3,
                "121421414",
                "asdas@sd.com",
                77777777,
                "Carrera 3",
                3,
                grupos,
                materias);
        // Setters
        e1.setNombre("Nombre 1");
        e1.setApellido("Apellido 1");
        e1.setEdad(11);
        e1.setDireccion(d1);
        e1.setTelefono("121414124");
        e1.setEmail("asd@asd.com");
        e1.setNumeroDeCuenta(1111111111);
        e1.setCarrera("Carrera 1");
        e1.setSemestre(1);
        e1.setGrupos(grupos);
        e1.setMaterias(materias);
        // Getters
        std::cout << e1.getId() << std::endl;
        std::cout << e1.getNombre() << std::endl;
        std::cout << e1.getApellido() << std::endl;
        std::cout << e1.getEdad() << std::endl;
        std::cout << e1.getDireccion() << std::endl;
        std::cout << e1.getTelefono() << std::endl;
        std::cout << e1.getEmail() << std::endl;
        std::cout << e1.getNumeroDeCuenta() << std::endl;
        std::cout << e1.getCarrera() << std::endl;
        std::cout << e1.getSemestre() << std::endl;
        for(int i = 0; i < e1.getGrupos().size(); i++) {
                std::cout << e1.getGrupos()[i] << std::endl;
        }
        for(int i = 0; i < e1.getMaterias().size(); i++) {
                std::cout << e1.getMaterias()[i] << std::endl;
        }
        // I/O
        std::cout << e3 << std::endl;

        return 0;
}

