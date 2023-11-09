#include <iostream>
#include <ostream>

#include "Direccion.hpp"

int main() {
        //Clase Direccion
        //Constructor por defecto
        Direccion d1, d3;
        //Setters
        d1.setCalle("Calle 1");
        d1.setNumero(1);
        d1.setColonia("Colonia 1");
        d1.setMunicipio("Municipio 1");
        d1.setEstado("Estado 1");
        d1.setPais("Pais 1");
        d1.setCodigoPostal(1);
        //Getters
        std::cout << "Calle: " << d1.getCalle() << std::endl;
        std::cout << "Numero: " << d1.getNumero() << std::endl;
        std::cout << "Colonia: " << d1.getColonia() << std::endl;
        std::cout << "Municipio: " << d1.getMunicipio() << std::endl;
        std::cout << "Estado: " << d1.getEstado() << std::endl;
        std::cout << "Pais: " << d1.getPais() << std::endl;
        std::cout << "Codigo Postal: " << d1.getCodigoPostal() << std::endl << std::endl;

        //Constructor con parametros
        Direccion d2("Calle 2",
                        2,
                        "Colonia 2",
                        "Municipio 2",
                        "Estado 2",
                        "Pais 2",
                        2);
        //Methods
        d2.print();
        std::cout << std::endl;
        //SQL
        d3.createTable();

        d1.create();
        d2.create();

        d3.read(1);
        d3.print();

        return 0;
}

