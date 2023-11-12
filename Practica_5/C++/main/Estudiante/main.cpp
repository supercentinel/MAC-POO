#include <iostream>
#include <iterator>

#include "Direccion.hpp"
#include "Persona.hpp"

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


        return 0;
}

