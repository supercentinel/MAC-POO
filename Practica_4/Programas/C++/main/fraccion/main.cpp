#include <iostream>

#include "fraccion.hpp"

int main(void) {
    //Creacion de un objeto de la clase Fraccion
    //Constructor por defecto
    Fraccion f1;
    //Constructor parametrizado
    Fraccion f2(16, 16);
    //Constructor de copia
    Fraccion f3(f2);

    //Getters
    std::cout << "a" << f1.getA() << std::endl;
    std::cout << "b" << f1.getB() << std::endl;

    //Setters
    f1.setA(-3);
    f1.setB(-4);

    //Métodos
    //A TeX
    std::cout << f1.toLatex() << std::endl;
    //Normalizacion
    f1.normalize();
    std::cout << f1.toLatex() << std::endl;
    //Reduccion
    std::cout << "f2" << f2.toLatex() << std::endl;
    f2.reduce();
    std::cout << "f2 reducido" << f2.toLatex() << std::endl;

    //Casteo a otros tipos de datos
    std::cout << "f1" << f1.toDouble() << std::endl;
    std::cout << "f1" << f1.toFloat() << std::endl;
    std::cout << "f2" << f2.toInt() << std::endl;

    //Sobrecarga de operadores
    // I/O
    std::cout << "f1" << f1 << std::endl;
    std::cin >> f1;

    //Operadores aritmeticos
    // adicion
    std::cout << (f1 + f2) << std::endl;
    std::cout << (f1 += f2) << std::endl;
    std::cout << (f1 += 2) << std::endl;
    std::cout << (f1++) << std::endl;
    // sustraccion
    std::cout << (f1 - f2) << std::endl;
    std::cout << (f1 -= f2) << std::endl;
    std::cout << (f1 -= 2) << std::endl;
    std::cout << (f1--) << std::endl;
    // multiplicacion
    std::cout << (f1 * f2) << std::endl;
    std::cout << (f1 *= f2) << std::endl;
    std::cout << (f1 *= 2) << std::endl;
    // division
    std::cout << (f1 / f2) << std::endl;
    std::cout << (f1 /= f2) << std::endl;
    std::cout << (f1 /= 2) << std::endl;
    // relaciones de orden
    std::cout << (f1 == f2) << std::endl;
    std::cout << (f1 == 2) << std::endl;
    std::cout << (f1 != f2) << std::endl;
    std::cout << (f1 != 1) << std::endl;
    std::cout << (f1 < f2) << std::endl;
    std::cout << (f1 < 1) << std::endl;
    std::cout << (f1 <= f2) << std::endl;
    std::cout << (f1 <= 1) << std::endl;
    std::cout << (f1 > f2) << std::endl;
    std::cout << (f1 > 1) << std::endl;
    std::cout << (f1 >= f2) << std::endl;
    std::cout << (f1 >= 1) << std::endl;

    return 0;
}
