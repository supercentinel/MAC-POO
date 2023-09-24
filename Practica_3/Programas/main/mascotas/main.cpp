#include <iostream>

#include "mascota.hpp"
#include "registro_mascotas.hpp"


int main(void) {

    int option = 0;
    char add = 'n';
    int id = 0;
    std::string nombre = "";

    RegistroMascotas registro("mascotas.csv");
    Mascota dummy = Mascota(0, "", "", "", 0, Pequeña, 'M');

    while (option != 6) {
        std::cout << "Registro de mascotas" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "1. Agregar mascota" << std::endl;
        std::cout << "2. Eliminar mascota" << std::endl;
        std::cout << "3. Actualizar mascota" << std::endl;
        std::cout << "4. Buscar mascota por ID" << std::endl;
        std::cout << "5. Buscar mascota por nombre" << std::endl;
        std::cout << "6. Salir" << std::endl;

        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Agregar mascota" << std::endl;
                std::cout << "================" << std::endl;
                dummy.readFromConsole();
                std::cout << "================" << std::endl;
                dummy.print();
                std::cout << "Desea agregar esta mascota? (y/N)" << std::endl;
                std::cin >> add;
                if (add == 'y') {
                    registro.addMascota(dummy);
                    registro.writeToFile("mascotas.csv");
                }
            break;
            case 2:
                std::cout << "Eliminar mascota" << std::endl;
                std::cout << "================" << std::endl;
                std::cout << "Ingrese el ID de la mascota a eliminar" << std::endl;
                std::cin >> id;
                registro.removeMascota(id);
                registro.writeToFile("mascotas.csv");
            break;
            case 3:
                std::cout << "Actualizar mascota" << std::endl;
                std::cout << "==================" << std::endl;
                std::cout << "Ingrese el ID de la mascota a actualizar" << std::endl;
                std::cin >> id;
                registro.findMascota(id);
                std::cout << "================" << std::endl;
                dummy.readFromConsole();
                dummy.setId(id);
                std::cout << "================" << std::endl;
                dummy.print();
                std::cout << "Desea actualizar esta mascota? (y/N)" << std::endl;
                std::cin >> add;
                if (add == 'y') {
                    registro.updateMascota(id, dummy);
                    registro.writeToFile("mascotas.csv");
                }
            break;
            case 4:
                std::cout << "Buscar mascota por ID" << std::endl;
                std::cout << "====================" << std::endl;
                std::cout << "Ingrese el ID de la mascota a buscar" << std::endl;
                std::cin >> id;
                registro.findMascota(id);
            break;
            case 5:
                std::cout << "Buscar mascota por nombre" << std::endl;
                std::cout << "=========================" << std::endl;
                std::cout << "Ingrese el nombre de la mascota a buscar" << std::endl;
                std::cin >> nombre;
                registro.findMascota(nombre);
            break;
        }
    }
}
