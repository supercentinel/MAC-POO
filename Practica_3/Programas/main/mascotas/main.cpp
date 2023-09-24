#include <iostream>

#include "mascota.hpp"
#include "registro_mascotas.hpp"


int main(void) {

    RegistroMascotas registro = RegistroMascotas("mascotas.csv");


    Mascota a = Mascota(
                12312,
                "Firulais",
                "Doverman",
                "Alberto",
                50,
                Grande,
                'M'
            );

    registro.readFromFile("mascotas.csv");

    return 0;
}
