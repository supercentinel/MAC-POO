#include <iostream>

#include "complejo.hpp"

int main(void) {

    //Constructores
    Complejo z1;
    Complejo z2(1.0, -2.0);
    Complejo z3(-3.0, 4.0, true);

    //Getters
    std::cout << "z2" << std::endl;
    std::cout << "a: " << z2.getA() << std::endl;
    std::cout << "b: " << z2.getB() << std::endl;
    std::cout << "theta: " << z2.getTheta() << std::endl;
    std::cout << "r: " << z2.getR() << std::endl;
    //Setters
    z1.setA(1.0);
    z1.setB(-2.0);
    z1.setTheta(-2.0);
    z1.setR(2.0);

    //Metodos
    z2.printPolar();
    z2.printCartesian();
    z2.printExponential();

    std::cout << "|z2| = " << z2.magnitude() << std::endl;

    Complejo z4 = z2.conjugate();

    std::cout << "arg(z2) = " << z2.arg() << std::endl;

    std::cout << z2.toTeX('p') << std::endl;
    std::cout << z2.toTeX('e') << std::endl;

    //Operadores
    // I/O
    std::cout << "z4\n" << z4;
    std::cout << (z2 + z3);
    z2 += z3;
    std::cout << (z2 - z3);
    z2 -= z3;
    std::cout << (z2 * z3);
    z2 *= z3;
    z2 = Complejo(4.0, 3.0);
    z3 = Complejo(2.0, 1.0);
    std::cout << (z2 / z3);
    std::cout << (z2 ^ 5);

    std::cout << (z2 == z3) << std::endl;
    std::cout << (z2 != z3) << std::endl;

    std::cin >> z1;

    return 0;
}
