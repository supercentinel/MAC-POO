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

    registro.removeMascota(43534);
    registro.findMascota(43534);

    return 0;
}
