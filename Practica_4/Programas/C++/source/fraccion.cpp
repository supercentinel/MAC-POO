#include <iostream>

#include "fraccion.hpp"

//Constructors
Fraccion::Fraccion() {
    this->a = 0;
    this->b = 1;
}

Fraccion::Fraccion(int a, int b) {
    this->a = a;
    this->b = b;
}

//Getters
int Fraccion::getA()  {
    return this->a;
}
int Fraccion::getB()  {
    return this->b;
}

//Setters
void Fraccion::setA(int a) {
    this->a = a;
}

void Fraccion::setB(int b) {
    this->b = b;
}

//Methods
std::string Fraccion::toLatex() {
    std::string result = "\\frac{" + std::to_string(this->a) + "}{" + std::to_string(this->b) + "}";
    return result;
}
// Oprerator overloading
// +
Fraccion Fraccion::operator + (const Fraccion &otro) {
    int a = this->a * otro.b + otro.a * this->b;
    int b = this->b * otro.b;

    Fraccion result(a, b);

    return result;
}

Fraccion Fraccion::operator + (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this + itof;
}

Fraccion Fraccion::operator += (const Fraccion &otro) {
    *this = *this + otro;

    return *this;
}

Fraccion Fraccion::operator += (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    *this = *this + itof;

    return *this;
}

Fraccion Fraccion::operator ++ () {
    *this += 1;

    return *this;
}

Fraccion Fraccion::operator - (const Fraccion &otro) {
    int a = this->a * otro.b - otro.a * this->b;
    int b = this->b * otro.b;

    Fraccion result(a, b);

    return result;
}

Fraccion Fraccion::operator - (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this - itof;
}

Fraccion Fraccion::operator -= (const Fraccion &otro) {
    *this = *this - otro;

    return *this;
}

Fraccion Fraccion::operator -= (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    *this = *this - itof;

    return *this;
}

Fraccion Fraccion::operator -- () {
    *this -= 1;

    return *this;
}
